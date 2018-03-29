import cs50

# keep prompting for float (dollar change in decimals)
while True:
    # can put message in get_float() directly. if user doesn't enter float(number), it will automatically prompt until they do
    dls = cs50.get_float("Change owed: ")
    # if user has given a float and it's not negative, break out of loop
    if dls >= 0:
        break

# convert dollar change to cents (multiply by 100), then round to nearest integer to remove any random trailing numbers (floating point imprecision)
cts = round(dls * 100)
# set up total number of coins needed
ntotal = 0

# for each coin value
for v in [25,10,5,1]:
    # get number of coins in the amount to be tested
    n = cts // v
    # update total
    ntotal += n
    # get remainder amount after accounting for the bigger coin
    r = cts % v
    # update the amount to be tested
    cts = r

# print the total number of coins needed
print(ntotal)

