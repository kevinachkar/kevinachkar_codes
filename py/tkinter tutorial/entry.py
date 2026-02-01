from tkinter import *
window = Tk()

def submit():
   username = entry.get()
   print(username)

def delete():
      entry.delete(0,END)

window.title("gboyek")
window.geometry("600x400")
window.config(bg="light grey")

entry = Entry(window)
entry.config(font=('Display',20))
entry.config(bg='light blue')
entry.config(fg='white')
entry.config(width=10)

button = Button(window,text='click')
button.config(command=submit)

button2 = Button(window,text='delete')
button2.config(command=delete)

entry.pack()
button.pack()
button2.pack()

window.mainloop()