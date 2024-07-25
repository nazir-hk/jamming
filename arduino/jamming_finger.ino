const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
boolean newData = false;

int toggleP = 0; //positive-pressure toggle
int toggleN = 0; //negative-pressure toggle

void  setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT); //positive-presssure singal pin
  digitalWrite(8, LOW);

  pinMode(7, OUTPUT); //negative-presssure signal pin
  digitalWrite(8, LOW);
  
}

void  loop() {
  recvWithEndMarker();
  showNewNumber();
  
  if (toggleP==0){
    digitalWrite(8, LOW);
  }
  
  if (toggleP==1){
    digitalWrite(8, HIGH);
  }

  if (toggleN==0){
    digitalWrite(7, LOW);
  }

  if (toggleN==1){
    digitalWrite(7, HIGH);
  }

}

void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  
  if (Serial.available() > 0) {
    rc = Serial.read();

    if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
            ndx = numChars - 1;
        }
    }
    else {
        receivedChars[ndx] = '\0'; // terminate the string
        ndx = 0;
        newData = true;
    }
  }
}

void showNewNumber() {
  if (newData == true) {
    if (receivedChars[0] == 'P')
    {
      toggleP = 0;             // new for this version
      char receivedChars_s[sizeof(receivedChars) - 1];
      strcpy(receivedChars_s, receivedChars + 1);
      toggleP = atoi(receivedChars_s);   // new for this version
      newData = false;
    }
    if (receivedChars[0] == 'N')
    {
      toggleN = 0;             // new for this version
      char receivedChars_dc[sizeof(receivedChars) - 1];
      strcpy(receivedChars_dc, receivedChars + 1);
      toggleN = atoi(receivedChars_dc);   // new for this version
      newData = false;
    }
  }
}