from cs50 import get_float


def main():

    while True:
        change = get_float("How manu cash? ")
        if change >= 0.01:
            break

    quarters = 0.25
    dimes = 0.10
    nickels = 0.05
    pennies = 0.01
    nomber = 0

    if change >= quarters:
        nomber += int(change / quarters)
        change = round(change % quarters, 2)
        #print(f"nom: {nomber} - ch: {change} - 1")

    if change >= dimes:
        nomber += calcNomber(change, dimes)
        change = calcChange(change, dimes)
       # print(f"nom: {nomber} - ch: {change} - 2")

    if change >= nickels:
        nomber += calcNomber(change, nickels)
        change = calcChange(change, nickels)
       # print(f"nom: {nomber} - ch: {change} - 3")

    if change >= pennies:
        nomber += calcNomber(change, pennies)
        change += calcChange(change, pennies)
       # print(f"nom: {nomber} - ch: {change} - 4")

    print(nomber)


def calcNomber(ch, n):
    nom = int(ch / n)
    return nom
    

def calcChange(ch, n):
    chang_c = round(ch % n, 2)
    return chang_c


if __name__ == "__main__":
    main()