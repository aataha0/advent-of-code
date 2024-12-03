right = []
left = []

with open("./input.txt") as f:
    lines = f.readlines()
    for line in lines:
        rl, ll = line.split("   ")
        right.append(int(rl))
        left.append(int(ll))

right.sort()
left.sort()

diff = 0
for i in range(len(right)):
    diff += abs(right[i] - left[i])

print(diff)
