#include "task.h"

int seq[SIZEOFMAT];
// int* rets[SIZEOFMAT];
struct task_struct* threadStruct;

int calc(void *input)
{
    // printf("enter\n");
    int rowNum = *(int*)input;
    int sum = 0;
    int i = 0;
    // printf("线程%d: \n", rowNum);
    for (i = 0; i < SIZEOFVEC; i++)
    {
        sum+=1;
    }
    // printf("sum: %d\n", *sum);
    // printf("exit\n");
    seq[rowNum] = sum;
    return 0;
}

void task(void)
{
    // 记录时间的变量
    unsigned int start,end;
    int i, j;
    for (i = 0; i < SIZEOFMAT; i++)
    {
        seq[i] = i;
    }

    start = jiffies64_to_msecs(jiffies);
    for (i = 0; i < SIZEOFMAT; i++)
    {
        threadStruct = kthread_create(calc, (void*)(seq+i), "CalcThread");
        wake_up_process(threadStruct);
    }

    

    end = jiffies64_to_msecs(jiffies);
    printk(KERN_ALERT "并行计算经过的时间为: %d\n", end-start);

    // int stdSum = 0;
    // for(int i = 0;i<SIZEOFVEC;i++)
    // {
    //     stdSum+=i*i;
    // }
    // printf("\n参照: %d\n", stdSum);
    
    start = jiffies64_to_msecs(jiffies);
    int sumSeq[SIZEOFMAT] = {0};
    for(i = 0;i<SIZEOFMAT; i++)
    {
        for(j = 0;j<SIZEOFVEC; j++)
        {
            sumSeq[i]+=1;
        }
    }

    end = jiffies64_to_msecs(jiffies);
    printk(KERN_ALERT "循环计算经过的时间为: %d\n", end - start);
}