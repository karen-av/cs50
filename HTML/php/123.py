from cs50 import get_string

print("hello,world")

answer = get_string("What's your name? ")
print("hello, "+ answer)
print(f"hello, {answer}")
print(f"{answer} hello")

counter = 0
print(f"{counter} hello")
counter += 1
print(f"{counter} hello")