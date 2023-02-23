#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int A;
int D;
int zahl[100000000] ={};
int zeilen = 0;
int import(void)
{
	FILE *fb;
	char buffer[100];
	int i = 0;
	fb = fopen("numbers.txt", "r");
	if (fb == NULL)
	{
		printf("Couldn't open numbers.txt.\n");
		exit(1);
	}

	while (fscanf(fb,"zahl: %d\n",&zahl[i]) != -1)
	{
		//printf("%d\n", zahl[i]);
		i++; 
		zeilen = i;
	}

	fclose(fb);
	return 0;
}

void show_num(int *zahl, int anzahl)
{
	for(int i=0;i<anzahl;i++)
	printf("%d ",zahl[i]);
	printf("\n\n");
}

void progress_bar(float progress, int width)
{
    int num_blocks = (int) (progress / (100.0 / width));
    int i;

    printf("[");
    for (i = 0; i < num_blocks; i++)
		{
      printf("=");
    }
    for (; i < width; i++)
		{
      printf(" ");
    }
    printf("] %.1f%%\r", progress);
    fflush(stdout);
}

void bubble_sort(int *zahl, int anzahl)
{
	int y,x;
	for(y=0;y<anzahl;y++)
	{
		int swap = 0;
		for(x=0;x<(anzahl-1-y);x++)
		{
			if(zahl[x]>zahl[x+1])
			{
				int temp = zahl[x];
				zahl[x] = zahl[x+1];
				zahl[x+1] = temp;
				swap = 1;
			}
		}
		progress_bar((float) y / (anzahl - 1) * 100, 20);
		if(swap == 0)
		{
			break;
		}
	}
	printf("\n");
}

void quick_sort()
{
	
}

void menu_debug()
{
	int MD = 1;
	int choiceD;
	while (MD)
	{
  	printf("---DEBUG---\n");
		printf("1. Show numbers Y\n");
		printf("2. Show numbers N\n");
		printf("3. Go Up\n");
		printf("Enter your choice: ");

		scanf("%d", &choiceD);

		switch (choiceD)
		{
			case 1:
				D = 1;
				printf("Set 'Zeige Zahlen' to Y\n");
				break;
			case 2:
				D = 0;
				printf("Set 'Zeige Zahlen' to N\n");
				break;
			case 3:
				MD = 0;
			default:
  			printf("Invalid choice. Please try again.\n");
  			break;
		}
	}
}

void menu_algo()
{
	int MA = 1;
	int choiceA;
	while (MA)
	{
  	printf("---ALGOS---\n");
		printf("1. Bubble sort\n");
		printf("2. Go Up\n");
		printf("Enter your choice: ");

		scanf("%d", &choiceA);

		switch (choiceA)
		{
			case 1:
				A = 1;
				printf("Selected Algorythm %d\n",A);
				break;
			case 2:
				MA = 0;
				break;
		}
	}
}

void call_zahlen()
{
	if( D == 1)
	{
		show_num(zahl,zeilen);
	}
}

void call_algo()
{
	if (A == 0)
	{
		printf("No Algorythm selected\n");
	}
	if (A == 1)
	{
		bubble_sort(zahl,zeilen);
	}
}

int main()
{
	import();
	int choice;
	int M = 1;
  while (M)
	{
    printf("Options\n");
    printf("1. Debug\n");
    printf("2. Algos\n");
    printf("3. Run\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
		{
      case 1:
				menu_debug();
				break;
      case 2:
				menu_algo();
        break;
      case 3:
				call_zahlen();
				call_algo();
				call_zahlen();
				M = 0;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
      break;
    }
  }
}
//t