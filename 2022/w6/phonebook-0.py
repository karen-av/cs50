from cs50 import get_string

people = {
    "David": "+7-395-234-43-67",
    "Alex": "+7-324-984-33-21"
}

name = get_string("name: ")
if name in people:
    number = people[name]
    print(f"Number: {number}")
    print(f"Number: {people[name]}")
else:
    print("Not found")