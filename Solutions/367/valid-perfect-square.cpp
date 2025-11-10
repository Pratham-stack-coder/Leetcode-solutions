class Solution {
public:
    bool isPerfectSquare(int n) {
        if(n == 1 || n == 0) return n;        
        if(n == 4) return 2;    
        // int overFLow = INT_MAX;    
        int i = 1;
        int end = n/3;
        long long int mid;
        for(; i<= end;){
            mid = i + (end-i)/2;
            if(n == mid * mid) return true;
            if(n > mid*mid) i = mid+1;
            else end = mid-1 ;
        }
        return false;
    }
};
