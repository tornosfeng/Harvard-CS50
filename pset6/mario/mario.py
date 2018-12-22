from cs50 import get_int
while True:
    n = get_int("Height:")
    if n >= 0 and n <=23:
        break

if n > 0:
    for i in range(1,n + 1):
        a = " " * (n - i) + '#' * i + "  " + '#' * i
        print(a)




