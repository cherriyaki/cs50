import sys
import cs50

# if number of args not 2, remind correct usage and stop program
if len(sys.argv) != 2:
    print("Usage: ./caesar k")
    sys.exit(1)

# convert user inputted key into int
k = int(sys.argv[1])

# get plaintext
ptext = cs50.get_string("plaintext: ")

# print 'ciphertext'
print("ciphertext: ", end = "")

# for each char in plaintext
for char in ptext:
    # if it's alphabet
    if char.isalpha() == True:
        # if it's uppercase
        if char.isupper() == True:
            # convert to int, -64 to get new index, add key and mod, then add back 64 for ascii
            print(chr((((ord(char) - 64) + k) % 26) + 64), end = "")
        # if it's lowercase
        elif char.islower() == True:
            # same procedure as uppercase but now for lower
            print(chr((((ord(char) - 96) + k) % 26) + 96), end = "")
    # if it's not alphabet, print as it is
    else:
        print(char, end = "")

# print new line
print()


