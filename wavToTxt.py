from scipy.io.wavfile import read
import json

a = read('heartbeat.wav')       

arr = []

for int in a[1]:
    if (int < 380 and int > -380):
        arr.append(abs(int/4))          # Convert heartbeat amplitudes into valid percentages for arduino dimmer

with open('heartbeatarr.txt', 'w') as filehandle:
    json.dump(arr, filehandle)