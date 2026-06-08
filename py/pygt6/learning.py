from PyQt6.QtWidgets import QApplication, QWidget, QSlider, QPushButton, QLabel, QLineEdit
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont
from PyQt6.QtWidgets import QFrame

app = QApplication([])   # 1. start application

window = QWidget()       # 2. create window
window.setWindowTitle("My First Window")  # give it a title
window.resize(400, 400)   # width, height
window.setStyleSheet("background-color: #101b2b;") # window color

font = QFont()
font.setBold(True)


########button###########
button = QPushButton("Add", window) #button
button.move(160, 180) # move the button
button.setStyleSheet("""
    QPushButton {
        background-color: #a500f7;
        color: #101b2b;
        border: 1px solid #a500f7;
        border-radius: 10px;
        padding: 10px;
    }
""")
button.setFont(font)

def button_click():
    print("button clicked")

button.clicked.connect(button_click)

##########slider##########
slider = QSlider(Qt.Orientation.Horizontal, window)
slider.setGeometry(50, 100, 300, 30) # x, y, width, height
slider.setMinimum(0)
slider.setMaximum(20)

def slider_change(value):
    print("slider value: ", value)

slider.valueChanged.connect(slider_change)

#########label############
label = QLabel("Value: .....", window)
label.move(50, 60)
label.setStyleSheet("""
    color: #101b2b;
    background-color: #a500f7;
    border: 1px solid #a500f7;
    border-radius: 10px;
    padding: 5px;
""")
label.setFont(font)

#######label with slider#######
def slider_label(x):
    label.setText(f"value: {x}") # f: this string can contain variables inside it / replace {value} with the actual value of the variable

slider.valueChanged.connect(slider_label)

#############Input Box################
input_box = QLineEdit(window)
input_box.setPlaceholderText("Type something here...")
input_box.setGeometry(50, 300, 300, 30)

def button_text():
    text = input_box.text()
    print(text)

button.clicked.connect(button_text)

########frame##############

line = QFrame(window)
#Horizontal
line.setGeometry(0, 20, 400, 3) #x, y, width, height
line.setStyleSheet("background-color: #7300ff;")
#Vertical
#line.setGeometry(20, 0, 3, 300)
#line.setStyleSheet("background-color: #7300ff;")



window.show()            # 3. display window

app.exec()               # keep program running