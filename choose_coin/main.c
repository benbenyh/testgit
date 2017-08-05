#include <stdio.h>

#define COIN_NUM 5

int choose_coin(int *coin, int coin_num)
{
    int i;
    int choice;

    if(coin_num < 4)
    {
        if(*coin > *(coin + coin_num - 1))
	{
	    choice = *coin;
	    
	    for(i = 0; i < coin_num - 1; i++)
	    {
	        *(coin + i) = *(coin + i + 1);
	    }
	}
	else
	{
	    choice = *(coin + coin_num - 1);
	}

	return choice;
    }

    if((*coin - *(coin + 1)) 
    > (*(coin + coin_num - 1) - *(coin + coin_num - 2)))
    {
        choice = *coin;
	
	for(i = 0; i < coin_num - 1; i++)
	{
	    *(coin + i) = *(coin + i + 1);
	}

	return choice;
    }
    else
    {
        choice = *(coin + coin_num -1);

	return choice;
    }
}

int main()
{
    int i;
    int A = 0;
    int B = 0;
    int coin_num = COIN_NUM;
    int coin[COIN_NUM];

    for(i = 0; i < COIN_NUM; i++)
    {
        scanf("%d",&coin[i]);
    }
    
    for(i = 0; i < COIN_NUM; i++)
    {
        if(i % 2 == 0)
	{
	    A += choose_coin(coin, coin_num);
	}
	else
	{
	    B += choose_coin(coin, coin_num);
	}

	coin_num--;
    }

    printf("A = %d\n", A);
    printf("B = %d\n", B);


    return 0;

}
