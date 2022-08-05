import csv
from cs50 import SQL

# ищем в базе данных название

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

# возвращает список словарей
rows = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title)

# Вытаскиваем первый словарь
row = rows[0]

print(row["counter"])