#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int flip(int* pts);
void printflg();

int main(){
	char key;
	int coins = 0;
	int round;
	time_t t;	

	srand((unsigned) time(&t));

	printf("[ * ] Welcome to the flipping coin game!\n");
	printf("[ * ] To win, you must flip heads 100 times!\n");
	printf("[ * ] To flip the coin, just press enter.\n");
	
	key = getchar();
	if(key == '\n')
		coins += 1;
	printf("[ * ] Nice, you flipped heads!\n");
	printf("[ * ] You now have %d points!\n", coins);

	while(coins < 100){
		key = getchar();
		if (key == '\n')
			round =	flip(&coins);
		if (round != 1)
			exit(1);
		fflush(stdin);
	}

	if (coins == 100)
		printflg();

	return 0;
}

int flip(int* pts){
	int coin = rand() % 2;
	if (coin){
		*pts += 1;
		printf("[ * ] Nice, you flipped heads!\n");
		printf("[ * ] You now have %d points!\n", *pts);
		return 1;
	}
	else{
		printf("[ * ] Oh no, you flipped tails!\n");
		return 0;
	}
}

void printflg(){
	int i;
	int size = 32;	
	unsigned char* hex[64] = {0x53, 0x43, 0x4d, 0x50, 0x76, 0x38, 0x7b, 0x5f, 0x41, 0x5f, 0x68, 0x75, 0x6e, 0x64, 0x72, 0x33, 0x64, 0x5f, 0x66, 0x6c, 0x31, 0x70, 0x5f, 0x66, 0x6c, 0x30, 0x70, 0x35, 0x5f, 0x7d};

	printf("[ * ] Congratulations! Here's your prize:");
	for (i = 0; i < size; i++) printf("%c",hex[i]);
	printf("\n");
}

