/* Algorithm for merging two array arrays of different sizes, which are ordered
 */

#include <stdio.h>
#include <stdlib.h>

int *merge(int *arr, int start, int mid, int end){

    //Allocate memory for merged array
    int *merged = (int *)malloc((end-start+1) * sizeof(int));
    //Ternary Operator -> val = EXPRESSION1 ? EXPRESSION2: EXPRESSION3
    //flag || {1,0} ... No changes -> Expression 1 of ternary Operator remains (arr1 < arr2)
    //flag || {0,0} ... Sets Expression 1 to FALSE -> only Expression 3 will be run
    //flag || {1,1} ... Sets Expression 1 to TRUE -> only Expression 2 will be run
    int state, flag[3][2] = {{1,0},{0,0},{1,1}};

    for(int i = start, j = mid + 1, x = 0; (i <= mid)||(j <= end);){

        merged[x++] = ((arr[i] < arr[j]) && flag[state][0]) || flag[state][1] ? arr[i++]:arr[j++]; 
        //If arr1 has reached its max then set EXP1 always to FALSE
        //arr1 will not be incremented
        if(i > mid)state = 1;
        //If arr2 has reached its max then set EXP1 always to TRUE
        //arr2 will not be incremented
        if(j > end)state = 2;
    }

    return merged;
}


int main(void){


    int arr[] = {1, 3, 5, 7, 8, 9, 4, 6, 9, 10, 15, 16};

    int start = 0, end = sizeof(arr)/sizeof(arr[0]) - 1;
    int mid = (end-start)/2;

    int *merged = merge(arr, 0, mid, end);
    for(int i = 0; i <= (end-start); i++)printf("%d ", merged[i]);
    return 0;
}
