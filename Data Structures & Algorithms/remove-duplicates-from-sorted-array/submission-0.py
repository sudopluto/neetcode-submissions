class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        r_head = 1
        w_head = 1
        
        while r_head < len(nums):
            if nums[r_head] == nums[w_head -1]:
                r_head += 1
            else:
                nums[w_head] = nums[r_head]
                  
                r_head += 1
                w_head += 1

        nums = nums[:w_head]
        return w_head 