def psage(items, size):
    for i, idx in enumerate(items):
        sub = []
        r = items[idx-1:idx+size-1]
        print(f"IDX: {idx}")
        if idx == 1:
            print("FIRsT")
            r = items[:idx+size-1]
        #else:
        #    print(idx-1)
        #    print(r)
            #break
        #print(idx)
        #print(items[idx+1:])
        if len(items[idx+1:]) < size:
            print(idx)
            r = items[idx+1:]

        sub.append(r)
        #for j in r:
        #    #print(r)
        #    sub.append(j)

        #yield sub
        if len(sub) == 0:
            break
        print(sub)
        print("*"*20)


def page(items, size):
    for i in range(0, len(items), size):
        print(items[i:size+i])

page([1,3,5,6,8,22,12], 2)

