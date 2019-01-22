while 1:
    n = int(input("请输入数字："))
    if (n * n < 50):
        break
    else:
        print("该数字平方为：%d"%(n * n))