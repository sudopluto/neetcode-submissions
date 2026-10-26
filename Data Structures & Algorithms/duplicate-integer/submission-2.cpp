class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        auto nums_set = std::unordered_set(nums.begin(), nums.end());
        return nums.size() != nums_set.size();
    }
};