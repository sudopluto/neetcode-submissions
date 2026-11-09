def concatenate(s1: str, s2: str) -> str:
    s_comb = s1 + s2
    return "Too long!" if len(s_comb) > 10 else s_comb




# do not modify below this line
print(concatenate("He", "llo"))
print(concatenate("Hello ", "world!"))
print(concatenate("Length", "of10"))
