import csv
import sys

name = sys.argv[1]
types= []
with open('pokemons_list.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        if name.lower() in row[0].lower():
            number = int(row[0][1:4])
            types = row[0][:-1].split("|")[2:]
            if len(row) > 1:
                types.append(row[1].split("|")[0])
if len(types) == 1:
    stypes = types[0]
elif len(types) == 2:
    stypes = "%s and %s" % (types[0], types[1])
if len(types) > 0:
    print("His number is %d and he is of type %s." % (number, stypes))
else:
    print("pokemon not found")
