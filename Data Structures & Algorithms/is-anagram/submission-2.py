class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        char_freq_lut = [0] * 26

        for i in range(len(s)):
            char_freq_lut[ord(s[i]) - ord('a')] += 1
            char_freq_lut[ord(t[i]) - ord('a')] -= 1
        
        for i in range(26):
            if char_freq_lut[i] != 0:
                return False
        
        return True