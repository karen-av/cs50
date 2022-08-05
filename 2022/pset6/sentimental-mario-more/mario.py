from re import L
import sys


def main():

    while True:
        heigth = input("Heigth: ")
        if heigth.isnumeric() and int(heigth) > 0 and int(heigth) != 9:
            heigth = int(heigth)
            break
    r = 1
    while True:
        for h in range(heigth - r):
            print(" ", end="")
        printing(r)
        print("  ", end="")
        printing(r)
        print()
        r += 1
        if r > heigth:
            break


def printing(t):
    for i in range(t):
        print("#", end="")


if __name__ == "__main__":
    main()