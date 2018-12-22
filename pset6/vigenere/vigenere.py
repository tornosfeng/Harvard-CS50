import sys
from cs50 import get_string
if len(sys.argv) != 2:
    print("Usage: ./vigenere k")
    sys.exit(1)

key = sys.argv[1]
len_key = len(key)

if key.isalpha() == False:
    print("Usage: ./vigenere k")
    sys.exit(1)


pt = get_string("plaintext:")
ct = ""

n = len(pt)
j = 0
for i in range(n):
    k  = key[j % len_key]
    if k.islower():
        key_num = ord(k) - ord('a')
    else:
        key_num = ord(k) - ord('A')

    if pt[i].islower():
        cc = (ord(pt[i]) + key_num)
        if cc > ord('z'):
            c = chr(cc -26)
        else:
            c = chr(cc)
        j += 1
    elif pt[i].isupper():
        cc = (ord(pt[i]) + key_num)
        if cc > ord('Z'):
            c = chr(cc -26)
        else:
            c = chr(cc)
        j += 1
    else:
        c = pt[i]
    ct += c
    print(c)

print(f"ciphertext: {ct}")
