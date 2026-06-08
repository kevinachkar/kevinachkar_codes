import sys
from PyQt6.QtWidgets import (
    QApplication, QMainWindow, QWidget,
    QVBoxLayout, QHBoxLayout,
    QLabel, QSlider, QPushButton,
    QMenuBar, QStatusBar, QGroupBox, QFormLayout
)
from PyQt6.QtCore import Qt


class DroneControl(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Drone Ground Control Station")
        self.resize(700, 400)

        # ================= MENU BAR =================
        menu = self.menuBar()

        file_menu = menu.addMenu("File")
        file_menu.addAction("Exit", self.close)

        tools_menu = menu.addMenu("Tools")
        tools_menu.addAction("Connect (COM)", self.connect_serial)
        tools_menu.addAction("Disconnect", self.disconnect_serial)

        help_menu = menu.addMenu("Help")
        help_menu.addAction("About", self.show_about)

        # ================= CENTRAL WIDGET =================
        central = QWidget()
        self.setCentralWidget(central)

        main_layout = QHBoxLayout()

        # ===== LEFT PANEL (PID CONTROL) =====
        pid_box = QGroupBox("PID Tuning")
        pid_layout = QFormLayout()

        self.p_slider = self.create_slider(pid_layout, "P Gain")
        self.i_slider = self.create_slider(pid_layout, "I Gain")
        self.d_slider = self.create_slider(pid_layout, "D Gain")

        pid_box.setLayout(pid_layout)

        # ===== RIGHT PANEL (CONTROLS) =====
        control_box = QGroupBox("Controls")
        control_layout = QVBoxLayout()

        self.arm_btn = QPushButton("ARM")
        self.disarm_btn = QPushButton("DISARM")
        self.send_btn = QPushButton("SEND VALUES")

        self.arm_btn.clicked.connect(lambda: self.set_status("ARMED"))
        self.disarm_btn.clicked.connect(lambda: self.set_status("DISARMED"))
        self.send_btn.clicked.connect(self.send_values)

        control_layout.addWidget(self.arm_btn)
        control_layout.addWidget(self.disarm_btn)
        control_layout.addWidget(self.send_btn)

        control_box.setLayout(control_layout)

        # ================= ADD TO MAIN =================
        main_layout.addWidget(pid_box)
        main_layout.addWidget(control_box)

        central.setLayout(main_layout)

        # ================= STATUS BAR =================
        self.status = QStatusBar()
        self.setStatusBar(self.status)
        self.status.showMessage("System Ready")

    # ===== helper: slider builder =====
    def create_slider(self, layout, name):
        label = QLabel(f"{name}: 0")

        slider = QSlider(Qt.Orientation.Horizontal)
        slider.setRange(0, 100)

        slider.valueChanged.connect(
            lambda v, l=label, n=name: l.setText(f"{n}: {v}")
        )

        layout.addRow(label, slider)
        return slider

    # ===== actions =====
    def set_status(self, text):
        self.status.showMessage(text)
        print(text)

    def send_values(self):
        p = self.p_slider.value()
        i = self.i_slider.value()
        d = self.d_slider.value()

        msg = f"{p},{i},{d}"
        print("Sending PID:", msg)
        self.status.showMessage(f"Sent: {msg}")

    def connect_serial(self):
        self.status.showMessage("Connecting to COM port...")

    def disconnect_serial(self):
        self.status.showMessage("Disconnected")

    def show_about(self):
        self.status.showMessage("Drone Control UI v1.0")


# ================= RUN APP =================
app = QApplication(sys.argv)
window = DroneControl()
window.show()
sys.exit(app.exec())