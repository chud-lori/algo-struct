import re

def is_palindrome(s: str):
    s = re.sub(r'[^A-Za-z0-9]', '', s)

    s = s.lower()
    lens = len(s)

    revName = []

    for i in range(lens-1, -1, -1):
        revName.append(s[i])

    rev = "".join(revName)

    return s == rev

print(is_palindrome("race a car"))
print(is_palindrome("0P"))
print(is_palindrome("kasur rusak"))

