#include <stdio.h>

void readMatrix(int mat[10][3]) {
    int rows, cols, nz;
    printf("Enter the rows, columns and non-zero elements:");
    scanf("%d %d %d", &rows, &cols, &nz);
    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nz;

    printf("Enter row, column, value for each non-zero element:\n");
    for (int i = 1; i <= nz; i++) {
        scanf("%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]);
    }
}
void display(int mat[100][3]) {
    int n = mat[0][2];
    for (int i = 0; i <= n; i++) {
        printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
    printf("\n");
}
void sparseAdd(int A[10][3], int B[10][3], int C[10][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Matrix sizes do not match!\n");
        C[0][2] = 0;
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;
    int t1 = A[0][2], t2 = B[0][2];

    while (i <= t1 && j <= t2) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        } else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= t1) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= t2) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

int main() {
    int A[100][3], B[100][3], C[100][3], T[100][3];

    printf("Matrix A:\n");
    readMatrix(A);
    printf("Matrix B:\n");
    readMatrix(B);
    printf("Matrix A:\n");
    display(A);
    printf("Matrix B:\n");
    display(B);
    sparseAdd(A, B, C);
    printf("Sum (A + B):");
    display(C);
    return 0;
}
