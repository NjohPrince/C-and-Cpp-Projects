#include<stdio.h>

/* Function to perform swapping */
void swap(int *element_1, int *element_2){
    int temp = *element_1;
    *element_1 = *element_2;
    *element_2 = temp;
}

/* Bubble Sort function */
void bubbleSort(int array[], int size){
    int i, j;
    for(i = 0; i < size-1; i++){
        // j runs to n-i-1 since the last i element is already the greater than the previous
        // so does not needs comparison
        for(j = 0; j < size-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

/* function to print the array elements */
void printElementsOfArray(int array[], int size){
    int i;
    printf("\nArray Elements: ");
    // using a loop to iterate through the array, printing the elements
    for(i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void){
    int array[] = {23, 45, 65, 17, 55, 98, 76};
    int size = sizeof(array)/sizeof(array[0]);

    // printing the array elements before performing sorting
    printf("Before Sorting: ");
    printElementsOfArray(array, size);

    bubbleSort(array, size);

    printf("\nAfter Sorting: ");
    printElementsOfArray(array, size);

    return 0;
}
