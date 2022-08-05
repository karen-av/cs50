#записываем в файйл.  вариант 2  более питонически

import csv
import cs50

with open("phonebook.csv", "a") as file:

    name = cs50.get_string("name: ")
    number = cs50.get_string("number: ")

    writer = csv.writer(file)

    writer.writerow([name, number])
