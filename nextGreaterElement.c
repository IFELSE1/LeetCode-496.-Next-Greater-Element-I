#include"stdio.h"
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize,int* returnSize) {
	int i=0,j=0,k=0;
	static int returnNums[1000];
	for (i=0;i<findNumsSize;i++){
		/*首先找出第一个数组的数在第二个数组中的位置*/
		for (j=0;j<numsSize;j++){
			if (findNums[i] == nums[j]) 
				break;
		}
		/*然后搜索此位置的右边是否有比它大的数，有则记下*/
		for (;j<numsSize;j++){
			if (nums[j]>findNums[i]){
				returnNums[i] = nums[j];
				break;
			}
		}
		/*无则赋值-1*/
		if (j==numsSize){
			returnNums[i] = -1;
		}
	}
	* returnSize = findNumsSize;
	return returnNums;
    
}

/**************for local test**************/
int main(void)  
{  
	int nums1[3]={4,3,1};
	int nums2[5]={5,4,1,3,2};
	int returnSize;
	int*  returnNums;
	int i;

	returnNums=nextGreaterElement((int*)nums1,sizeof(nums1)/sizeof(int),(int*)nums2,sizeof(nums2)/sizeof(int),&returnSize);
	printf("[");
	for (i=0;i<(returnSize);i++){
		printf("%d",returnNums[i]);
		if(i!= (returnSize-1)){
			printf(",");
		}
		
	}
	printf("]");
}  














































