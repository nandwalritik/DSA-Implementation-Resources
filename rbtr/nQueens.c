#include<stdio.h>
#include<stdlib.h>
#define N 5

void printSolution(int board[N][N]) 
{ 
    static int k = 1; 
    printf("%d-\n",k++); 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
    printf("\n"); 
} 
int isSafe(int board[N][N],int row,int col){
	int i,j;

	for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return 0; 
  
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return 0; 
  
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return 0; 

    return 1;    
  

}
int solveNQUtil(int board[N][N], int col) 
{ 
    /* base case: If all queens are placed 
    then return 1 */
    if (col == N) 
    { 
        printSolution(board); 
        return 1; 
    } 
  
    /* Consider this column and try placing 
    this queen in all rows one by one */
    int res = 0; 
    for (int i = 0; i < N; i++) 
    { 
        /* Check if queen can be placed on 
        board[i][col] */
        if ( isSafe(board, i, col) ) 
        { 
            /* Place this queen in board[i][col] */
            board[i][col] = 1; 
  
            // Make result 1 if any placement 
            // is possible 
            res = solveNQUtil(board, col + 1) || res; 
  
            /* If placing queen in board[i][col] 
            doesn't lead to a solution, then 
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK 
        } 
    } 
  
    /* If queen can not be place in any row in 
        this column col then return 0 */
    return res; 
} 

void solveNQ() 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(board, 0) == 0) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 
  
    return ; 
} 

int main(){

	solveNQ();
	return 0;
}
