li = list(map(int,input("请输入三个数字：").split()))
x = min(li)
li.remove(x)
z = max(li)
li.remove(z)
print(x,li[0],z)

