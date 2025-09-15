class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n= num.size();
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++){
                if (num[i] + num[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};
