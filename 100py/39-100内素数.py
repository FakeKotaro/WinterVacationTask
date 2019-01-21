num = [2,3,]
for i in range(5,101):
    for j in range(2,i):
        if i % j == 0:
            break
    else:
        num.append(i)

print(num)
