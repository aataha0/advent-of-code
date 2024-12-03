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
        continue

    for i in range(len(report)):
        # enlever i du rapport
        new_report = report[:i] + report[i+1:]
        # puisqu'on change la longueur du rapport, on verifie une deuxieme fois s'il est plus grand que 1
        if len(new_report) > 1 and is_safe(new_report):
            count += 1
            break

print(count)
