from flask import Flask, redirect, render_template, request

app = Flask(__name__)

# Создаем словарь для хранения регистрантов
REGISTRANTS = {}

SPORTS = { 
    "Tennis",
    "Basketball",
    "Soccer"
}

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():

    # Validate name
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")

    # Validate sport 
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")
    
    # Remember registrant
    REGISTRANTS[name] = sport

    # Confirm registration
    return redirect("/registrans")

@app.route("/registrants")
def registrants():
    return render_template("/registrans.html", registrants=REGISTRANTS)

