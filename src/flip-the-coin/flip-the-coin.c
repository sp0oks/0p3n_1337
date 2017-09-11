#include <stdio.h>
#include <stdlib.h>
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
	printf("[ * ] Congratulations! Here's your prize: SCMPv8{4_hundr3d_fl1p_fl0p5}\n");
}

