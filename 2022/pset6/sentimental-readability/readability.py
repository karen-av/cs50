from itertools import count
from cs50 import get_string


def main():

    text = get_string("Type the text: ")

    # Количество букв
    letters = 0
    for char in text:
        if char.isalnum():
            letters += 1

    # Расчитать количество слов.
    # split разделяет на str строки. len считает строки
    words = len(text.split())

    # Расчитать количество предложений
    sentence = 0
    characters = ["!", "?", "."]
    for char in text:
        if char in characters:
            sentence += 1

    # букв на 100 слов l
    l = letters / words * 100

    # предложений на 100 слов s
    s = sentence / words * 100

    x = round(0.0588 * l - 0.296 * s - 15.8)

    if x > 16:
        print("Grade 16+")
    elif x < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {x}")


if __name__ == "__main__":
    main()
