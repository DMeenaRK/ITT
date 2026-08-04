int* resultArray(int* nums, int numsSize, int* returnSize) {
    int *arr1=(int*)malloc(numsSize*sizeof(int));
    int *arr2=(int*)malloc(numsSize*sizeof(int));
    int *c=(int*)malloc(numsSize*sizeof(int));
    int ind=0,arr1S=0,arr2S=0;
        arr1[arr1S++]=nums[0];
        arr2[arr2S++]=nums[1];
    for(int i=2;i<numsSize;i++){
        if(arr1[arr1S-1]>arr2[arr2S-1]){
            arr1[arr1S++]=nums[i];
        }else{
            arr2[arr2S++]=nums[i];
        }
    }
    for(int i=0;i<arr1S;i++){
        c[ind++]=arr1[i];
    }
    for(int i=0;i<arr2S;i++){
        c[ind++]=arr2[i];
    }
    free(arr1);
    free(arr2);
    *returnSize=numsSize;
    return c;
}