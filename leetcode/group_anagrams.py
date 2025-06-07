from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        data = {}
        for val in strs:
            sortedda = ''.join(sorted(val))
            if sortedda in data:
                data[sortedda].append(val)
            else:
                data[sortedda] = [val]
        return [data[i] for i in data]

