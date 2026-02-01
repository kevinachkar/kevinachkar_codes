import pygame
import time

pygame.init()
pygame.joystick.init()

print("Joystick count:", pygame.joystick.get_count())

# Use joystick 0 directly
joystick = pygame.joystick.Joystick(0)
joystick.init()

print("Using joystick:", joystick.get_name())
print("Axes:", joystick.get_numaxes())

while True:
    pygame.event.pump()  # VERY IMPORTANT

    axes = []
    for i in range(joystick.get_numaxes()):
        axes.append(round(joystick.get_axis(i), 3))

    print(axes)
    time.sleep(0.05)
