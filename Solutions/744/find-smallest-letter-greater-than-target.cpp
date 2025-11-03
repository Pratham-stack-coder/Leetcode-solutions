class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int low = 0, high = letters.size() - 1;

        if (target >= letters.back())
        {
            return letters[0];
        }
        int mid = letters.size() / 2;
        int prevmid = mid;
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            if (letters[mid] <= target)
                low = mid + 1;  // move right
            else
                high = mid - 1; // move left
        }
        return letters[low % letters.size()];
    }
};
