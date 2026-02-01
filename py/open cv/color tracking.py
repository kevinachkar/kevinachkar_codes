import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    frame = cv2.flip(frame, 1)

    h, w, _ = frame.shape
    center_x, center_y = w // 2, h // 2

    # Convert frame to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Red color range (You can adjust if needed)
    lower_red1 = np.array([0, 120, 70])
    upper_red1 = np.array([10, 255, 255])
    lower_red2 = np.array([170, 120, 70])
    upper_red2 = np.array([180, 255, 255])

    mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
    mask = mask1 + mask2

    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)

    cnts, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if cnts:
        c = max(cnts, key=cv2.contourArea)
        ((x, y), radius) = cv2.minEnclosingCircle(c)

        if radius > 5:
            cv2.circle(frame, (int(x), int(y)), int(radius), (0, 0, 255), 2)

            # Normalize to range -100 to 100
            norm_x = int(((x - center_x) / center_x) * 100)
            norm_y = int(((center_y - y) / center_y) * 100)  # invert y so up is +
            
            cv2.putText(frame, f"X: {norm_x}   Y: {norm_y}",
                        (10, 30), cv2.FONT_HERSHEY_SIMPLEX,
                        0.8, (255, 255, 255), 2)

    # Draw reference center lines
    cv2.line(frame, (center_x, 0), (center_x, h), (200, 200, 200), 1)
    cv2.line(frame, (0, center_y), (w, center_y), (200, 200, 200), 1)

    cv2.imshow("Red Object Tracker", frame)

    if cv2.waitKey(1) & 0xFF == 27:  # ESC to exit
        break

cap.release()
cv2.destroyAllWindows()
