def fun(n):
    if n == 1:
        return 1
    else:
        return n * fun(n-1)

sum = 0
for i in range(1,21):
    sum += fun(i)
print(sum)

