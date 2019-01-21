n = int(input())
while(n > 1):
    if n % 3 != 0:
        print("No")
        break
    n /= 3
else:
    print("Yes")
