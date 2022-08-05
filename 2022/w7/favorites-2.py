import csv

title = input("Get title: ").upper().strip()
counter = 0

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # if row["title"].upper().strip() == title:
        if title in row["title"].upper().strip():
            counter += 1
print(counter)