
import serial


ser = serial.Serial("COM4", 9600) #Replace"Com4" with the current serial port of the Arduino Board
while True:
    #dimmer_value is a percentage value from 0-100% of the total ac power
    dimmer_value = input('Enter dimmer value: ')
    ser.write(dimmer_value.encode())