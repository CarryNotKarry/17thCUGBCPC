n = int(input())
p_Alice, p_Bob = 0, 0
num_Alice, num_Bob = 0, 0
for i in range(n):
    t, a, b = map(int, input().split())
    if b == 0:
        continue
    else:
        p_Alice += (a - 1) * 20 + t
        num_Alice += 1
for i in range(n):
    t, a, b = map(int, input().split())
    if b == 0:
        continue
    else:
        p_Bob += (a - 1) * 20 + t
        num_Bob += 1
if num_Alice == num_Bob:
    print('Alice' if p_Alice < p_Bob else 'Bob')
else:
    print('Alice' if num_Alice > num_Bob else 'Bob')