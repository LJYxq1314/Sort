#include <stdio.h>

#define BUFFER_SIZE 6

/* 交换函数 */
int swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
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

/* 冒泡排序 */
void bubbleSort(int *array, int arraySize)
{
    for(int end = arraySize; end > 0; end--)
    {
        for(int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的小 交换 */
            if(array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
            }
        }
    }
}

/* 冒泡排序---优化1 */
void bubbleSort01(int *array, int arraySize)
{
    int sorted = 1;
    for(int end = arraySize; end > 0; end--)
    {
        /* 已经排好序的标志 */
        sorted = 1;
        for(int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的小 交换 */
            if(array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /* 数据是没有排好序的 */
                sorted = 0;
            }
        }
        if(sorted == 1)
        {
            break;
        }
    }
}

/* 冒泡排序---优化2 */
void bubbleSort02(int *array, int arraySize)
{

    int sortedIndex  = 0;
    for(int end = arraySize; end > 0; end--)
    {
        /* 已经排好序的索引 */
        sortedIndex = 1;
        for(int begin = 1; begin < end; begin++)
        {
            /* 后面的数 比 前面的小 交换 */
            if(array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /* 数据是没有排好序的 */
                sortedIndex = begin;
            }
        }
        /* 更新 */
        end = sortedIndex;
    }
}

int main(int argc, char const *argv[])
{
    int array[BUFFER_SIZE] = {88, 54, 78, 89, 127, 159};
    int arrayLen = sizeof(array) / sizeof(array[0]);
    
    // bubbleSort(array, arrayLen);
    // bubbleSort01(array, arrayLen);
    bubbleSort02(array, arrayLen);

    printArray(array, arrayLen);

    printf("\n");
    return 0;
}
