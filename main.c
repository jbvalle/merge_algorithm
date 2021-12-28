#include <stdio.h>
#include <stdlib.h>

int *merge(int *arr1, int *arr2, int size1, int size2){

    int *merged = (int *)malloc((size1 + size2) * sizeof(int));
    int state, flag[3][2] = {{1,0},{0,0},{1,1}};

    for(int i = 0, j = 0; (i < size1)||(j < size2);){

        merged[i + j - 1] = ((arr1[i] < arr2[j]) && flag[state][0]) || flag[state][1] ? arr1[i++]:arr2[j++]; 
        
        if(i == size1)state = 1;
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
