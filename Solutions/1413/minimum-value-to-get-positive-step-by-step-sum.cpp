class Solution {
public:
    int minStartValue(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int minPrefixSum = *min_element(nums.begin(), nums.end());
        if (minPrefixSum <= 0) {
            return abs(minPrefixSum) + 1; 
        } else {
            return 1; 
        }
    }
};
