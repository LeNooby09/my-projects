#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int upper;
int lower;
#define anz 100000
int zahl[anz];

void menu()
{
	printf("Enter upper limit ");
	scanf("%d", &upper);
	printf("Enter lower limit ");
	scanf("%d", &lower);
}

int check_zahl(int z, int *zahl, int max)
{
	int retv = 1;
	for(int i = 0; i<max; i++)
	{
		if(z == zahl[i])
		{
			retv = 0;
			break;
		}
	}
	return retv;
}

int main(void)
{
	menu();
	srand(time(0));
	int i = 0;
	while(i<anz)
	{
		int temp = (rand() % (upper - lower +1)) + lower;
		if(check_zahl(temp, zahl, i))
		{
			zahl[i++] = temp;
		}
	}
	for(int i = 0; i<anz; i++)
	{
		printf("zahl: %d\n",zahl[i]);
	}
	return 0;
}
