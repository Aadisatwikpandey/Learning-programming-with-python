class Solution:
    def pattern(self, n):
        for i in range(n,0,-1):
            for j in range(0,n-i):
                print(" ",end = "")
            for j in range(0,i*2-1):
                print("*", end="")
            # for j in range(0,n-i):
            #     print(" ",end = "")

            print()







if __name__ == "__main__":
    # Create an instance of the Solution class
    sol = Solution()
    # Function to call the pattern 4
    sol.pattern(4)