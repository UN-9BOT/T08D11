#include <stdio.h>
#include <stdlib.h>

void wtfMX(double ***, int, int);
void freeMX(double **);
void getSize(int *, int *, int *);
void getNums(double **, int, int, int *);
double getDet(int, double **);
void reduceMX(double **mx, double **mx2, int n, int m, int size);
int main(void) {
    int n, m, flag;
    double **mx;
    n = m = flag = 0;

    getSize(&n, &m, &flag);
    if (flag == 0) {
        wtfMX(&mx, n, m);
        getNums(mx, n, m, &flag);
        double res = getDet(n, mx);
        printf("%.6lf", res);
        freeMX(mx);
    }
    return (0);
}

void wtfMX(double ***mx, int n, int m) {
    *mx = (double **)malloc(sizeof(double *) * n);
    double *pmx = (double *)malloc(sizeof(double) * n * m);
    for (int i = 0; i < n; i++) (*mx)[i] = pmx + m * i;
}

void freeMX(double **mx) {
    free(mx[0]);
    free(mx);
}

void getNums(double **mx, int n, int m, int *flag) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (scanf("%lf", &(mx[i][j])) != 1) {
                printf("n/a");
                *flag = 1;
            }
        }
}

void reduceMX(double **mx, double **mx2, int n, int m, int size) {
    int shiftN = 0;
    int shiftM = 0;

    for (int i = 0; i < size - 1; i++) {
        if (i == n) {
            shiftN = 1;
        }
        shiftM = 0;
        for (int j = 0; j < size - 1; j++) {
            if (j == m) {
                shiftM = 1;
            }
            mx2[i][j] = mx[i + shiftN][j + shiftM];
        }
    }
}

void getSize(int *n, int *m, int *flag) {
    int trash = 0;

    if (scanf("%d %d.%d", n, m, &trash) != 2 || *n <= 0 || *m <= 0) {
        printf("n/a");
        *flag = 1;
    }
}

double getDet(int size, double **mx) {
    double det = 0;

    if (size == 1) {
        det = mx[0][0];
    } else if (size == 2) {
        det = mx[0][0] * mx[1][1] - mx[0][1] * mx[1][0];
    } else {
        int degree = 1;
        double **mx2 = (double **)malloc(sizeof(double *) * (size - 1));
        for (int i = 0; i < size - 1; i++) {
            mx2[i] = (double *)malloc(sizeof(double) * (size - 1));
        }
        for (int j = 0; j < size; j++) {
            reduceMX(mx, mx2, j, 0, size);
            det += (degree * mx[j][0] * getDet(size - 1, mx2));
            degree *= -1;
        }
        for (int i = 0; i < size - 1; i++) {
            free(mx2[i]);
        }
        free(mx2);
    }
    return (det);
}
