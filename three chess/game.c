#include "game.h"




void Menu(){
	printf("######################\n");
	printf("#1.play     2.exit####\n");
	printf("######################\n");
}



void PlyerMove(char board [][ROW], int col, int row){
	int x = 0;
	int y = 0;
	while (1){
		printf("请输入你的位置：");
		scanf("%d""%d", &x, &y);
		if (x<1 || x>3 || y<1 || y>3){
			printf("你输入的坐标有误，请重新输入\n");
			continue;
		}
		else if (board[x - 1][y - 1] != ' '){
			printf("你输入的位置已经被占用\n");
			continue;
		}
		else{
			board[x - 1][y - 1] = P_COLOR;
			break;
		}
	}
	

}



char Judge(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' '){
			return board[i][0];
		}
	}
	for (int i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!=' '){
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!=' '){
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0]!=' '){
		return board[2][0];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return NEXT;
			}
		}
	}
	return DRAW;

}


void ComputerMove(char board[][COL], int col, int row){

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = C_COLOR;
			break;
		}
	}
}


void ShowBoard(char board[][COL], int col, int row){
	printf("   | 1 | 2 | 3 |\n");
	printf("----------------\n");
	for (int i = 0; i < ROW; i++){
		printf(" %d | ", i + 1);
		for (int j = 0; j < COL; j++)
		{
			printf("%c | ", board[i][j]);
		}
		printf("\n----------------\n");
	}
}


void Game(){
	

	srand((unsigned long)time(NULL));
	char board [ROW] [COL];
	memset(board, ' ', sizeof(board));
	char result = 'x';
	do{
		ShowBoard(board, ROW, COL);
		PlyerMove(board,ROW,COL);
		Judge(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != NEXT){
			break;
		}		
		ComputerMove(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != NEXT){
			break;
		}
	} while (1);
	if (P_COLOR == result)
	{
		printf("你赢了！\n");
	}
	else if (C_COLOR == result)
	{
		printf("你输了！\n");
	}
	else
	{
		printf("和棋！\n");
	}

	ShowBoard(board, ROW, COL);

}