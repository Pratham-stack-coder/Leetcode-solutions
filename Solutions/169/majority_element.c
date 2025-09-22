int majorityElement(int* nums, int n) {
    int count = 0;
    int candidate = 0;
    for(int i = 0; i<n ; i++){
        if(count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;

    }
    return candidate;
}
