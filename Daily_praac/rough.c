
#include <stdio.h>


int maxProfit(int* prices, int pricesSize,int max) {
    max=0;
    for(int i=0;i<pricesSize;i++){
        for(int j=i+1;j<pricesSize;j++){
            int diff=prices[i]-prices[j];
            if (diff>max){
                max=diff;
            }
        }
    }
    return max;
}


int main(){
    int prices[] = {7,1,5,3,6,4};
    int diff = prices[5]-prices[4];
    int diff2 = prices[4] - prices[5];
    printf("%d \n",diff);
    printf("%d \n",diff2);
}