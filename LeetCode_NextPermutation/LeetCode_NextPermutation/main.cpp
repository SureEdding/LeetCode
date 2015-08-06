
#include <algorithm>
#include <iostream>

using namespace std;

void nextPermutation(int* nums, int numsSize);
void change(int *, int *);
void revert(int *a, int sizeOfArray);
int arr1[5] = {5,2,3,4,1};
int arr2[5] = {5,2,4,1,3};
int main()
{
//    int a[5];
//    a[0]=1;a[1]=2;a[2]=3;a[3]=4;a[4]=5;
//    do
//    {
//        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
//    } while (next_permutation(a,a+5));
    
    nextPermutation(arr1, 5);
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize == 1) {
        return;
    }
    int low = 0, high = 0;
    int i = 0;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[numsSize - 1 - i - 1] < nums[numsSize - 1 - i]) {
            low = numsSize - 1 - i - 1;
            high = numsSize - 1 - i;
            break;
        }
    }
    if (i == numsSize - 1) {
        revert(nums, numsSize);
        return;
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[numsSize - 1 - i] > nums[low]) {
            change(&nums[numsSize - 1 - i], &nums[low]);
            revert(&nums[high], numsSize - high);
            return;
        }
    }
    
}
void revert(int *a, int sizeOfArray)
{
    if (sizeOfArray == 1) {
        return;
    }
    int i = 0;
    for (i = 0; i < sizeOfArray/2; i++) {
        change(&a[i], &a[sizeOfArray - 1 - i]);
    }
}
void change(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
