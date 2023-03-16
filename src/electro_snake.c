#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
/* void sort_vertical(int **matrix, int n, int m, int **result_matrix); */

/*
    1 2 3
    6 5 4
    7 8 9
*/
/* void sort_horizontal(int **matrix, int n, int m, int **result_matrix); */


void input(int **matrix, int *n, int *m, int *flag);
void allocateMX(int ***, int, int);
void output(int **matrix, int n, int m);
void freeMX(int ***matrix, int n);


int main() {
    int **matrix = NULL;
    /* int **result; */
    int n, m, flag;
    n = m = flag = 0;

    flag = 0;
    allocateMX(&matrix, n, m);
    input(matrix, &n, &m, &flag);
    output(matrix, n, m);
    freeMX(&matrix, n);
    if (!flag) {
        /* sort_vertical(matrix, n, m, result); */
        /* output(result, n, m); */
        output(matrix, n, m);
        
        /* sort_horizontal(matrix, n, m, result); */
        /* output(result, n, m); */

    }
}

void input(int **matrix, int *n, int *m, int *flag) {
    int trash = 0;
    printf("fd");
    if (scanf("%d %d.%d", n, m, &trash) != 2 || *n <= 0 || *m <= 0) {
        printf("n/a");
        *flag = 1;
    } else {
        printf("kkkk"); 
    }
    for (int tn = 0; tn < *n && flag == 0; tn++) {
        for (int tm = 0; tm < *m && flag == 0; tm++) {
            if (scanf("%d.%d", *(matrix + tn) + tm, &trash) != 1) {
                printf("n/a");
                *flag = 1;
            }
        }
    }
}


void allocateMX(int ***matrix, int n, int m) {
    *matrix = (int **)malloc(n * sizeof(int *));

    for (int tn = 0; tn < n; tn++) {
        *matrix[tn] = (int *)malloc(m * sizeof(int));
    }
}

void freeMX(int ***matrix, int n) {
    for (int tn = 0; tn < n; tn++) {
        free(*(matrix + tn));
    }
    free(*matrix);
}

void output(int **matrix, int n, int m) {
    for (int tn = 0; tn < n ; tn++) {
        for (int tm = 0; tm < m; tm++) {
            printf("%d ", *(*(matrix + tn) + tm));
        }
    }
}

