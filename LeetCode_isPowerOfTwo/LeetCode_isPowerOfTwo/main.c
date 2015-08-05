//
//  main.c
//  LeetCode_isPowerOfTwo
//
//  Created by mac on 7/23/15.
//  Copyright (c) 2015 mac. All rights reserved.
//

#include <stdio.h>
int isPowerOfTwo(int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n", isPowerOfTwo(0));
    return 0;
}
int isPowerOfTwo(int n)
{
    int result = n;
    if (result == 0) {
        return 0;
    }
    while (1) {
        if (result % 2 != 0) {//奇数
            if (result == 1) {
                return 1;
            }
            else{
                return 0;
            }
        }
        else
        {
            result /= 2;
        }
    }
}

