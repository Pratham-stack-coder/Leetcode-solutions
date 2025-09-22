#include <stdio.h>
#include <stdbool.h>

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int stops[1001] = {0};  // since max location is 1000

    for (int i = 0; i < tripsSize; i++) {
        int numPassengers = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];
        
        stops[from] += numPassengers;   // pick up passengers
        stops[to] -= numPassengers;     // drop off passengers
    }

    int currentLoad = 0;
    for (int i = 0; i <= 1000; i++) {
        currentLoad += stops[i];
        if (currentLoad > capacity) {
            return false;
        }
    }

    return true;
}
