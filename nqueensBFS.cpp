#include<iostream>
#include<queue>
#include <utility>
using namespace std;
#define QUEENS 4


struct node{
	int queensPlaced;
	pair <int,int> config [QUEENS];
};
queue<node> q;

void initializeBoard(int board[QUEENS][QUEENS]){
	for (int i = 0; i < QUEENS; i++)
	{
		/* code */
		for (int j = 0; j < QUEENS; j++)
		{
			/* code */
			board[i][j] = 0;
		}
	}
}

void fillBoard(int board[QUEENS][QUEENS],node currentNode){

	for (int i = 0; i < (currentNode.queensPlaced); i++)
	{
		board[(currentNode.config)[i].first][(currentNode.config)[i].second] = 2;
	}
	for (int i = 0; i < QUEENS; i++)
	{
		/* code */
		for (int j = 0; j < QUEENS; j++)
		{
			/* code */
			if(board[i][j] == 2)
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}

}

void initilizeNode(node newnode){
	(newnode.queensPlaced) = 0;
	for (int i = 0; i < QUEENS; i++)
	{
		/* code */
		(newnode.config)[i] = {make_pair(-1,-1)};
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

bool isValidBoardNaive(int board[QUEENS][QUEENS],int row,int col){

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

void enqueueChildren(int board[QUEENS][QUEENS],node frontNode){
	fillBoard(board,frontNode);
	for (int i = 0; i < QUEENS; i++)
	{
		/* code */
		//node *newNode = (node *)(malloc(sizeof(node)));
		node * newNode = (node *)(malloc(sizeof(node)));
		newNode->queensPlaced = (frontNode.queensPlaced + 1);
		for (int j = 0; j < (frontNode.queensPlaced); j++)
		{
			(newNode->config)[j] = (frontNode.config)[j];	
		}
		//fillBoard(board,*newNode);
		(newNode->config)[(frontNode.queensPlaced)] = {make_pair(i,frontNode.queensPlaced)};
		if(isValidBoardNaive(board,i,frontNode.queensPlaced))
			q.push(*newNode);



	}
}

bool nqueensBFS(int board[QUEENS][QUEENS],node root){
	q.push(root);
	while(!q.empty()){
		fillBoard(board,q.front());
		//cout<<"Board : "<<endl;
		//printBoard(board);
		if((q.front()).queensPlaced == QUEENS)
		{
			fillBoard(board,q.front());
			//cout<<"Board : "<<endl;
			//printBoard(board);
			return true;
		}
			
		enqueueChildren(board,q.front());
		q.pop();
		//cout<<"Size of queue : "<<q.size()<<endl;

	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	int board[QUEENS][QUEENS];
	initializeBoard(board);
	node * root = (node *)(malloc(sizeof(node)));
	initilizeNode(*root);
	if(nqueensBFS(board,*root))
	{
		cout<<"Solution exists\n";
		printBoard(board);
	}
	
	else
	{
		cout<<"Solution doesn't exist\n";
	}
	return 0;
}