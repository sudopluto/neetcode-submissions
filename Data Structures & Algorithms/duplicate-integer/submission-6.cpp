class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        auto seen_nums = std::unordered_set<int>{};
        for(const auto& num : nums) {
            if(seen_nums.contains(num)) {
                return true;
            } else {
               seen_nums.insert(num); 
            }
        }
        return false;
        
    }
};