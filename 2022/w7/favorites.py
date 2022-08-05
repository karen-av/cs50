import csv

# Структура данных "Множество". Хранит неповторяющиеся данные в неотсортированном виде
#titles = set()

titles = {}
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    #next(reader)
    for row in reader:
        # Сохраняем в переменную значение. убираем пробелы с двух сторон и переводим в верхний регистор
        title = row["title"].strip().upper()

        # Если ключа еще нет в словаре, то добавляем его и писваиваем значение 0
        if not title in titles:
            titles[title] = 0
        titles[title] += 1

# сортируем словарь по значению и в обратном порядке. выводим на печать
for title in sorted(titles, key=lambda title: titles[title], reverse=True):
    print(title, titles[title])