from cs50 import get_string

s = get_string("Do you agree? ")
#Переводим значение, введенное пользотателем, в нижнйи регистр и сравниваем
if s.lower() in ["y", "yes"]:
    print("Agree")
elif s.lower() == "n" or s.lower() == "no":
    print("No agree")
else:
    print("WTF")