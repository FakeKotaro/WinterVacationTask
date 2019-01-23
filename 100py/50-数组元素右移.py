li = list(map(int,input("请输入数组，用空格隔开：").split()))
n = int(input("请输入右移个数："))
Newli = li[len(li)-n:len(li)] + li[0:len(li)-n]
print(Newli)