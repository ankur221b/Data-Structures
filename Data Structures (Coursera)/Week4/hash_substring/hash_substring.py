#use python3

pat = input()
s = input()

h = sum([ord(i) for i in pat])

tmp = s[0:len(pat)]

h_tmp = sum([ord(i) for i in tmp])
if h_tmp == h and pat == tmp:
    print(0,end=' ')

for i in range(1,len(s)-len(pat)+1):
    h_tmp -= ord(s[i-1])
    h_tmp += ord(s[i+len(pat)-1])

    if h == h_tmp and pat == s[i:i+len(pat)]:
        print(i,end=' ')



