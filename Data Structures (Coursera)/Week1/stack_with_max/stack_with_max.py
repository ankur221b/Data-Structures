#use python3

s, ma = [], []

def push(x):
    s.append(x)
    if len(ma):
        x = max(x,ma[-1])
        ma.append(x)
    else:
        ma.append(x)

def pop():
    s.pop()
    ma.pop()

def maximum():
    return ma[-1]

n = int(input())

for _ in range(n):
    operation = input().split()
    if operation[0] == 'push':
        push( int(operation[1]) )

    if operation[0] == 'pop':
        pop()

    if operation[0] == 'max':
        print( maximum() )

