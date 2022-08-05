#  Simulate a sports tournament

import csv
import sys
import random

#  Number of simluations to run
N = 1000


def main():

    #  Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")
    #  Заполняем список
    teams = []
    #  Открываем файл для чтения
    with open(sys.argv[1], "r") as file:
        # Определяем переменную
        read = csv.DictReader(file)
        # Читаем файл по строкам
        for row in read:
            # Меняем тип данных рейтинг на int
            row["rating"] = int(row["rating"])
            # Записываем в список прочитанную строку
            teams.append(row)
    # Заполняем словарь
    counts = {}
    # Открываем файл для чтения
    with open(sys.argv[1], "r") as file:
        # Определяем переменную
        read = csv.DictReader(file)
        # Читаем файл по строкам
        for row in read:
            # Записываем в словарь ключ (название команды) и значение 0
            counts[row["team"]] = 0
    # Заполняем значения в словаре по количеству побед из функции simulate_tournament
    for i in range(N):
        counts[simulate_tournament(teams)] += 1
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")
    print()


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []
    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


# Вычисляем победителя турнира
def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # Создаем переменную типа стринг
    champion = ""
    # Запусаем бесконечный цикл
    while True:
        # Рекурсивно запускаем функцию, которая возвращает в два раза меньше команд после каждого раунда
        teams = simulate_round(teams)
        # Когда остается одна команда. победитель
        if len(teams) == 1:
            # Запускаем for для прохода по строке списка
            for row in teams:
                # Выдергиваем название команды
                champion = row['team']
            # Выходим из while
            break
    # Возвращаем название команды
    return champion


if __name__ == "__main__":
    main()
