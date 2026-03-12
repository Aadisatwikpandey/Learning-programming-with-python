class Solution:
    def pattern(self, n):
        for i in range(n,0,-1):
            for j in range(i,0,-1):
                print("*",end = " ")
            print(end="\n")







if __name__ == "__main__":
    # Create an instance of the Solution class
    sol = Solution()
    # Function to call the pattern 4
    sol.pattern(4)