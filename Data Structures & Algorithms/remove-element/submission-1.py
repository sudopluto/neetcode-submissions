class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0

        lr_head = 0
        rl_head = len(nums) - 1

        #lr advances, if encounters val then swaps with rl_head
        #rl_head points to furthest avail valid val for swap
        #at the end rl_head will be meet lr head at end of valid array
        while lr_head < rl_head:
            if nums[rl_head] == val:
                rl_head -= 1
            elif nums[lr_head] == val:
                nums[lr_head] = nums[rl_head]
                rl_head -= 1
            else:
                lr_head += 1

        return 0 if lr_head == 0 else lr_head + 1 