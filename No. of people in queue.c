
int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) 
{
    *returnSize = heightsSize;
    int* ans = (int*)malloc(heightsSize * sizeof(int));
    int* stack = (int*)malloc(heightsSize * sizeof(int));
    int top = -1;
    for (int i = heightsSize - 1; i >= 0; i--) 
    {
        int count = 0;
        while (top >= 0 && heights[i] > stack[top]) 
        {
            count++;
            top--;
        }
        if (top >= 0)
        {
            count++;
        }
        ans[i] = count;
        stack[++top] = heights[i];
    }
    free(stack);
    return ans;
}
