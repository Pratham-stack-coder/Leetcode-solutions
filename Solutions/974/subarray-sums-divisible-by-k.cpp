class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int count = 0;
        
        // Iterate through all possible subarrays
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                // Check if the sum is divisible by k
                if (sum % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
