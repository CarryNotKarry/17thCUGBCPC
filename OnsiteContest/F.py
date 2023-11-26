s = input()
s = '[' + s + ']'
sta = []
top = 0
l_sta = []
for c in s:
    if c == '[':
        l_sta.append(top)
    elif c == ']':
        l = l_sta.pop()
        r = top
        res = 0
        p = l
        for i in range(l, r):
            if sta[i].isdigit():
                res = res * 10 + int(sta[i])
            else:
                p = i
                break
        if res == 0:
            res = 1
        new_sta = sta[:l] + sta[p:r] * res
        sta = new_sta
        top = len(sta)
            
    else:
        sta.append(c)
        top += 1
for c in sta:
    print(c, end='')
# a[1b[2d[3e[4f[5g[6[h]i]j]k]l]m]c]z
