n = input("请输入一个五位数：")
li = list(n)
if li[0] == li[4] and li[1] == li[3]:
    print("该数字是回文数")
else:
    print("该数字不是回文数")