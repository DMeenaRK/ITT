#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool compare(int* nums1, int size1, int index1, int* nums2, int size2, int index2) 
{
    while (index1 < size1 && index2 < size2) 
    {
        if (nums1[index1] < nums2[index2]) return false;
        if (nums1[index1] > nums2[index2]) return true;
        index1++;
        index2++;
    }
    return index1 < size1;
}
void maxSubsequence(int* nums, int numsSize, int k, int* result) 
{
    int top = -1;
    int dropRemaining = numsSize - k;
    for (int i = 0; i < numsSize; i++) 
    {
        while (top >= 0 && result[top] < nums[i] && dropRemaining > 0) 
        {
            top--;
            dropRemaining--;
        }
        if (top < k - 1) 
        {
            result[++top] = nums[i];
        } 
        else 
        {
            dropRemaining--;
        }
    }
}
void merge(int* sub1, int size1, int* sub2, int size2, int* merged) 
{
    int i = 0, j = 0, r = 0;
    while (i < size1 || j < size2) 
    {
        if (compare(sub1, size1, i, sub2, size2, j)) 
        {
            merged[r++] = sub1[i++];
        } 
        else 
        {
            merged[r++] = sub2[j++];
        }
    }
}
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) 
{
    *returnSize = k;
    int* ans = (int*)calloc(k, sizeof(int));
    int* sub1 = (int*)malloc(k * sizeof(int));
    int* sub2 = (int*)malloc(k * sizeof(int));
    int* tempMerged = (int*)malloc(k * sizeof(int));
    int start = (k - nums2Size > 0) ? k - nums2Size : 0;
    int end = (nums1Size < k) ? nums1Size : k;
    for (int i = start; i <= end; i++) 
    {
        int j = k - i;
        maxSubsequence(nums1, nums1Size, i, sub1);
        maxSubsequence(nums2, nums2Size, j, sub2);
        merge(sub1, i, sub2, j, tempMerged);
        if (compare(tempMerged, k, 0, ans, k, 0)) 
        {
            memcpy(ans, tempMerged, k * sizeof(int));
        }
    }
    free(sub1);
    free(sub2);
    free(tempMerged);
    return ans;
}
