class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 0) {
            std::cout << "[ ]\n";
            return 0;
        }

        int k = 1;
        size_t r_head = 1;
        size_t w_head = 1;

        while (r_head < nums.size()) {
            if (nums[r_head] == nums[w_head - 1]) {
                r_head++;
            } else {
                nums[w_head] = nums[r_head];
                r_head++;
                w_head++;
                k++;
            }
        }
        return k;
    }
};