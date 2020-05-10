from picamera.array import PiRGBArray
import RPi.GPIO as gpio
from picamera import PiCamera
import time
import cv2

RELAY = 17
gpio.setmode(gpio.BCM)
gpio.setup(RELAY, gpio.OUT, initial=gpio.LOW)
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(640, 480))

faceCascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
eyesCascade = cv2.CascadeClassifier("haarcascade_eye_tree_eyeglasses.xml")

init_detector = 0;
time.sleep(0.1)

for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    image = frame.array

    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    faces = faceCascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(50, 50))

    for (x, y, w, h) in faces:
        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
        roi_gray = gray[y:y + h, x:x + w]
        roi_color = image[y:y + h, x:x + w]
        eyes = eyesCascade.detectMultiScale(roi_gray)
        for (ex, ey, ew, eh) in eyes:
            print "眼睛坐标为"+eyes
            cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (100, 255, 255), 2)

        if len(faces) >= 1 and len(eyes) >= 2:
            # cv2.putText(image, 'WARNING!', (10, 500), cv2.FONT_HERSHEY_SIMPLEX, 4, (255, 255, 255), 2)
            gpio.output(RELAY, False)
            if init_detector != 0:
                init_detector == 0;
        else:
            gpio.output(RELAY, True)
            init_detector += 1;

    cv2.imshow("Frame", image)
    key = cv2.waitKey(1) & 0xFF
    rawCapture.truncate(0)

    if key == ord("q") ||init_detector == 320:
        print "疲劳驾驶"
        break
gpio.output(RELAY, False)
gpio.cleanup()

cv2.destroyAllWindows()
