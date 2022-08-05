from cs50 import get_string

def main():

    s = get_string("Befor: ")
    print("After: " , end="")
    print(s.upper())

    print("After: ", end="")
    for c in s:
        print(c.upper(), end="")
    print()

main()