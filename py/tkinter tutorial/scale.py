from tkinter import *
window=Tk()

scale = Scale(window,from_=0,to=100)
scale.config(bg='light blue')
scale.config(fg='white')
scale.config(length=400)
scale.config(orient=HORIZONTAL)
scale.config(tickinterval=5)#add intervale
scale.config(showvalue=0)# 1 to show the value
scale.config(resolution=5)
scale.config(troughcolor='pink')
scale.pack()

window.mainloop()
