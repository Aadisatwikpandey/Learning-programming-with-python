#include <stdio.h>

// Solution provided
int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for(int i=0;i<gridSize;i++){
        // Note: In typical LeetCode problems, gridColSize is an array (int*), 
        // but your code treats it as a pointer to a single int value (*gridColSize).
        // This works for rectangular matrices where you pass the address of the column count.
        for(int j=0;j<(*gridColSize);j++){
            if(grid[i][j]<0){
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Example 1
    // grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    int row1[] = {4, 3, 2, -1};
    int row2[] = {3, 2, 1, -1};
    int row3[] = {1, 1, -1, -2};
    int row4[] = {-1, -1, -2, -3};
    
    // Create an array of pointers to simulate int**
    int* grid1[] = {row1, row2, row3, row4};
    int gridSize1 = 4;
    int colSize1 = 4;

    printf("Example 1 Input: [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]\n");
    // Pass address of colSize1 to match the function's expectation of *gridColSize
    printf("Example 1 Output: %d\n\n", countNegatives(grid1, gridSize1, &colSize1));

    // Example 2
    // grid = [[3,2],[1,0]]
    int r1[] = {3, 2};
    int r2[] = {1, 0};
    
    int* grid2[] = {r1, r2};
    int gridSize2 = 2;
    int colSize2 = 2;

    printf("Example 2 Input: [[3,2],[1,0]]\n");
    printf("Example 2 Output: %d\n", countNegatives(grid2, gridSize2, &colSize2));

    return 0;
}
