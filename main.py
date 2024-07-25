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
        inflate(duration=2)
        time.sleep(1)
        # deflate(duration=3)

