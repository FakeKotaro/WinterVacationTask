import turtle
pen = turtle.Turtle()
a = 1
for i in range(120):
    if 0 <= i < 30 or 60 <= i < 90:
        a = a + 0.2
        pen.lt(3)
        pen.fd(a)
    else:
        a = a - 0.2
        pen.lt(3)
        pen.fd(a)

print(pen)
turtle.mainloop()