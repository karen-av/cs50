#Работа с аргументами командной строки

from sys import argv

if len(argv) == 2:
    if len(argv[1]) == 2:
        print(f"Hello, {argv[1]}!")
    else:
        print("By!")
else:
    print("Hello, wordl!")


#print all arguments
for a in argv:
    print(a)