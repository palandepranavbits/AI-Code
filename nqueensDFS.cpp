#include<iostream>
using namespace std;
#define QUEENS 8

void initializeBoard(int board[QUEENS][QUEENS]){
	for (int i = 0; i < QUEENS; ++i)
	{
		/* code */
		for (int j = 0; j < QUEENS; ++j)
		{
			/* code */
			board[i][j] = 0;
		}
	}
}

void printBoard(int board[QUEENS][QUEENS]){
	for (int i = 0; i < QUEENS; i++)
	{
		for (int j= 0; j < QUEENS; j++)
		{
			/* code */
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isValidBoardNaive(int board[QUEENS][QUEENS],int col,int row){
	/*
	for (int i = 0; i < QUEENS; i++)
	{
		
		if(i == col)
			continue;
		if(board[row][i])
			return false;

	}
	for (int i = 0; i < QUEENS; i++)
	{
		
		if(i == row)
			continue;
		if(board[i][col])
			return false;

	}

	int sumdiagtopleft = 0,sumdiagtopright = 0;

	for (int i = 0; i < QUEENS; i++)
	{
		sumdiagtopleft += board[i][i];
	}

	if(sumdiagtopleft > 1)
		return false;

	for (int i = 0; i < QUEENS; i++)
	{
		
		sumdiagtopright +=board[i][QUEENS-1-i];

	}

	if(sumdiagtopright > 1)
		return false;
	return true;
	*/
	int i, j;
 
    
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    
    for (i = row, j = col; j >= 0 && i < QUEENS; i++, j--)
        if (board[i][j])
            return false;
 
    return true;

	
}

bool nqueens_dfs(int board[QUEENS][QUEENS], int latestcol){
	if(latestcol == QUEENS)
		return true;
	for (int i = 0; i < QUEENS; i++)
	{
		/* code */
		if(isValidBoardNaive(board,latestcol,i)){
			//cout<<"Hi"<<endl;
			board[i][latestcol] = 1;
			//printBoard(board);
			if (nqueens_dfs(board,latestcol + 1))
				return true;
			board[i][latestcol] = 0;
		}
		

	}
	return false;
}

int main(int argc, char const *argv[])
{
	int board[QUEENS][QUEENS];
	initializeBoard(board);	
    //printBoard(board);
    if(nqueens_dfs(board,0))
    {
    	cout<<"A solution exists"<<endl;
    	printBoard(board);
    }
    else
    	cout<<"Solution doesn't exist"<<endl;
    	//printBoard(board);
	return 0;
}