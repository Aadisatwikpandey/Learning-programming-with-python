int removeElement(int* nums, int numsSize, int val) {
    
    int j=0;
    int size;
    int res[numsSize];
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            res[j]=nums[i];
            j++;
        }
    }
    // int elem_size=sizeof(res[0]);
    // int total_size=sizeof(res);
    size=j;
    for(int k=0;k<size;k++){
        nums[k]=res[k];
    }
    return size;
}
//solved this and it is passing the first two use cases, but failing the rest of them.

//after this I moved to another another question: find numbers with even numbers of digits
int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for (int i=0;i<numsSize;i++){
        if(10<=nums[i] && nums[i]<=99){
            count++;
        }
        else if(1000<=nums[i] && nums[i]<=9999){
            count++;
        }
        else if(nums[i]==100000){
            count++;
        }
    }
    return count;
}

//the question is like this:
// 1295. Find Numbers with Even Number of Digits
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums of integers, return how many of them contain an even number of digits.

 

// Example 1:

// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.
// Example 2:

// Input: nums = [555,901,482,1771]
// Output: 1 
// Explanation: 
// Only 1771 contains an even number of digits.
 

// Constraints:

// 1 <= nums.length <= 500
// 1 <= nums[i] <= 105