# 30. Substring with Concatenation of All Words
def findsubstr(s: str, words: list):
    print(f"WORDS: {words}")
    print(f"S: {s}")
    lens = len(s)
    totwordlen = len("".join(words))
    words = sorted(words)
    trval = 0
    indices = []
    for i, v in enumerate(s):
        if (i + (totwordlen - 1) > lens):
            break

        slide = s[i:i+totwordlen]
        print(slide)
        for j in words:
            #lenw = len(j)
            print(f"J : {j}")
            if j in slide:
                trval += 1
                if trval == len(words):
                    indices.append(i)
                    trval = 0
                    break
            else:
                trval = 0
                break

    print(f"RESULT: {indices}")
    return indices



def findsubstrr(s, words):
    counts = {}
    for w in words:
        counts.update({w: counts.get(w, 0) + 1})

    indexes = []
    n = len(s)
    num = len(words)
    lenn = len(words[0])

    for i in range(0, n - num * lenn + 1):
        seen = {}
        j = 0
        print(f"i HER: {i}")
        while j < num:
            word = s[i + j * lenn:i + (j + 1) * lenn +1]
            print(word)
            if word in counts:
                seen.update({word: seen.get(word, 0) + 1})
                if seen.get(word) > counts.get(word, 0):
                    break
            else:
                break
            j += 1
        if j == num:
            indexes.append(i)

    return indexes

def findSubstringHelp(s: str, words: list):
    if not s or not words:
        return []

    word_len = len(words[0]) # assume each items in list has same length
    word_count = len(words)
    total_len = word_len * word_count

    # map count each word appear in list words
    word_map = {}
    for word in words:
        word_map[word] = word_map.get(word, 0) + 1

    indices = []

    # loop the string s
    # the loop limitation is to make sure it's not surpassed the length s
    for i in range(len(s) - total_len + 1):
        seen = {}
        # this j variable used for counting the word if exist in our words list
        j = 0
        # this loop will check each word start from index i
        while j < word_count:
            # calculate the starting position for the window slide
            # so each loop in this while meant to check each word
            # we need i as starting point
            start = i + j * word_len
            word = s[start:start + word_len]
            print(word)
            if word in word_map:
                seen[word] = seen.get(word, 0) + 1
                # check if word shown in s is more than in word map count
                if seen[word] > word_map[word]:
                    break
            else:
                # if word not in map meaning arbitrary word, skip
                break

            # increment j to check next word
            j += 1

        # if the j count is same as our word_count meaning it match the words list and add the index
        if j == word_count:
            indices.append(i)

    return indices

if __name__ == "__main__":
    s="barfoothefoobarman"
    words = ["foo", "bar"]
    assert findSubstringHelp(s, words) == [0,9]

    #s = "barfoofoobarthefoobarman"
    #words = ["bar","foo","the"]
    #assert findSubstringHelp(s, words) == [6,9,12]

    #s = "wordgoodgoodgoodbestword"
    #words = ["word","good","best","word"]
    #assert findSubstringHelp(s, words) == []
