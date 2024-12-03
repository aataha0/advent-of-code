def is_safe(report):
    trend_upwards = report[1] >= report[0]
    for i in range(len(report) - 1):
        if abs(report[i + 1] - report[i]) < 1 or abs(report[i + 1] - report[i]) > 3 or (trend_upwards and report[i + 1] < report[i]) or (not trend_upwards and report[i + 1] > report[i]):
            return False
    return True

reports = []

with open("./input.txt") as f:
    reports = f.read().splitlines()
    reports = [[int(level) for level in report.split(" ") if level != ""] for report in reports]

count = 0
for report in reports:
    if len(report) < 2:
        continue

    if is_safe(report):
        count += 1

print(count)
