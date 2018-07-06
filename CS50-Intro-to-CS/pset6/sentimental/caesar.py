# Caesar.py
# Must take one argument, an integer, which is the key
# I must then ask for a plaintext word to shift

import sys
from cs50 import get_string

if len(sys.argv) == 2:
    key = int(sys.argv[1])
    plaintext = get_string("plaintext: ")
    final = ""
    for letter in plaintext:
        subtractor = 65 if letter.isupper() else 97
        if letter.isalpha():
            tmp = ord(letter) - subtractor + key
            tmp %= 26
            tmp += subtractor
            final += chr(tmp)
        else:
            final += letter
    print("ciphertext: ",final);
else:
    print(f"You must enter more than one argument.")
    exit(1)