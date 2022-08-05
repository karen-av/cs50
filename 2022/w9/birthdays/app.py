from curses.ascii import isdigit
import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)


# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        id = request.form.get("id")
        nameEdit = request.form.get("nameEdit")
        monthEdit = request.form.get("monthEdit")
        dayEdit = request.form.get("dayEdit")
        idEdit = request.form.get("idEdit")
        edit=db.execute("SELECT * FROM birthdays WHERE id = ?", idEdit)


        if name or month or day:
            if name:
                if int(len(name)) > 10:
                    return redirect("/")
            if month:
                if month.isnumeric():
                    if int(month) > 12 or int(month) < 1:
                        return redirect("/")
                else:
                    return redirect("/")
            if day:
                if day.isdigit():
                    if int(day) > 31 or int(day) < 1:
                        return redirect("/")
                else:
                    return redirect("/")

            if not name or not day or not month:
                return redirect("/")
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

        elif nameEdit or monthEdit or dayEdit:
            if nameEdit:
                if int(len(nameEdit)) > 10:
                    return render_template("edit.html", edit=edit)
                db.execute("UPDATE birthdays SET name=? WHERE id = ?", nameEdit, idEdit)

            if monthEdit:
                if monthEdit.isnumeric():
                    if int(monthEdit) > 12 or int(monthEdit) < 1:
                        return render_template("edit.html", edit=edit)
                    db.execute("UPDATE birthdays SET month=? WHERE id = ?", monthEdit, idEdit)
                else:
                    return render_template("edit.html", edit=edit)

            if dayEdit:
                if dayEdit.isdigit():
                    if int(dayEdit) > 31 or int(dayEdit) < 1:
                        return render_template("edit.html", edit=edit)
                    db.execute("UPDATE birthdays SET day=? WHERE id = ?", dayEdit, idEdit)
                else:
                    return render_template("edit.html", edit=edit)

        elif id:
            db.execute("DELETE FROM birthdays WHERE id = ?", id)

        return redirect("/")

    else:
        names=db.execute("SELECT * FROM birthdays")
        return render_template("index.html", names=names)

@app.route("/edit", methods=["POST"])
def edit():
    edit = request.form.get("edit")
    edit = db.execute("SELECT * FROM birthdays WHERE id = ?", edit)
    return render_template("edit.html", edit=edit)
