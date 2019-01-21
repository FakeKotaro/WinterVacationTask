n = input("请输入一个不多于5位的正整数：")
print("这是一个%d位数"%len(n))
li = list(n)
li.reverse()
print("相反顺序后：")
for i in li:
    print(i)
