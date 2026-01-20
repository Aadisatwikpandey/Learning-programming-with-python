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

