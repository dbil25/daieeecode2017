import csv
import sys
import random

name = sys.argv[1]
pokemonlist= []
with open('pokemons_list.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        pokemonlist.append(row[0].split("|")[1].lower())
name = name.lower()

#RANSAC OH YEAH
found = False
for i in range(1000000):
    temp = "".join(random.sample(name,len(name)))
    if temp in pokemonlist:
        found = True
        name = temp
        break
if found:
    print(name)
else:
    print("no pokemon found")
