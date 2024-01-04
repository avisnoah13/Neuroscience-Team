# Neuroscience-Team
Code base for the EEG/ EKG project team of Catholic High School

-------------------------------------------------------------------
USING SMART OUTLETS

Look at the provided example for code implementation

1. Plug in Arduino to computer
2. Upload the .ino sketch and take note of the port name
3. Ensure that smart_outlet is in the same directory as your python file
4. Import the smart_outlet module
6. To create the outlet object, use that port name in start_outlet() as shown in the example
7. Use set_outlet whenever chaning the state of either the dimmer or switch. Pass your outlet object as the first argument, an integer from 0-100 for the dimmer power in the second argument, and the last argument is 0 for turning thr switch off and 1 for turning it on.
8. Run the python program

Progress:
I am working on adding code for the physical on/off siwtch I included in the enclosure.

Repository Author: Noah Avis
