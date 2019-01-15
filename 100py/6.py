def FBNQ(n):
    if n==1 or n==2:
        return 1
    else:
        return FBNQ(n-1) + FBNQ(n-2)

n = int(input("请输入项数："))
for i in range(1,n+1):
    print(FBNQ(i))


