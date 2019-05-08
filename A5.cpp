#include <stdio.h>
#include <stdlib.h>


//Question 1a
void swap(int arr[], int i, int j){

	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}

//Question 1b
int partition(int arr[], int first, int last){
    int j;
    int pivot = arr[last];
    int i = (first-1);
    for(j = first; j < last; j++){
        if(arr[j] <= pivot){
            i = i+1;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,j);
    return(i+1);

}

//Question 1c
void quickSortR(int arr[], int first, int last){
    if(first < last){
        int pi = partition(arr,first,last);
        quickSortR(arr,first,pi-1); //Sort from arr[0] to arr[pi-1]
        quickSortR(arr,pi+1,last); //Sort from arr[pi+1] to last
    }

}



void arrCpy(int dest[], int src[], int len){
    for(int l = 0; l < len; l++){
        dest[l] = src[l];
    }

}

void merge(int arr[], int first, int mid, int last) {
    int len = last-first+1;
    int newArr[len];
    int left = first;
    int right = mid+1;
    int newPos = 0;
    while(left <= mid && right <= last) {
        if (arr[left] == arr[right]){
            arr[right] = -1;
        }
        if (arr[left] < arr[right]) {
            newArr[newPos++] = arr[left++];
        }
        else {
            newArr[newPos++] = arr[right++];
        }



    arrCpy(newArr + newPos, arr + left, mid - left + 1);
    arrCpy(newArr + newPos, arr + right, last - right + 1);
    arrCpy(arr + first, newArr, len);

}
}
void mergeSort(int arr[], int first, int last) {

    if (last <= first)
        return;

    // Split array
    int mid = (first+last)/2;

    // Recursively sort
    mergeSort(arr, first, mid);
    mergeSort(arr, mid+1, last);

    // Join
    merge(arr, first, mid ,last);

}

void main() {
    int arr[14] = {488888, 3, 5, 0, 23, 12124, 6, 7, 2, 1121, 0, 92, 5, 8};
    quickSortR(arr, 0, 13);
    for (int i = 0; i<14; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); Printing Sorted Array
    }




}
