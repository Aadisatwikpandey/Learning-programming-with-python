//tried to solve the remove duplicates problem, and Got out of bound issue each time.the solution I have proposed is:
int removeDuplicates(int* nums, int numsSize) {
    int res[numsSize];
    int count=1;
    for(int i=1;i<numsSize-1;i++){
        if(nums[i]!=nums[i-1]){
            res[i]=nums[i-1];
            count++;
        }
    }
    for(int k=0;k<numsSize;k++){
        nums[k]=res[k];
        
    }
return count;
}



//solved this problem:

// 35. Search Insert Position
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104


//solution:
int searchInsert(int* nums, int numsSize, int target) {
    int op = -1;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == target){
            op = i;
        }
        // else{
        //     if((nums[i-1]<target) && nums[i]>target){
        //         op = i;
        //     }
        // }
    }
    if(nums[0]>target){
                op = 0;
            }
    else if(nums[numsSize-1]<target){
                    op = numsSize;
                }
    
    else{
        for(int j=1;j<numsSize;j++){
            if(op == -1){
                
                if((nums[j-1]<target) && nums[j]>target){
                    op = j;
                }
                
            }
        }
    }
    return op;
}