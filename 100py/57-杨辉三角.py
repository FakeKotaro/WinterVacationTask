Count = 2
List = [1]
List2 = []
Line = int(input("请输入行数:"))

print("[1]")
while Count < Line + 1:
    List2.append(1)
    if Count > 2:
        for i in range(Count - 2):
            List2.append(List[i] + List[i + 1])
    List2.append(1)
    List = List2.copy()
    print(List)
    List2.clear()
    Count = Count + 1

