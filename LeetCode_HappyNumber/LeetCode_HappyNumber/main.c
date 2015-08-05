//
//  main.c
//  LeetCode_HappyNumber
//
//  Created by mac on 7/23/15.
//  Copyright (c) 2015 mac. All rights reserved.
//

#include <stdio.h>

int isHappy(int n);
int divideToDifferent(int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", isHappy(1));
    
    return 0;
}
static int hashSum[100000000] = {0};
int isHappy(int n)
{
    int count = 0, i = 0;
    int numbers[20] = {0};
    hashSum[n] = 1;
    if (n == 1) {
        return 1;
    }
    while (1)
    {
        numbers[count++] = (n % 10);
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    int sum = 0;
    for (i = 0; i < 20; i++) {
        sum += numbers[i] * numbers[i];
    }
    if (hashSum[sum] == 1) {
        return 0;
    }
    else
    {
        return isHappy(sum);
    }
    return 0;
}
