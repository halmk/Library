import os

path = '../input.txt'
with open(path, 'w') as f:
    s = ''
    for i in range(500000):
        if i % 2 == 0:
            s += '<'
        else:
            s += '>'
    f.write(s)