class Solution {
public:
    int partitionDisjoint(vector<int>& arr) {
        int leftMax = arr[0], maxVal = arr[0], ans = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < leftMax) {
                ans = i + 1;
                leftMax = maxVal;
            } else {
                maxVal = max(maxVal, arr[i]);
            }
        }
        return ans;
    }
};
