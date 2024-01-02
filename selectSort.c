#include <stdio.h>

#define BUFFER_SIZE 6

/* 选择排序：相较于冒泡排序，减少了交换次数 */
int selectSort(int *array, int arrayLen)
{
    int minVal = 0;
    int minIndex = 0;
    for(int pos = 0; pos < arrayLen; pos++)
    {
        minVal = array[pos];
        for(int begin = pos + 1; begin < arrayLen; begin++)
        {
            /* 遍历到的元素比最小值要小，就更新元素 */
            if(minVal > array[begin])
            {
                minVal = array[begin];
                minIndex = begin;
            }
        }

        if(array[pos] > minVal)
        {
            int temp = array[pos];
            array[pos] = minVal;
            array[minIndex] = temp;
        }
    }
}

/*数组做函数参数会被弱化为指针 */
/* 打印函数 */
int printArray(int *array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d ", idx, array[idx]);
    }
}

int main(int argc, char const *argv[])
{
    int array[BUFFER_SIZE] = {88, 54, 78, 89, 127, 159};
    int arrayLen = sizeof(array) / sizeof(array[0]);

    selectSort(array, arrayLen);

    printArray(array, arrayLen);

    printf("\n");
    return 0;
}
