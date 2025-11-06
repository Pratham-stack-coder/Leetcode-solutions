class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    v.push_back(matrix[i][j]);
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==target) return true;
        }
        return false;
    }
};
