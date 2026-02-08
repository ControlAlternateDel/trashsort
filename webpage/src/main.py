from flask import Flask, jsonify
import serial
import time

app = Flask(__name__)

# Open serial ONCE
ser = serial.Serial('/dev/cu.usbmodem11101', 19200, timeout=0.1)
time.sleep(2)  # Arduino reset

dryDist = None
wetDist = None


@app.route("/")
def home():
    return "flask runs bro"


@app.route("/api/data")
def get_data():
    global dryDist, wetDist

    # Read all available serial lines (non-blocking)
    while ser.in_waiting > 0:
        line = ser.readline().decode("utf-8", errors="ignore").strip()

        if line.startswith("Dry:"):
            dryDist = float(line.replace("Dry:", "").strip())
        elif line.startswith("Wet:"):
            wetDist = float(line.replace("Wet:", "").strip())

    return jsonify(
        dryCurrentDepth=dryDist,
        wetCurrentDepth=wetDist
    )

app.run(debug=True)



# Replace 'COM3' with your Arduino's port (e.g., 'COM4', '/dev/ttyUSB0', '/dev/ttyACM0')


# Wait for the connection to initialize


