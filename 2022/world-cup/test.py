# Simulate a sports tournament

import csv

teams = []
t = {
    "Hello": "14",
    "asd": "24"
}

#print(t)
for i in t:
    t[i] = int(t[i])
#print(t)

with open("2018m.csv", "r") as file:
    read = csv.DictReader(file) #read like a dictionary
    for row in read:
        row["rating"] = int(row["rating"])
        teams.append(row)
print(teams)
