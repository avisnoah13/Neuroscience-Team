import serial

def start_outlet(port):     #initializes the outlet object with a specified port name
    return serial.Serial(port, 9600)

#sets the power of the AC Dimmer on the outlets from 0-100% and turns the Solid State Relay on or of
#Outlet is the defined outlet object, dimmer_power is a value from 0-100, and ssr_state is 0 for off and 1 for on
def set_outlet(Outlet, dimmer_power, ssr_state):    
    string_packet = ""
    dimmer_str = str(dimmer_power)
    ssr_str = str(ssr_state)
    
    if len(dimmer_str) <= 3:
        string_packet = f"{dimmer_power:03}"
    else: print("Invalid dimer power value")

    if len(ssr_str) == 1:
        string_packet += ssr_str
    else: print("Invalid ssr_state")

    Outlet.write(string_packet.encode())
    print("Sent "+ string_packet)




