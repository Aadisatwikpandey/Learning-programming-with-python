// // solved this problem

// 941. Valid Mountain Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers arr, return true if and only if it is a valid mountain array.

// Recall that arr is a mountain array if and only if:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

// Example 1:

// Input: arr = [2,1]
// Output: false
// Example 2:

// Input: arr = [3,5,5]
// Output: false
// Example 3:

// Input: arr = [0,3,2,1]
// Output: true
 

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104


//solution



bool validMountainArray(int* arr, int arrSize){
    
    if (arrSize < 3) return false;

    int i = 0;

    while (i + 1 < arrSize && arr[i] < arr[i + 1]) {
        i++;
    }

    if (i == 0 || i == arrSize - 1) {
        return false;
    }

    while (i + 1 < arrSize && arr[i] > arr[i + 1]) {
        i++;
    }

    return i == arrSize - 1;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // int valley=0;
    // bool increasing = false;
    // bool decreasing = false;

    // // for(int i=0;i<arrSize-1;i++){
    // //     diff = arr[i+1]-arr[i];

    // // }

    // if(arrSize<3){
    //     return false;
    // }
    // else{
    //     for(int i=0;i<arrSize-1;i++){
    //         int diff = arr[i+1] - arr[i];
    //         if(diff<0){
    //             valley = i+1;
    //             break;
    //         }
    //     }
    //     for(int i=0;i<valley-1;i++){
    //         int diff = arr[i+1]-arr[i];
    //         if(diff == 0){
    //             increasing = false;
    //             break;
    //         }
    //         else if(diff<1){
    //             increasing =false;
    //             break;
    //         }
    //         else{
    //             increasing = true;
    //         }
    //     }
    //     for(int i=valley;i<arrSize-1;i++){
    //         int diff = arr[i+1]-arr[i];

    //         if(diff == 0){
    //             decreasing = false;
    //             break;
    //         }

    //         else if(diff>0){
    //             decreasing =false;
    //             break;
    //         }
    //         else{
    //             decreasing = true;
    //         }
    //     }
    // }
    // return (increasing && decreasing);
}