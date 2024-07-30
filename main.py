import driver
import time

import msvcrt


def inflate(duration=None):
    driver.sendCommand("P1")
    if duration is not None:
        time.sleep(duration)
        driver.sendCommand("P0")

def deflate(duration=None):
    driver.sendCommand("N1")
    if duration is not None:
        time.sleep(duration)
        driver.sendCommand("N0")

if __name__ == '__main__':

    driver.setupSerial(115200, 'COM3')
    time.sleep(2)

    while True:
        print("0: InflateShort\n1: InflateLong\n2: Deflate")

        cmd = msvcrt.getch()

        if cmd.upper() == b"0":
            inflate(duration=0.5)

        elif cmd.upper() == b"1":
            inflate(duration=2.0)

        elif cmd.upper() == b"2":
            deflate(duration=None)        

        elif cmd == b'\x00':  # Arrow key prefix
            arrow_key = msvcrt.getch()
            if arrow_key == b'H':
                inflate(duration=0.1)

            elif arrow_key == b'P':
                deflate(duration=0.1)
                
            else:
                print("Invalid command")  

        else:
            print("Invalid command")    

        time.sleep(0.1)

