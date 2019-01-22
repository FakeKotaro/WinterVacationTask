li = list(map(int,input("请输入九个数字，用空格隔开以构成矩阵：").split()))
print("您输入的矩阵为：")
for i in range(0,9):
    print("%d"%li[i],end = '  ')
    if i == 2 or i == 5:
        print("\n")
print("主对角线元素和为：%d"%(li[0]+li[2]+li[4]+li[6]+li[8]))
