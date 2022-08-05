from flask import Flask, redirect, render_template, request
from cs50 import SQL

app = Flask(__name__)

# Подключаемся к базе данных для хранения регистрантов

db = SQL("sqlite:///froshims.db")

SPORTS = {
    "Tennis",
    "Basketball",
    "Soccer"
}

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():
    # Foget register
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id=?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():

    # Validate submition
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("error.html", message="Missing name")

    # Remember registration
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # Confirm regiatration
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)



