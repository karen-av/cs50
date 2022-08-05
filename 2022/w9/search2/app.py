
# Searches for shows using Ajax with JSON

from cs50 import SQL 
from flask import Flask, render_template, request, jsonify

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///movies.db")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM movies WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return jsonify(shows)
    



