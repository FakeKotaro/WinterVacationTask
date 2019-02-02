import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)

rect = plt.Rectangle((0.1,0.1),0.5,0.3)
ax.add_patch(rect)

plt.show()