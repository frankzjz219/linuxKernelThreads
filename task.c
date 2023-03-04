#include "task.h"

int seq[SIZEOFMAT];
// int* rets[SIZEOFMAT];
struct task_struct* threadStruct;

int calc(void *input)
{
    unsigned int start, end;
    // printf("enter\n");
    int rowNum = *(int*)input;
    int sum = 0;
    int i = 0;
    // printf("线程%d: \n", rowNum);
    start = jiffies64_to_nsecs(jiffies_64);
    
    for (i = 0; i < SIZEOFVEC; i++)
    {
        sum+=1;
    }
    // printf("sum: %d\n", *sum);
    // printf("exit\n");
    seq[rowNum] = sum;
    end = jiffies64_to_nsecs(jiffies_64);
    // printk("线程%d 计算结果为 %d 计算时间为 %d纳秒\n", rowNum, sum, end-start);
    return 0;
}

void task(void)
{
    // 记录时间的变量
    u64 start,end;
    int i, j;
    for (i = 0; i < SIZEOFMAT; i++)
    {
        seq[i] = i;
    }
    
    start = ktime_get_ns()%1000000;
    for (i = 0; i < SIZEOFMAT; i++)
    {
        threadStruct = kthread_create(calc, (void*)(seq+i), "CalcThread");
        wake_up_process(threadStruct);
    }

    

    end = ktime_get_ns()%1000000;
    printk(KERN_ALERT "并行计算经过的时间为: %d纳秒\n", end-start);

    // int stdSum = 0;
    // for(int i = 0;i<SIZEOFVEC;i++)
    // {
    //     stdSum+=i*i;
    // }
    // printf("\n参照: %d\n", stdSum);
    
    start = ktime_get_ns()%1000000;
    int sumSeq[SIZEOFMAT] = {0};
    for(i = 0;i<SIZEOFMAT; i++)
    {
        for(j = 0;j<SIZEOFVEC; j++)
        {
            sumSeq[i]+=1;
        }
    }

    end = ktime_get_ns()%1000000;
    printk(KERN_ALERT "循环计算经过的时间为: %d纳秒\n", end-start);
}