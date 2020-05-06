import numpy as np
import matplotlib.pyplot as plt
np.random.seed(2)
MAX = 50
N = 20
x = np.random.randint(MAX, size=(N,))
y = np.random.randint(MAX, size=(N,))
points = np.array([(a, b) for a, b in zip(x, y)])

points = sorted(points, key=lambda a: a[0])
left = points[0]
plt.scatter(left[0], left[1], c='red')


# plt.plot([left[0], currentVertex[0]], [left[1], currentVertex[1]])
# plt.plot([left[0], nextVertex[0]], [left[1], nextVertex[1]])
# plt.scatter(currentVertex[0], currentVertex[1], c='orange')
# plt.scatter(nextVertex[0], nextVertex[1], c='green')

# print(np.cross(currentVertex, nextVertex))


def convexHull(points):
    hull = []
    currentVertex = points[0]
    nextVertex = points[1]
    index = 2
    hull.append(currentVertex)
    while(True):
        while index < len(points):
            checking = points[index]
            a = nextVertex - currentVertex
            b = checking - currentVertex
            # print(currentVertex, nextVertex, checking, a, b, np.cross(a, b))
            if(np.cross(a, b) > 0):
                nextVertex = checking
            index += 1
        # print("Loop Completed")
        index = 0
        hull.append(nextVertex)
        currentVertex = nextVertex
        nextVertex = hull[0]
        # print(hull)
        if(np.all(hull[0] == hull[-1])):
            break

    return hull


plt.subplots_adjust(left=0.10, right=0.95, hspace=0.25,
                    wspace=0.35)
# fig = plt.figure(figsize=(10, 20))


plt.subplot(2, 1, 1)
plt.scatter(x, y)
plt.title('Points')
plt.xlabel('X')
plt.ylabel('Y')


hull = convexHull(points)

plt.subplot(2, 1, 2)
plt.scatter(x, y)

i = 0
while i < len(hull)-1:
    plt.scatter([hull[i][0], hull[i+1][0]],
                [hull[i][1], hull[i+1][1]], c='purple', linewidths=4)
    plt.plot([hull[i][0], hull[i+1][0]], [hull[i][1], hull[i+1][1]], c='red')
    i += 1

plt.title('Convex Hull using Jarvis')
plt.xlabel('X')
plt.ylabel('Y')

plt.show()
