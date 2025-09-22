#include<stdio.h>
int maximumPopulation(int** logs, int logsSize, int* logsColSize) {
    int yearFreq[101] = {0};
    for(int i=0; i<logsSize; i++){
        for(int j=logs[i][0]; j<logs[i][1]; j++){
            yearFreq[j - 1950]++;
        }
    }
    int max = yearFreq[0], ind = 0;
    for(int i=1; i<101; i++){
        if(yearFreq[i] > max){
            max = yearFreq[i];
            ind = i;
        }
    }
    return ind + 1950;

}
