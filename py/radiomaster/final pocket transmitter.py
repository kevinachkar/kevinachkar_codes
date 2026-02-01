import pygame
import serial
import time

# ---------- SERIAL ----------
ser = serial.Serial('COM4', 9600, timeout=1)
time.sleep(2)  # wait for Nano reset

# ---------- PYGAME ----------
pygame.init()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)  # Joystick 0
joystick.init()

print("Using joystick:", joystick.get_name())

def axis_to_arduino(val):
    # Convert -1.0 .. 1.0  →  0 .. 1023
    return int((val + 1.0) * 511.5)

# ---------- MAIN LOOP ----------
while True:
    pygame.event.pump()

    joy1x = axis_to_arduino(joystick.get_axis(0))
    joy1y = axis_to_arduino(joystick.get_axis(1))
    joy2x = axis_to_arduino(joystick.get_axis(2))
    joy2y = axis_to_arduino(joystick.get_axis(3))

    data = f"{joy1x},{joy1y},{joy2x},{joy2y}\n"
    ser.write(data.encode())

    # Debug print (VS Code terminal only)
    print(data.strip())

    time.sleep(0.02)  # 50 Hz
