# perfect number
container = []
for i in range(1, 101):
    sum_con = []
    for j in range(1, i):
        if i % j == 0:
            sum_con.append(j)

    if sum(sum_con) == i:
        container.append(i)

print(f"Perfect number between 1-100: {container}")

# perfect square number
container = []
latest = 0
for i in range(1, 101):
    if latest >= 100:
        break
    latest = i*i
    container.append(latest)

print(f"Perfect square number between 1-100: {container}")

