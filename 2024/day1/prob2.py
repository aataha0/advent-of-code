right = []
left = []

with open("./input.txt") as f:
    lines = f.readlines()
    for line in lines:
        rl, ll = line.split("   ")
        right.append(int(rl))
        left.append(int(ll))

def find_occurence(arr, num):
    count = 0
    for i in arr:
        if i == num:
            count += 1
    return count

sim = 0
for i in range(len(right)):
    sim += abs(find_occurence(right, left[i]) * left[i])

print(sim)
