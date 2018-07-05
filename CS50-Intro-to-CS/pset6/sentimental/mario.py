from cs50 import get_int

while True:
    height = get_int("How high do you want the pyramid? ")
    if height < 24 and height >= 0:
        break

# there will be 'height' rows

for i in range(height):
    spaces = height - 1 - i
    hashes = height - spaces
    for j in range(spaces):
        print(" ", end='')
    print("#", end='')
    for k in range(hashes):
        print("#", end='')
    print('')
