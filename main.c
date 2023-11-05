#include <stdio.h>

void printMatrix(int n, double mat[][n + 1]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(int n, double mat[][n + 1]) {
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = mat[i][k] / mat[k][k];
            for (int j = k; j <= n; j++) {
                mat[i][j] -= factor * mat[k][j];
            }
        }
    }
}

void backSubstitution(int n, double mat[][n + 1], double sol[]) {
    for (int i = n - 1; i >= 0; i--) {
        sol[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            sol[i] -= mat[i][j] * sol[j];
        }
        sol[i] /= mat[i][i];
    }
}

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double mat[n][n + 1];

    printf("Enter the augmented matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    gaussianElimination(n, mat);
    
    double sol[n];
    backSubstitution(n, mat, sol);

    printf("The solution of the system of equations are:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.3lf\n", i + 1, sol[i]);
    }

    return 0;
}
