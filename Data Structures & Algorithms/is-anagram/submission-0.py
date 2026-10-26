class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_chars, t_chars = defaultdict(int), defaultdict(int)
        for i in range(len(s)):
            s_chars[s[i]] += 1
            t_chars[t[i]] += 1
        
        if len(s_chars) != len(t_chars):
            return False
        
        for k in s_chars:
            if (k not in t_chars) or (s_chars[k] != t_chars[k]):
                return False
        
        return True
        