# python3
import sys

def opening(s):
    return s=='[' or s=='{' or s=='('

def closing(s):
    return s==']' or s=='}' or s==')'

def chk(b,a):
    if a=='[':
        return b==']'
    if a=='(':
        return b==')'
    if a=='{':
        return b=='}'

s = input()
if len(s)==1:
    print(1)
    sys.exit()
v = []
openn = []
res=-1
close=False

for i in range(len(s)):
    if opening(s[i]):
        v.append(s[i])
        openn.append(i+1)
    if closing(s[i]):
        if len(v) and chk(s[i],v[len(v)-1])==False:
            res=i+1
            close=True
            break
        elif len(v)==0:
            print(i+1)
            sys.exit()
        else:
            v.pop()
            openn.pop()

if res==-1 and len(v)==0:
    print("Success")
elif close==True:
    print(res)
else:
    print(openn[-1])
    
    
    
