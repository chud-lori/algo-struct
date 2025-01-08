
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag_map = {}
        for i in magazine:
            if i in mag_map:
                mag_map[i] += 1
            else:
                mag_map[i] = 1

        for i in ransomNote:
            if not mag_map.get(i, 0):
                return False
            mag_map[i] -= 1

        return True

