#include"game.h"


int main(){
	
	int seclet = 0;
	int quit = 0;
	while (!quit){
		Menu();
		scanf("%d", &seclet);
		switch (seclet){
		case 1:
			Game();
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("please input again");
		}
	}

	printf("Bye Bye\n");
	
	system("pause");
	return 0;
}