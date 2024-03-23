class Solution {
public:

    bool helper(int i, int j, int n, int m, int k, vector<vector<char>> &board, string &word){

        if(k >= word.size()){  // base case 1
            return true;
        }

        if(i < 0 or i > n-1 or j < 0 or j > m-1 or word[k] != board[i][j]){   // base case 2
            return false;
        }

        board[i][j]  = '.';
        int x[4] = {0, 0, -1, 1};
        int y[4] = {-1, 1, 0, 0};
        bool temp = false;

        for(int idx = 0; idx < 4; idx++){
            temp = temp or helper(i + x[idx], j + y[idx], n, m, k + 1, board, word);
        }

        board[i][j] = word[k];

        return temp;

    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(word[0] == board[i][j]){
                    if( helper(i, j, n, m, 0, board, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};