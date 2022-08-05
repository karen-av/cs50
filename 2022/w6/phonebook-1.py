#записываем в файйл.  вариант 1

import csv
import cs50

file = open("phonebook.csv", "a")

name = cs50.get_string("name: ")
number = cs50.get_string("number: ")

writer = csv.writer(file)

writer.writerow([name, number])

file.close()