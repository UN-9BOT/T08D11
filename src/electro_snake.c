#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
void getNM(int *, int *, int *);
void freeMX(int **, int);
void input(int **matrix, int n, int m, int *);
void allocMx(int ***matrix, int n, int m);
void nsort(int *, int);
void output(int **matrix, int n, int m);

int main(void) {
    int **matrix;
    int **result;
    int n, m, flag;
    getNM(&n, &m, &flag);
    if (!flag) {
        allocMx(&matrix, n, m);
        input(matrix, n, m, &flag);
        allocMx(&result, n, m);
        sort_vertical(matrix, n, m, result);
        output(result, n, m);
        printf("\n\n");
        sort_horizontal(matrix, n, m, result);
        output(result, n, m);
        printf("\n");
        freeMX(matrix, n);
        freeMX(result, n);
    }
    return (0);
}

void getNM(int *n, int *m, int *flag) {
    int trash = 0;
    if (scanf("%d %d.%d", n, m, &trash) != 2) {
        *flag = 1;
    }
}

void input(int **matrix, int n, int m, int *flag) {
    int trash = 0;
    for (int tn = 0; tn < n; tn++) {
        for (int tm = 0; tm < m && *flag == 0; tm++) {
            if (scanf("%d.%d", &matrix[tn][tm], &trash) != 1) *flag = 1;
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int tn = 0; tn < n; tn++) {
        for (int tm = 0; tm < m; tm++) {
            printf("%d", *(*(matrix + tn) + tm));
            if (tm != m - 1) {
                printf(" ");
            }
            if (tm == m - 1 && tn != n - 1) {
                printf("\n");
            }
        }
    }
}

void allocMx(int ***matrix, int n, int m) {
    *matrix = (int **)malloc(n * sizeof(int *));

    for (int tn = 0; tn < n; tn++) {
        (*matrix)[tn] = (int *)malloc(sizeof(int) * m);
    }
}

void freeMX(int **matrix, int n) {
    for (int tn = 0; tn < n; tn++) {
        free(*(matrix + tn));
    }
    free(matrix);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void nsort(int *data, int sz) {
    int i, j;
    for (i = 0; i < sz - 1; i++)
        for (j = 0; j < sz - i - 1; j++)
            if (data[j] > data[j + 1]) swap(&data[j], &data[j + 1]);
}

void sort_vertical(int **matrix, int n, int m, int **result) {
    int *arr = (int *)malloc(n * m * sizeof(int *));

    int counter = 0;

    for (int tn = 0; tn < n; tn++) {
        for (int tm = 0; tm < m; tm++) {
            arr[counter] = *(*(matrix + tn) + tm);
            counter++;
        }
    }

    nsort(arr, n * m);
    counter = 0;
    for (int tm = 0; tm < m; tm++) {
        if (tm % 2 == 0) {
            for (int tn = 0; tn < n; tn++) {
                result[tn][tm] = arr[counter];
                counter++;
            }
        } else {
            for (int tn = n - 1; tn >= 0; tn--) {
                result[tn][tm] = arr[counter];
                counter++;
            }
        }
    }

    free(arr);
}

void sort_horizontal(int **matrix, int n, int m, int **result) {
    int *arr = (int *)malloc(n * m * sizeof(int *));

    int counter = 0;

    for (int tn = 0; tn < n; tn++) {
        for (int tm = 0; tm < m; tm++) {
            arr[counter] = *(*(matrix + tn) + tm);
            counter++;
        }
    }

    nsort(arr, n * m);
    counter = 0;
    for (int tn = 0; tn < n; tn++) {
        if (tn % 2 == 0) {
            for (int tm = 0; tm < m; tm++) {
                result[tn][tm] = arr[counter];
                counter++;
            }
        } else {
            for (int tm = m - 1; tm >= 0; tm--) {
                result[tn][tm] = arr[counter];
                counter++;
            }
        }
    }

    free(arr);
}
