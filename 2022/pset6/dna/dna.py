import csv
import sys


# Название программы + csv + txt
# python3 dna.py databases/large.csv sequences/1.txt
# python3 dna.py databases/small.csv sequences/1.txt

def main():

    # Инициализируем базу данных list
    dataBase = []
    # Переменная
    sequence = ""
    # Список конкретных последовательностей
    subSequenceAll = []

    # TODO: Check for command-line usage
    # Проверяем количество аргументов командной строки
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit()

    # Названия последовательностей. Включая name
    with open(sys.argv[1], "r") as file:
        read = csv.reader(file)
        for row in read:
            for i in row:
                subSequenceAll.append(i)
            break

    # TODO: Read database file into a variable
    # База данных. Так же vеняем значения на int
    with open(sys.argv[1], "r") as file:
        readCSV = csv.DictReader(file)
        for row in readCSV:
            k = list(row)
            for i in range(1, len(k)):
                row[k[i]] = int(row[k[i]])
            dataBase.append(row)

    # TODO: Read DNA sequence file into a variable
    # Записываем последовательности
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Считаем наибольшее количество подпоследовательностей в общей последовательности
    x = {}
    for i in range(1, len(subSequenceAll)):
        subsequence = subSequenceAll[i]
        x[subSequenceAll[i]] = longest_match(sequence, subsequence)

    # TODO: Check database for matching profiles
    # найти соответсвие в базе данных. Сравникть датабас с х и выводим имя или отсутсвие имени
    for n in dataBase:
        dict = n.pop("name")
        if n == x:
            print(dict)
            break
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    """Возвращает длину самого длинного отрезка подпоследовательности в последовательности"""

    # Initialize variables
    longest_run = 0
    # Длина значения
    subsequence_length = len(subsequence)
    # Доина всей цепочки
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
