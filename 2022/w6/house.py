# работаем с открытием файла и расчетом данных в нем

import csv

# Таблица данных. ключ - значение

houses = {
    "Hog": 0,
    "Nort": 0,
    "Nir": 0
}

# Open file to read
with open("houses.csv", "r") as file:
    # передаем переменной функцию
    reader = csv.reader(file)
    # Пропускаем первую строчку в таблице
    next(reader)
    # Читаем данные в таблице построчно
    for row in reader:
        # Присваеваем переменной значение ном 1 в прочитанной строке
        house = row[1]
        # В словаре согласно ключю прибавляем единицу
        houses[house] += 1

# Печатаем словарь
for i in houses:
    print(f"{i}: {houses[i]}")
