#include <stdio.h>
#include "lib/matrixlib.h"
#include "lib/staticlib.h"

int findMax(int*, int, int, int);

int main() {
    int size = 7;
    int A[size];
    if (inputIntArray(A, size)) {
        //максимум на четных позициях
        int maxo = findMax(&A, 0, size, 2);
        //максимум на нечетных позициях
        int maxe = findMax(&A, 1, size, 2);
        if(maxo-maxe == 0)
            return 1;
        double Z = (double) (maxo + maxe)/(maxo-maxe);
        printf("maxo = %d maxe = %d Z = %lf", maxo,maxe,Z);
    } else {
        printf("Error in input.\n");
    }
    return 0;
}

//поиск максимума с шагом
int findMax(int *arr, int start, int size, int step){
    int max = *(arr+start);
    int index = start;
    while(index+step < size){
        max = max < *(arr+index+step) ? *(arr+index+step) : max;
        index += step;
    }
    return max;
}