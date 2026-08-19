class Solution:
    def isValid(self, s: str) -> bool:
        map_parens = {")": "(", "}": "{", "]": "["}

        stack: list[str] = []
    
        for char in s:
            if char in map_parens:
                if len(stack) == 0 or map_parens[char] != stack[-1]:
                    return False
                else:
                    _ = stack.pop()
            else:
                stack.append(char)
    
        return len(stack) == 0