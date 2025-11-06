/** 
 * Forward declaration of guess API.
 * int guess(int num);
 */

int guess(int num);  // Required declaration

int guessNumber(int n) {
    int low = 1, high = n;
    while (low < high) {
        // Use unsigned right shift to avoid overflow and optimize division
        int mid = low + ((high - low) >> 1);
        int res = guess(mid);
        if (res == 0)
            return mid;
        else if (res < 0)
            high = mid;      // exclude mid because num > pick
        else
            low = mid + 1;   // num < pick
    }
    return low;
}
