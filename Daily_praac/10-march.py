class Solution:
    # Function to print "Hello world" string
    def func(self):
        print("Hello World")
        return
    def pattern4(self, n):
        for i in range(1,n+1):
            for j in range(0,i):
                print(i,end = "")
            print(end="\n")


if __name__ == "__main__":
    # Create an instance of the Solution class
    sol = Solution()
    # Function to call the pattern 4
    sol.pattern4(4)