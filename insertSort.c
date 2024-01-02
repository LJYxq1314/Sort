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

/* 插入排序 */
int insertSort(int *array, int arrayLen)
{
    int posVal = 0;
    for(int begin = 0; begin < arrayLen; begin++)
    {
        posVal = array[begin];
        for(int end = begin; end >= 0; end--)
        {
            if(array[end - 1] > posVal)
            {
                array[end] = array[end - 1];
            }
            else
            {
                array[end] = posVal;
                break;
            }

        }
    }
}


/* 插入排序 */
int insertSort01(int *array, int arrayLen)
{
    int copyNum = 0;
    int cur = 0;
    for(int idx = 1; idx < arrayLen; idx++)
    {
        cur = idx;
        copyNum = array[idx];
        while (cur > 0 && copyNum < array[cur - 1])
        {
            array[cur] = array[cur - 1];
            cur--;
        }   // 退出条件是：cur == 0 && copyNum >= array[cur - 1]
        
        array[cur] = copyNum;
    }
}

int main(int argc, char const *argv[])
{
    int array[BUFFER_SIZE] = {88, 54, 78, 89, 127, 159};
    int arrayLen = sizeof(array) / sizeof(array[0]);


    // insertSort(array, arrayLen);
    insertSort01(array, arrayLen);
    printArray(array, arrayLen);

    printf("\n");
    return 0;
}
