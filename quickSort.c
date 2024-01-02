#include <stdio.h>

#define BUFFER_SIZE 6

/*数组做函数参数会被弱化为指针 */
/* 打印函数 */
int printArray(int *array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d ", idx, array[idx]);
    }
}

/* 快速排序 */
int quickSort(int *array, int start, int end)
{
    int ret =0;
    int left = start;
    int right = end;
    if(start >= end)
    {
        return ret;
    }

    int copyNum = array[start];
    
    while (start < end)
    {
        while (start < end)
        {
            if(copyNum <= array[end])
            {
                end--;
            }
            else
            {
                array[start] = array[end];
                start++;
                break;
            }
        }

        while (start < end)
        {
            if(copyNum >= array[end])
            {
                start++;
            }
            else
            {
                array[end] = array[start];
                end--;
            }
        }
        
    }   //退出循环的条件：start = end
    array[start] = copyNum;
    quickSort(array, left, start - 1);
    quickSort(array, start + 1, right);

    return ret;
}

int main(int argc, char const *argv[])
{
    int array[BUFFER_SIZE] = {88, 54, 78, 160, 127, 159};
    int arrayLen = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, arrayLen - 1);

    printArray(array, arrayLen);

    printf("\n");
    return 0;
}