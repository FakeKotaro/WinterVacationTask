li = list(map(int,input("给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次:").split()))
for i in li:
    if li.count(i) == 1:
        print("该元素为%d"%i)
        break
