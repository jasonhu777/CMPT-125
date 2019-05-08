#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool CheckIfSorted(int arr[], int length){

    for (int i = 0; i < length; i++){
        if (arr[i] > arr[i+1]){
            return false;
    }
    return true;
}


int BinarySearch(int arr[], int len, int target) {
    assert(CheckIfSorted(arr, len));

    return 0;
}


int main(){

    int arr2[] = {1,2,3,5,4,6,7,8};
    BinarySearch(arr2, 8, 4);
    return 0;
