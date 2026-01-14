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