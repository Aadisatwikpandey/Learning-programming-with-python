// problem 1464. Maximum Product of Two Elements in an Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

// Example 1:

// Input: nums = [3,4,5,2]
// Output: 12 
// Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
// Example 2:

// Input: nums = [1,5,4,5]
// Output: 16
// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
// Example 3:

// Input: nums = [3,7]
// Output: 12
 

// Constraints:

// 2 <= nums.length <= 500
// 1 <= nums[i] <= 10^3


//solution:

int maxProduct(int* nums, int numsSize) {
    int maxi,maxj;
    int max;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            int prod=nums[i]*nums[j];
            if(max<prod){
                max=prod;
                maxi=nums[i];
                maxj=nums[j];
            }
        }
    }
    int result = (maxi-1)*(maxj-1);
    return result;
}



//question2: 
// 1346. Check If N and Its Double Exist
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array arr of integers, check if there exist two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]
 

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
// Example 2:

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions.
 

// Constraints:

// 2 <= arr.length <= 500
// -103 <= arr[i] <= 103



//solution:
bool checkIfExist(int* arr, int arrSize) {
    for(int i=0;i<arrSize;i++){
        for (int j=0;j<arrSize;j++){
            if(i!=j && arr[i] == 2*arr[j]){
                return true;
            }
        }
    }
    return false;
}