import csv
import re

counter = 0
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        # if title == "OFFICE":
        # if "OFFICE" in title:
        # if re.search("OFFICE", title):
        if re.search("^(OFFICE|THE.OFFICE)$", title):
            counter += 1
print(f"Numbers of people who like the The Office: {counter}")