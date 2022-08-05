#from cs50 import get_int
import cs50

x = cs50.get_int("x: ")
y = cs50.get_int("y: ")

if x < y:
    print("x < y")
elif x > y:
    print("y > x")
else:
    print("x = y")

