str = input("请输入一个字符串:")
def fun(x):
    if x == -1:
        return ''
    else:
        return str[x] + fun(x-1)

print(fun(len(str)- 1))