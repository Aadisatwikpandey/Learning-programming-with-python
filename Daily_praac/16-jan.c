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


//question3:1491. Average Salary Excluding the Minimum and Maximum Salary
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
// Example 2:

// Input: salary = [1000,2000,3000]
// Output: 2000.00000
// Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
// Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 

// Constraints:

// 3 <= salary.length <= 100
// 1000 <= salary[i] <= 106
// All the integers of salary are unique


//solution
double average(int* salary, int salarySize) {
    double sum1=0,sum2=0;
    
    int min = salary[0];
    int max=salary[0];
    int count=0;
    for(int i=0;i<salarySize;i++){
        if(salary[i]>max){
            max=salary[i];
        }
    }
    for(int j=0;j<salarySize;j++){
        if(salary[j]<min){
            min=salary[j];
        }
    }
    // for(int i=0;i<salarySize;i++){
    //     if(salary[i]!=min || salary[i]!= max){
    //         sum1+=salary[i];
    //         count++;
    //     }
    // }
    for(int k=0;k<salarySize;k++){
        sum1 += salary[k];
        count++;
    }
    count=count-2;
    sum2= max+min;
    sum1=sum1-sum2;
    double result = sum1/count;
    return result;

}
//learning:
//Learnt about the use of float double and int size