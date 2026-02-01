from tkinter import *
window = Tk()
window.geometry('600x400')

x = IntVar()

def display():
    print(x.get())

checkbox = Checkbutton(window,text='button')
checkbox.config(font=('Display',10,'bold'))
checkbox.config(variable=x)
checkbox.config(onvalue=1,offvalue=0,command=display)



checkbox.pack()

window.mainloop()