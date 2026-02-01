from tkinter import *

count = 0

def click():
    global count
    count += 1
    label.config(text=count)

window = Tk()
window.title("gboyek")
window.geometry("800x500")
window.config(background="purple")

label = Label(window,text=count)
label.config(font=("Arial",100,"bold"))

text = Label(window,text="gboyek")
text.config(bg="black")
text.config(fg="blue")
text.config(font=("Ink Free",50,"bold"))

button = Button(window,text="HELP")
button.config(command=click)

button.config(font=("Ariel",70,"bold"))
button.config(bg="orange")
button.config(state=ACTIVE) # ACTIVE OR DISABLED

button.pack()
text.place(x=0,y=0)
label.place(x=600,y=0)

window.mainloop()