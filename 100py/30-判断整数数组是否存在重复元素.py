li = list(map(int,input().split()))
for i in li:
    if li.count(i) > 1:
        print("true")
        break
else:
    print("false")