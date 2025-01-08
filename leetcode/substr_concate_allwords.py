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

   word_len = len(words[0])
   word_count = len(words)
   total_len = word_len * word_count

   # Frequency map for the words
   word_map = {}
   for word in words:
       word_map[word] = word_map.get(word, 0) + 1

   indices = []
   for i in range(len(s) - total_len + 1):
       seen = {}
       j = 0
       while j < word_count:
           # Extract a word from the sliding window
           start = i + j * word_len
           word = s[start:start + word_len]

           if word in word_map:
               seen[word] = seen.get(word, 0) + 1
               # If a word is seen more times than it exists in the word list
               if seen[word] > word_map[word]:
                   break
           else:
               break
           j += 1

       if j == word_count:
           indices.append(i)

   return indices

if __name__ == "__main__":
    s="barfoothefoobarman"
    words = ["foo", "bar"]
    assert findSubstringHelp(s, words) == [0,9]

    s = "barfoofoobarthefoobarman"
    words = ["bar","foo","the"]
    assert findSubstringHelp(s, words) == [6,9,12]

    s = "wordgoodgoodgoodbestword"
    words = ["word","good","best","word"]
    assert findSubstringHelp(s, words) == []
