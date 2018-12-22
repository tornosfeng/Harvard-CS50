from cs50 import get_int

n = 0
while True:
    n = get_int("Number: ")
    if n > 0:
        break

tmp = n
dig = 0
while tmp != 0:
    tmp = tmp // 10
    dig += 1

card_alg = 0

for i in range(1, dig + 1):
    digs = n // 10**(i - 1)
    digs = digs % 10

    if i % 2 == 0:
        card_alg += (digs * 2) // 10 + (digs * 2) % 10
    else:
        card_alg += digs

flag = 0

first_one = (int)(n // 10**(dig - 1))
first_two = (int)(n // 10**(dig - 2))
if card_alg % 10 == 0:
    if dig == 15 and (first_two == 34 or first_two == 37):
        print("AMEX")
        flag = 1
    elif dig == 16 and (first_two == 51 or first_two == 52 or first_two == 53 or first_two == 54 or first_two == 55):
        print("MASTERCARD")
        flag = 2
    elif ((dig == 16 or dig == 13) and (first_one == 4)):
        print("VISA")
        flag = 3
    else:
        print("INVALID")
        flag = 4
else:
    print("INVALID")
    flag = 5

print(flag)


