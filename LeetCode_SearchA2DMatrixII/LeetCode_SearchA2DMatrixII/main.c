//
//  main.c
//  LeetCode_SearchA2DMatrixII
//
//  Created by mac on 8/6/15.
//  Copyright © 2015 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target);

int main(int argc, const char * argv[]) {
    // insert code here...
    int **m;
    m = (int **)malloc(2 * sizeof(int *));
    m[0] = (int *)malloc(sizeof(int));
    m[1] = (int *)malloc(sizeof(int));
    m[0][0] =-5;
    m[0][1] = 3;
    printf("%d\n",searchMatrix(m, 1, 1, 2));

    return 0;
}
int searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    
    int i = 0, j = matrixColSize - 1;
    
    while (1) {
        if (j < 0 || i >= matrixRowSize) {
            break;
        }
        if (matrix[i][j] > target)
        {
            //此列不会存在target, j++
            j--;
            continue;
        }
        if (matrix[i][j] < target)
        {
            i++;
            continue;
        }
        if (matrix[i][j] == target) {
            return 1;
        }
    }
    
    
    return 0;
}