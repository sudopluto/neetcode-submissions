class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        net_char_hist = defaultdict(int)

        for i in range(len(s)):
            net_char_hist[s[i]] += 1
            net_char_hist[t[i]] -= 1
        
        for v in net_char_hist.values():
            if v != 0:
                return False

        return True