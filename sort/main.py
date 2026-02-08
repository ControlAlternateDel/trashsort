from tensorflow.keras.models import load_model  
import cv2  
import numpy as np
import serial, time

np.set_printoptions(suppress=True)
arduino = serial.Serial('/dev/cu.usbmodem11101', 9600, timeout=1)
time.sleep(2)

model = load_model("keras_Model.h5", compile=False)

class_names = open("labels.txt", "r").readlines()

camera = cv2.VideoCapture(0)

last_state = None

while True:
    ret, image = camera.read()

    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)

    cv2.imshow("Webcam Image", image)

    image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)

    image = (image / 127.5) - 1

    arduino.write(b"TEST\n")

    prediction = model.predict(image)
    index = np.argmax(prediction)
    class_name = class_names[index]
    confidence_score = prediction[0][index]
    print(confidence_score)
    if confidence_score > 0.8:
        if "Class" in class_name:
            print("meow meow meow")
            arduino.write(b"e")
            time.sleep(2)
            arduino.flush()
        if "wet" in class_name:
            print("meow meow meow meow")
            arduino.write(b"w")
            time.sleep(2)
            arduino.flush()
            last_state = "wet"
            time.sleep(0.5)
        elif "dry" in class_name:
            arduino.write(b"d")
            time.sleep(2)
            arduino.flush()
            last_state = "dry"
            time.sleep(0.5)
        else:
            arduino.write(b"d.write(90)\n")
            time.sleep(0.5)
            
        
        print(class_name)
    print("Class:", class_name[2:], end="")
    print("Confidence Score:", str(np.round(confidence_score * 100))[:-2], "%")

    keyboard_input = cv2.waitKey(1)

    if keyboard_input == 27:
        break

camera.release()
cv2.destroyAllWindows()
