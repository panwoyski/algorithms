import sys

with open('true_recursion_{}.txt'.format(sys.argv[1]), 'w') as fd:
    fd.write('{} {}\n'.format(0, sys.argv[1]))
    for i in range(int(sys.argv[1])):
        fd.write('{} {}\n'.format(i, i+1))

