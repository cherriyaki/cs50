import cs50

# keep prompting for height unless user gives int from 0-23
while True:
    print("Height: ", end = "")
    # when using imported functions, in python u must reference the lib
    h = cs50.get_int()
    if h >= 0 and h <= 23:
        break

# for each row in height
for i in range(h):
    # print spaces, no new line
    print(" " * (h-i-1), end = "")
    # print hashes, no new line
    print("#" * (i+2), end = "")
    # print new line
    print()

'''
wrote the following code without knowing about
range(n) giving n number of loops
multiple printing
print() being valid

if h > 0:
    for i in range(2,h+2):
        for j in range(0,h+1-i):
            print(" ", end = "")
        for k in range(0,i):
            print("#", end = "")
        print("")
'''
