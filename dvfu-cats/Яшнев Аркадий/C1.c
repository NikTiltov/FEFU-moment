#include <stdio.h>

int check_diagonals(int board[8][8], int pos_x, int pos_y);
int is_in_board(int x, int y);

int main() {
    FILE *fin  = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    int board[8][8] = {0}, x1, y1, x2, y2;

    fscanf(fin, "%d%d%d%d", &x1, &y1, &x2, &y2);
    board[x1 - 1][y1 - 1] = 1;
    board[x2 - 1][y2 - 1] = 1;

    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(check_diagonals(board, i, j)) {
                fprintf(fout, "%d %d", i + 1, j + 1);
                fclose(fout); fclose(fin);
                return 0;
            }
        }
    }

    fprintf(fout, "0");
    fclose(fout); fclose(fin);
}

int is_in_board(int x, int y) {
    return x < 8 && x >= 0 && y < 8 && y >= 0;
}

int check_diagonals(int board[8][8], int pos_x, int pos_y) {
    int counter = 0;
    for(int i = pos_x + 1, j = pos_y + 1; is_in_board(i, j); ++i, ++j) {
        if(board[i][j]) { ++counter; break; }
    }

    for(int i = pos_x - 1, j = pos_y + 1; is_in_board(i, j); --i, ++j) {
        if(board[i][j]) { ++counter; break; }
    }

    for(int i = pos_x + 1, j = pos_y - 1; is_in_board(i, j); ++i, --j) {
        if(board[i][j]) { ++counter; break; }
    }

    for(int i = pos_x - 1, j = pos_y - 1; is_in_board(i, j); --i, --j) {
        if(board[i][j]) { ++counter; break; }
    }

    return counter == 2;
}
