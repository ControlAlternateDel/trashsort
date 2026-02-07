from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)

CORS(
    app,
    resources={r'api/*': {"origins": "http:localhost:5173"}}
)

