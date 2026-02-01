from tkinter import *
from tkinter import messagebox

window = Tk()

def click():
    messagebox.showinfo(title='error gboyek')

button = Button(window,command=click,text='click')

button.pack()

window.mainloop()