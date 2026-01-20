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


//question3
// 88. Merge Sorted Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

// Constraints:

// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[j] <= 109
 

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?

//Solution
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int j=0;
    for(int i=m;i<(m+n);i++){
        nums1[i]=nums2[j];
        j++;
    }
    // int q=0;
    // for(int p=1;p<(m+n);p++){
    //     if(nums1[p]<nums1[q]){
    //         int temp;
    //         temp = nums1[p];
    //         nums1[p]=nums1[q];
    //         nums1[q]=temp;
    //         // q++;
    //     }
    //     q++;
    // }


    for(int p=0;p<(m+n);p++){
        for(int q=p+1;q<(m+n);q++){
            if(nums1[p]>nums1[q]){
                int temp;
                temp = nums1[p];
                nums1[p]=nums1[q];
                nums1[q]=temp;
            }
        }
    }
}