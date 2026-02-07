from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)

CORS(
    app,
    resources={r'api/*': {"origins": "http:localhost:5173"}}
)

@app.route("/")
def home():
    return "flask runs bro"

@app.route("/api/data")
def get_data():
    return jsonify(
        wetOriginalDepth=500,
        wetCurrentDepth=345,
        dryOriginalDepth=5000,
        dryCurrentDepth=851
    )

app.run(debug=True)