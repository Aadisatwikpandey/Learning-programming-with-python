//Question 1
// You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

// A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

 

// Example 1:

// Input: accounts = [[1,2,3],[3,2,1]]
// Output: 6
// Explanation:
// 1st customer has wealth = 1 + 2 + 3 = 6
// 2nd customer has wealth = 3 + 2 + 1 = 6
// Both customers are considered the richest with a wealth of 6 each, so return 6.
// Example 2:

// Input: accounts = [[1,5],[7,3],[3,5]]
// Output: 10
// Explanation: 
// 1st customer has wealth = 6
// 2nd customer has wealth = 10 
// 3rd customer has wealth = 8
// The 2nd customer is the richest with a wealth of 10.
// Example 3:

// Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
// Output: 17
 

// Constraints:

// m == accounts.length
// n == accounts[i].length
// 1 <= m, n <= 50
// 1 <= accounts[i][j] <= 100

// solution:

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max;
    int colSize = *accountsColSize;
    for(int i=0;i<accountsSize;i++){
        int sum = 0;
        for(int j=0;j<colSize;j++){
            int val;
            val = accounts[i][j];
            sum+=val;
            if(sum>max){
                max=sum;
            }   
        }
    }

    return max;
}



//question2
// 1351. Count Negative Numbers in a Sorted Matrix
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100

//Solution:
int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<(*gridColSize);j++){
            if(grid[i][j]<0){
                count++;
            }
        }
    }
    return count;
}