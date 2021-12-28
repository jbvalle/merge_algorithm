/* Algorithm for merging two array arrays of different sizes, which are ordered
 */

#include <stdio.h>
#include <stdlib.h>

int *merge(int *arr1, int *arr2, int size1, int size2){

    //Allocate memory for merged array
    int *merged = (int *)malloc((size1 + size2) * sizeof(int));
    //Ternary Operator -> val = EXPRESSION1 ? EXPRESSION2: EXPRESSION3
    //flag || {1,0} ... No changes -> Expression 1 of ternary Operator remains (arr1 < arr2)
    //flag || {0,0} ... Sets Expression 1 to FALSE -> only Expression 3 will be run
    //flag || {1,1} ... Sets Expression 1 to TRUE -> only Expression 2 will be run
    int state, flag[3][2] = {{1,0},{0,0},{1,1}};

    for(int i = 0, j = 0; (i < size1)||(j < size2);){

        merged[i + j - 1] = ((arr1[i] < arr2[j]) && flag[state][0]) || flag[state][1] ? arr1[i++]:arr2[j++]; 
        //If arr1 has reached its max then set EXP1 always to FALSE
        //arr1 will not be incremented
        if(i == size1)state = 1;
        //If arr2 has reached its max then set EXP1 always to TRUE
        //arr2 will not be incremented
        if(j == size2)state = 2;
    }

    return merged;
}


int main(void){


    int arr1[] = {1, 3, 5, 7, 8};
    int arr2[] = {2, 4, 6, 9, 10, 15, 16};

    int size1 = sizeof(arr1)/sizeof(arr1[0]), size2 = sizeof(arr2)/sizeof(arr2[0]);
    
    int *merged = merge(arr1, arr2, size1, size2);
    for(int i = 0; i < (size1 + size2); i++)printf("%d ", merged[i]);
    return 0;
}
