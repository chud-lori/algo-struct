
a = [aa for aa in range(13)]
k = 4
lenn = math.ceil(len(hs)/k)

for i in range(lenn):
    first = i*k
    last = (i+1)*k
    if last >= len(a):
        hsl.append()
        print(a[first:])
    else:
        print(a[first:last])

