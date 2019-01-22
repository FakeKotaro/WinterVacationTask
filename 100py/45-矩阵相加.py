li1 = list(map(int,input("请输入一个3*3矩阵，数字间用空格隔开：").split()))
li2 = list(map(int,input("请输入第二个矩阵：").split()))
print("矩阵相加后的新矩阵为：")
for i in range(9):
    new = li1[i] + li2[i]
    print("%d"%new,end = '  ')
    if i == 2 or i == 5:
        print("")

