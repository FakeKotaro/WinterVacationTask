def Fenzi(n):
    if n == 1:
        return 2
    elif n == 2:
        return 3
    else:
        return Fenzi(n-1) + Fenzi(n-2)

def Fenmu(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    else:
        return Fenmu(n-1) + Fenmu(n-2)

sum = 0
n = 0
for i in range(1,21):
    sum += n
    n = Fenzi(i)/Fenmu(i)
print(sum)



