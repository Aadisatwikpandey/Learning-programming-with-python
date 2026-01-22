void moveZeroes(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
       for(int j=1;j<numsSize;j++){
            if(nums[i]==0 && nums[j]!=0 && i<j){
                    nums[i]=nums[j];
                    nums[j]=0;
            }
        }
    }
}


// for(int j=1;j<numsSize;j++){
//                 if(nums[j]!=0){
//                     int temp = nums[i];
//                     nums[i]=nums[j];
//                     nums[j]=temp;
//                     j=i;
//                     break;
//                 }
//             }