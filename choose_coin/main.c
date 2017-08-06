/***************************************************************************
有n枚硬币按照0到n-1对它们进行编号，其中编号为i的硬币面额为vi，两个人轮流从剩下硬币中取出一枚硬币归自己所有，但每次取硬币的时候只能取剩下的硬币中编号最小的硬币或者编号最大的硬币，在两个都采用最优策略的情况下，作为先取硬币的你请编写程序计算出你能获得硬币总面额的最大值？
****************************************************************************/
#include <stdio.h>

#define COIN_NUM 10

int Max_Value(int a[], int n)
{
    int i;
    int max_value_a = 0;
    int max_value_b = 0;

    if(n % 2 == 0)
    {
        for(i = 0; i < n; i++)
	{
	    if(i % 2 == 0)
	    {
	        max_value_a += a[i];
	    }
	    else
	    {
	        max_value_b += a[i];
	    }
	}

	return max_value_a > max_value_b ? max_value_a : max_value_b;
    }
    else
    {
        if(a[0] > a[n - 1])
	{
	    for(i = 1; i < n; i++)
	    {
	        if(i % 2 == 0)
		{
		    max_value_a += a[i];
		}
		else
		{
		    max_value_b += a[i];
		}
	    }

	    return max_value_a < max_value_b ?
	           max_value_a + a[0] : max_value_b + a[0];
	}
	else
	{
	    for(i = 0; i < n - 1; i++)
	    {
	        if(i % 2 == 0)
		{
		    max_value_a += a[i];
		}
		else
		{
		    max_value_b += a[i];
		}
	    }

	    return max_value_a < max_value_b ?
	           max_value_a + a[n - 1] : max_value_b + a[n - 1];
	}
    }
}

int main()
{
    int i;
    int coin_num = COIN_NUM;
    int coin[COIN_NUM];

    for(i = 0; i < COIN_NUM; i++)
    {
        scanf("%d",&coin[i]);
    }
    
    int A = Max_Value(coin,coin_num);

    printf("A = %d\n", A);

    return 0;

}
