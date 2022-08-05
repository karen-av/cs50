from cs50 import get_int

def main():

    i = get_positive_int()
    print(i)

def get_positive_int():

    while True:
        i = get_int("Ger positive int: ")
        if i > 0:
            break
    return i

main()