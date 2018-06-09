// Gaussian elimination

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 256

FILE *fout;
float A[MAX][MAX], b[MAX], augmentedMatrix[MAX][MAX], determinant;
int n, cases, flag, swapTimes;

// Test correctness by using substitution method
int isValid(float x[])
{
    for (int i = 0; i < n; ++i) {
        float sol = 0;
        for (int j = 0; j < n; ++j)
            sol += A[i][j] * x[j];
        if (abs(sol - b[i]) > 0.0001)
            return 0;
    }
    return 1;
}

// Find the first nonzero pivot and swap row
void swapRow(int row)
{
    flag = 0;
    for (int i = row; i < n; ++i) {
        if (augmentedMatrix[i][row] != 0) {
            flag = 1;
            for (int j = 0; j < n + 1; ++j) {
                float tmp = augmentedMatrix[row][j];
                augmentedMatrix[row][j] = augmentedMatrix[i][j];
                augmentedMatrix[i][j] = tmp;
            }
            break;
        }
    }
}

void toOne(int row)
{
    float pivot = augmentedMatrix[row][row];
    swapTimes = 0;
    if (abs(pivot) > 0.0001) {
        flag = 1;
    }
    else if (abs(pivot) <= 0.0001) {
        swapRow(row);
        swapTimes++;
        if (flag)    // If the pivot is nonzero
            toOne(row);
    }

    if (flag) {    // If the pivot is nonzero
        determinant *= pivot;
        for (int j = row; j < n + 1 ; ++j)
            augmentedMatrix[row][j] /= pivot;
    }
}

void gaussianElimination()
{
    fprintf(fout, "Case %d: n = %d\n\n", cases, n);

    int row = 0, i, j;
    flag = 0;
    determinant = 1;

    // Row reduction
    while (row < n) {
        // Check whether all elements of the row is zero
        for (j = 0; j < n; ++j) {
            if (abs(augmentedMatrix[row][j]) > 0.0001) {
                flag = 1;
                break;
            }
        }

        // Divide pivot into one
        toOne(row);

        // Elimination
        if (flag) {
            for(i = 0; i < n; ++i) {
                if (i != row) {
                    float divisor = -augmentedMatrix[i][row];
                    for (j = 0; j < n + 1; ++j)
                        augmentedMatrix[i][j] += augmentedMatrix[row][j] * divisor;
                }
            }
        }
        else {
            fprintf(fout, "The determinant is zero.\n");
            break;
        }

        row++;
    }

    // If the determinant is nonzero
    if (row == n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n + 1; j++)
                fprintf(fout, "%f\t", augmentedMatrix[i][j]);
            fprintf(fout, "\n");
        }
        fprintf(fout, "\n");
        
        // Solution
        float x[MAX];    
        for (i = 0; i < n; ++i)
            x[i] = augmentedMatrix[i][n];

        // If swapTimes is odd, the determinant is negative.
        if (swapTimes % 2 == 1)
            determinant = -determinant;

        fprintf(fout, "Determinant = %f\n", determinant);
        fprintf(fout, "Solution: ");
        for (i = 0; i < n; ++i)
            fprintf(fout, "%f ", x[i]);
        fprintf(fout, "\n");

        // Test correctness
        if (isValid(x))
            fprintf(fout, "Check: The solution is valid.\n");
        else
            fprintf(fout, "Check: The solution is invalid.\n");
    }
    fprintf(fout, "=================================================\n");
}

int main(int argc, char *argv[])
{
    // File I/O
    // FILE *fin = fopen("./ex7_sample.in", "r");
    char filename[128];
    strcpy(filename, argv[1]); 
    FILE *fin = fopen(filename, "r");
    assert(fin != NULL);
    fout = fopen("test.out", "w");
    assert(fout != NULL);

    cases = 0;
    while (1) {
        // The number of unknown variable
        fscanf(fin, "%d", &n);
        if (n == 0)
            break;

        // A of Ax = b
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                fscanf(fin, "%f", &A[i][j]);

        // b of Ax = b
        for(int i = 0; i < n; ++i)
            fscanf(fin, "%f", &b[i]);

        // Augmented matrix
        for(int i = 0; i < n; ++i)
            for(int j = 0 ; j < n ; ++j)
                augmentedMatrix[i][j] = A[i][j];
        for(int i = 0; i < n; ++i)
            augmentedMatrix[i][n] = b[i];

        gaussianElimination();
        cases++;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
