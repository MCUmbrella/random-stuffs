#ifndef COMMON_UTIL_H
#define COMMON_UTIL_H

int round(double x)
{
    return x > 0 ? (int)(x+0.5) : (int)(x-0.5);
}

void sortInt(int* nums, int numsLen)
{
    int sorted=0;
    int tmp=0;
    do
        for(int i=0; i!=numsLen-1; i++)
            if(nums[i] <= nums[i+1])
                sorted++;
            else
            {
                tmp=nums[i+1];
                nums[i+1]=nums[i];
                nums[i]=tmp;
                sorted=0;
            }
    while(sorted<=numsLen);
}

#endif
