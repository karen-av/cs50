from cs50 import get_int

i = 1
while True:
    print(i)
    i *= 2
    if i > 1000000000:
        break

scores = [72, 73, 33]
scoresGet = []

for i in range(3):
    scoresGet.append(get_int("Score: "))

average = sum(scoresGet) / len(scoresGet)
print(f"Average: {average}")
print(f"Average: {(sum(scores) / len(scores))}")
print("Average: " + str(sum(scores) / len(scores)))