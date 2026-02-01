import random

tries = 1

number = random.randint(1, 100)

x = int(input("Try to guess the number(0-100): "))

while x != number:
    delta = number - x

    if delta > 0 :
        print("TOO LOW ")

    elif delta < 0:
        print("TOO HIGH")

    x = int(input("Try again: "))
    tries +=1

print("you guessed it right! ")   
print(f"you guesses it in {tries} tries") 
    
          
