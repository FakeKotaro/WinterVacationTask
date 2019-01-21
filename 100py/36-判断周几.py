c1 = input("请输入第一个字母：")
if c1 == 'm' or c1 == 'M':
    print("周一")
elif c1 == 'w' or c1 == 'W':
    print("周三")
elif c1 == 'f' or c1 == 'F':
    print("周五")
elif c1 == 't' or c1 == 'T':
    c2 = input("请输入第二个字母：")
    if c2 == 'u':
        print("周二")
    else:
        print("周四")
else:
    c2 = input("请输入第二个字母：")
    if c2 == 'u':
        print("周日")
    else:
        print("周六")

