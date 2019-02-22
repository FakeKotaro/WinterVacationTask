s1 = input("请输入长字符串：")
s2 = input("请输入短字符串：")
for i in range(len(s1) - len(s2) + 1):
    if s1[i:i+len(s2)] == s2:
        print("此短字符串在长字符串中，且在第%d个字符位置"%i)
        break
else:
    print("此短字符串不在长字符串中")

