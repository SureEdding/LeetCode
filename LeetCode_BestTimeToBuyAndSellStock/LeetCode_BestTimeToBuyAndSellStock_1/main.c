//
//  main.c
//  LeetCode_BestTimeToBuyAndSellStock_1
//
//  Created by mac on 8/13/15.
//  Copyright © 2015 mac. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
int maxProfit(int* prices, int pricesSize) {
    int i = 0;
    int low = 10000;
    int profit = 0;
    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    }
    for(i = 0; i < pricesSize; i++){
        if(prices[i] < low)
        {
            low = prices[i];
        }
        else if(prices[i] - low > profit)
        {
            profit = prices[i] - low;
        }
    }
    return profit;
}
