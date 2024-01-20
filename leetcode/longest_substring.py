class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index_map = {}  # To store the index of each character in the string
        start = 0  # Start index of the current substring
        max_length = 0  # Maximum length of substring without repeating characters

        for end in range(len(s)):
            if s[end] in char_index_map and char_index_map[s[end]] >= start:
                # If the character is repeated and its index is greater than or equal to the start,
                # move the start index to the next position of the repeated character
                start = char_index_map[s[end]] + 1

            # Update the index of the current character
            char_index_map[s[end]] = end

            # Update the maximum length if the current substring is longer
            max_length = max(max_length, end - start + 1)

        return max_length
