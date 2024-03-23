
class Solution {
public:
    bool CanPlace(vector<vector<char>>& board, int i, int j, int n, int num) {
        // Check in row and column
        for (int x=0;x<n;x++)
        {
            if(board[i][x]==num || board[x][j]==num) 
            {
                return false;
            }
        }

        // Check in a grid
        int rn=sqrt(n);
        int sx=(i/rn)*rn;
        int sy=(j/rn)*rn;

        for (int x=sx;x<sx+rn;x++)
        {
            for (int y=sy;y<sy+rn;y++)
            {
                if (board[x][y]==num) 
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool Sudoku(vector<vector<char>>& board, int i, int j, int n) {
        // Base case
        if (i==n)
        {
            return true;
        }

        // Check for row end -> next row
        if (j==n) 
        {
            return Sudoku(board,i+1,0,n);
        }

        // Check for empty cell
        if (board[i][j]!='.') 
        {
            return Sudoku(board,i,j+1,n);
        }

        // Place the num in empty cell ->rec case
        for (char num='1';num<='9';num++)
        {
            if (CanPlace(board,i,j,n,num)) 
            {
                board[i][j]=num;  //assuming
                if (Sudoku(board,i,j+1,n)) 
                {
                    return true;
                }
            }
        }

        // Else backtrack
        board[i][j]='.';
        return false;
    }

    bool solveSudoku(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        
        if(rows!=9 || cols!=9)
        {
            return false; //board does not have 9 rows9 columns
        }
        return Sudoku(board,0,0,9);
    }
};
