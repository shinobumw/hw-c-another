// Simple implementation of Gaussian elimination

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <assert.h>
using namespace std;

#define DEBUG 0
#define MAX 4096

FILE *fout;
float A[MAX][MAX], b[MAX], augmentedMatrix[MAX][MAX], determinant;
int n, cases, swapTimes;

// Test correctness by using substitution method
bool isValid(float x[])
{
    for (int i = 0; i < n; ++i) {
        float sol = 0.0;
        for (int j = 0; j < n; ++j)
            sol += A[i][j] * x[j];
        if (abs(sol - b[i]) > 0.0001)
            return false;    
    }
    return true;    
}

// Find the first nonzero pivot and swap row
int swapRow(int row)
{
    for (int i = row + 1; i < n; ++i) {
        if (abs(augmentedMatrix[i][row]) > 0.0001) {
            for (int j = 0; j < n + 1; ++j) {
                float tmp = augmentedMatrix[row][j];
                augmentedMatrix[row][j] = augmentedMatrix[i][j];
                augmentedMatrix[i][j] = tmp;
            }
            // Successful
            return 1;    
        }
    }
    // Fail
    return 0;
}

int toOne(int row)
{
    float pivot = augmentedMatrix[row][row];
    int flag = 0;
    if (abs(pivot) > 0.0001) {
        flag = 1;
    }
    // If the pivot is zero, swapRow
    else {    
        if (flag = swapRow(row))
            swapTimes++;
    }

    // If the pivot is nonzero
    if (flag) {    
        determinant *= pivot;
        for (int j = row; j < n + 1 ; ++j)
            augmentedMatrix[row][j] /= pivot;
        return 1;   
    }
    // If the pivot is zero
    else    
        return 0;
}

void gaussianElimination()
{
    fprintf(fout, "Case %d: n = %d\n\n", cases, n);

    int i, j;
    int row = 0;
    swapTimes = 0;
    determinant = 1;

    // Row reduction
    while (row < n) {
        // Check whether all elements of the row is zero
        int flag = 0;
        for (j = 0; j < n + 1; ++j) {
            if (abs(augmentedMatrix[row][j]) > 0.0001) {
                flag = 1;
                break;
            }
        }

        #if DEBUG == 1
        if (j >= n) {
            fprintf(fout, "Incorrect at [%d][%d]\n", row, j);
            for (i = 0; i < n; i++) {
                for (j = 0; j < n + 1; j++)
                    fprintf(fout, "%f\t", augmentedMatrix[i][j]);
                fprintf(fout, "\n");
            }
            fprintf(fout, "\n");
        }
        #endif

        // Divide pivot into one
        if (flag)
            flag = toOne(row);

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
            determinant *= -1;

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
    FILE *fin = fopen(argv[1], "r");
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

        #if DEBUG == 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++)
                fprintf(fout, "%f\t", augmentedMatrix[i][j]);
            fprintf(fout, "\n");
        }
        fprintf(fout, "\n");
        #endif

        gaussianElimination();
        cases++;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
