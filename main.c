#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20

//Defining the structure of the gameboard
typedef struct GameBoard
{
    int size;
    char board[MAX][MAX];
}GameBoard;

//Prototypes
void initializeBoard(GameBoard *p, int size);
void printBoard(GameBoard *p);
bool makeMove(GameBoard *p, int row, int col);
bool makeMove1(GameBoard *p, int row1, int col1);
bool isGameOver(GameBoard *p);
int evaluateScore(GameBoard *p);

int main()
{
    //Declare Variables
    int size;
    int row,col,row1,col1;
    GameBoard game;

    //Get The Size Of The Board
    printf("Enter The Size Of The Board: ");
    scanf("%d",&size);

    //Initialize The Board
    initializeBoard(&game,size);

    //Print The Board
    printBoard(&game);


    //Start The Game
    while(1)
    {
        //Enter The Move
         printf("Passer turn : ");
        printf("Enter The Move (Row, Col): ");
        scanf("%d %d",&row,&col);
        row --;
        col --;
        //Check The Move
        if(makeMove(&game,row,col))
        {
            printf("Move Accepted!\n");
        }
        else
        {
            printf("Invalid Move!\n");
            repasserturn(row,col,&game);
        }

        //Enter The Move
        printf("Eater turn : ");
        printf("Enter The Move (Row, Col): ");
        scanf("%d %d",&row1,&col1);
        row1 --;
        col1 --;

        //Check The Move
        if(makeMove1(&game,row1,col1))
        {
            printf("Move Accepted!\n");
        }
        else
        {
            printf("Invalid Move!\n");
            reeaterturn(row1,col1,&game);
        }

        //Print The Board
        printBoard(&game);

        //Check For Game Over
        if(isGameOver(&game))
        {
            printf("Game Over!\n");
            printf("The Score Is: %d\n",evaluateScore(&game));
            break;
        }

    }

    return 0;

}

//Initialize The Board
void initializeBoard(GameBoard *p, int size)
{
    p->size = size;
    int i,j;

    //Fill The Board With Empty Cells
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            p->board[i][j] = '-';
        }
    }
}

//Print The Board
void printBoard(GameBoard *p)
{
    int i,j;

    //Print The Game Board
    for(i=0;i<p->size;i++)
    {
        for(j=0;j<p->size;j++)
        {
            printf("%c ",p->board[i][j]);
        }
        printf("\n");
    }
}


//Make A Move
bool makeMove(GameBoard *p, int row, int col)
{
    //Check The Move
    if(row >= 0 && row < p->size && col >= 0 && col < p->size && p->board[row][col] == '-')
    {
        p->board[row][col] = 'P';
        return true;
    }
    return false;
}
bool makeMove1(GameBoard *p, int row1, int col1)
{
    //Check The Move
    if(row1 >= 0 && row1 < p->size && col1 >= 0 && col1 < p->size)
    {
        p->board[row1][col1] = 'E';
        return true;
    }
    return false;
}

//Check For Game Over
bool isGameOver(GameBoard *p)
{
    int i,j;
    int count = 0;

    //Check For Empty Cells
    for(i=0;i<p->size;i++)
    {
        for(j=0;j<p->size;j++)
        {
            if(p->board[i][j] == '-')
            {
                count++;
            }
        }
    }

    //If All Cells Are Filled
    if(count == 0)
    {
        return true;
    }
    return false;
}
void repasserturn(int row,int col,int game){
printf("Passer turn : ");
        printf("Enter The Move (Row, Col): ");
        scanf("%d %d",&row,&col);
        row --;
        col --;
        //Check The Move
        if(makeMove(&game,row,col))
        {
            printf("Move Accepted!\n");
        }
}
void reeaterturn(int row1,int col1,int game){
printf("Eater turn : ");
        printf("Enter The Move (Row, Col): ");
        scanf("%d %d",&row1,&col1);
        row1 --;
        col1 --;

        //Check The Move
        if(makeMove1(&game,row1,col1))
        {
            printf("Move Accepted!\n");
        }
}
//Evaluate The Score
int evaluateScore(GameBoard *p)
{
    int i,j;
    int score = 0;

    //Calculate The Score
    for(i=0;i<p->size;i++)
    {
        for(j=0;j<p->size;j++)
        {
            if(p->board[i][j] == 'P')
            {
                score++;
            }
            else if(p->board[i][j] == 'E')
            {
                score--;
            }
        }
    }
   return score;
}
