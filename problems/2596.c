#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


int check1Grid(int **grid, int nrows, int ncols, int i, int j){
    int lFlag = 0, rFlag = 0;
    if (i-1 >= 0 && j - 2 >= 0){
        if (grid[i-1][j-2] - grid[i][j] == 1) rFlag = 1;
        if (grid[i-1][j-2] - grid[i][j] == -1) lFlag = 1;
    }
    if (i-2 >= 0 && j - 1 >= 0){
        if (grid[i-2][j-1] - grid[i][j] == 1) rFlag = 1;
        if (grid[i-2][j-1] - grid[i][j] == -1) lFlag = 1;
    }
    if (i-2 >= 0 && j + 1 < ncols){
        if (grid[i-2][j+1] - grid[i][j] == 1) rFlag = 1;
        if (grid[i-2][j+1] - grid[i][j] == -1) lFlag = 1;
    }
    if (i-1 >= 0 && j + 2 < ncols){
        if (grid[i-1][j+2] - grid[i][j] == 1) rFlag = 1;
        if (grid[i-1][j+2] - grid[i][j] == -1) lFlag = 1;
    }
    // printf("val = %d, rlfag = %d, lflag = %d\n", grid[i][j], rFlag, lFlag);
    return lFlag + rFlag;
}

bool checkValidGrid(int** grid, int gridSize, int* gridColSize){
    int nrows, ncols;
    int i, j;
    int *visited;

    nrows = gridSize;
    ncols = *gridColSize;
    visited = (int*)malloc(sizeof(int) * (nrows*ncols+1));
    memset(visited, 0, sizeof(int) * (nrows*ncols+1));
    visited[0] = 1;
    visited[nrows*ncols - 1] = 1;

    for (i = nrows - 1; i >= 1; i--){
        for (j = 0; j < ncols; j++){
            if (visited[grid[i][j]] == 2) continue;
            if (visited[grid[i][j]] + check1Grid(grid, nrows, ncols, i, j) != 2){
                // printf("fails in val:%d, visited:%d, new:%d\n", grid[i][j], visited[grid[i][j]], check1Grid(grid, nrows, ncols, i, j));
                free(visited);
                return false;
            }
            visited[grid[i][j]] = 2;
            visited[grid[i][j]+1] += 1;
            if (grid[i][j]-1 >= 0)
                visited[grid[i][j]-1] += 1;
        }
    }
    free(visited);
    return true;
}

int main(){
    int k = 3, k2 = 5;
    int a[3][3] = {{0,3,6},{5,8,1},{2,7,4}};
    int a2[5][5] = {{24,11,22,17,4},{21,16,5,12,9},{6,23,10,3,18},{15,20,1,8,13},{0,7,14,19,2}};
    // {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    int **b = malloc(3 * sizeof(int *));
    int **b2 = malloc(5 * sizeof(int *));
    
    for (int i = 0; i < 3; i++) {
        b[i] = a[i];
    }
    for (int i = 0; i < 5; i++) {
        b2[i] = a2[i];
    }

    printf("result is %d\n", checkValidGrid(b2, 5, &k2));
    // printf("result is %d\n", checkValidGrid(b, 3, &k));
    return 0;
}