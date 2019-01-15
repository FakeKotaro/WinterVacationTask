y = int(input("请输入年份："))
m = int(input("请输入月份："))
d = int(input("请输入日期（天）："))

if (y//4 == 0 and y//100 != 0) or y//400 == 0:
    ds = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
else:
    ds = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

n = 0
for i in range(1, 13):
    if i == m:
        for j in range(i-1):
                n += ds[j]
        print("此日期是该年第%d天"%(n+d))

