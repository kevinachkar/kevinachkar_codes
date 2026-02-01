import cv2
import mediapipe as mp

mp_face_detection = mp.solutions.face_detection
mp_draw = mp.solutions.drawing_utils

cap = cv2.VideoCapture(0)

MAX_VAL = 1000

with mp_face_detection.FaceDetection(model_selection=1, min_detection_confidence=0.5) as face_detection:
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # ✅ Flip the frame horizontally
        frame = cv2.flip(frame, 1)

        height, width, _ = frame.shape
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = face_detection.process(rgb)

        if results.detections:
            for detection in results.detections:
                bbox = detection.location_data.relative_bounding_box
                x = int(bbox.xmin * width)
                y = int(bbox.ymin * height)
                w = int(bbox.width * width)
                h = int(bbox.height * height)

                # Draw bounding box
                cv2.rectangle(frame, (x, y), (x + w, y + h), (0,255,0), 2)

                # Find center of face
                cx = x + w // 2
                cy = y + h // 2

                # Convert center to 0–1000 scale
                scaled_x = int((cx / width) * MAX_VAL)
                scaled_y = int((cy / height) * MAX_VAL)

                cv2.putText(frame, f"X:{scaled_x} Y:{scaled_y}", (x, y - 10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 0, 0), 2)

                print(f"Face Center → X: {scaled_x}, Y: {scaled_y}")

        cv2.imshow("Face Tracking - MediaPipe", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
