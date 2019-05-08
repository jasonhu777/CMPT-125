#include <stdio.h>

/////////////////////////////////
/*Question 1b*/
/////////////////////////////////


int FibIter(int k) {
    int n1 = 1;
    int n2 = 1;
    int n3 = 1; //if the user doesn't enter <= 2, return n3 as beign 1
    for (int i = 2; i < k; i++){
        n3 = n1+n2; //adding two previous numbers
        n1 = n2; //set n1 to n2
        n2 = n3; //set n2 to n3
    }
    return n3;
}


/////////////////////////////////
/*Question 2a*/
/////////////////////////////////

int findMinpos(int arr[], int mid, int len){


    static int index; //let index be a static int so it is intialized once and doesn't lose its value :)
    static int temp;

    if (temp == 0){
        index = mid; //to start off index to be equal to mid so we have a val to compare to
        temp = temp + 1; //set temp to + 1 so we dont enter here again
    }

    if (mid == len){ //Remember that in a array we count from 0
        temp = 0; //reset temp counter since we may need this after
        return index;
    }
    else if (arr[index] <= arr[mid]){
        findMinpos(arr, mid+1, len); //if index is <= mid, dont change index
    }
    else if(arr[index] > arr[mid]){
        index = mid; //if val of [index] is greater than mid, set index to mid
        findMinpos(arr, mid+1, len);
    }

    return index;
}

/////////////////////////////////
/*Question 2b*/
/////////////////////////////////

void swapMinpos(int arr[], int mid, int len) {

    int minindex = findMinpos(arr, mid, len); //Find minindex
    int tmp = arr[minindex]; //Set tmp to arr[minindex]
    arr[minindex] = arr[mid]; //Assigning mid value to minindex
    arr[mid] = tmp; //assigning miniindex to tmp

}

/////////////////////////////////
/*Question 2c*/
/////////////////////////////////

void selSortR(int arr[], int mid, int length){
    static int tmp = 0;
    if (tmp == mid){ //If we are at mid stop
        return;
    }
    else{
        swapMinpos(arr, tmp, mid); //Call out swap function. We want to sort until mid-1 so call mid to be length
        tmp = tmp+1; //Increase tmp by 1 to sort next set
    }
    selSortR(arr, mid, length); //Call itself

}


void main(){
    //Code for Question 1 and Testing purposes.
    int k;
    printf("Enter some value to find the value of corresponding fib sequence: ");
    scanf("%d", &k);
    printf("\n");
    int n = FibIter(k);
    printf("%d \n", n);
    printf("End of Question 1b \n \n \n \n \n");

    //Code for Question 2
    printf("Beginning of Question 2\n");
    int arr[] = {488888, 3, 5, 0, 23, 12124, 6, 7, 2, 1121, 0, 92, 5, 8}; //given array
    int length = (sizeof(arr)/sizeof(int)); //calculating length

    int mid = length / 2; //calculating mid

    swapMinpos(arr,mid,length); //swapping


    selSortR(arr, 14, 14);
    printf("\n \n");
    for(int j = 0; j < length; j++){    //Printing Sorted
        printf("arr[%d] = %d\n", j, arr[j]);
    }

}
