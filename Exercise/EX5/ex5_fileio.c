// Quick sort implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

typedef struct {
    int x;
    char c;
} P;

// Sort in ascending order
int cmp1(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// Sort first element in descending order
int cmp2(const void *a, const void *b)
{
    P p = *(P *)a;
    P q = *(P *)b;
    return q.x - p.x;
}

// Sort second element in ascending order
int cmp3(const void *a, const void *b)
{
    P p = *(P *)a;
    P q = *(P *)b;
    return p.c - q.c;
}

void myswap(void *ptr1, void *ptr2, size_t size)
{
    if (ptr1 == ptr2)
        return;
    void *temp = malloc(size);
    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
}

void mysort(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    // No need to sort if the number of elements is less than 1
    if (num <= 1)
        return;

    // Choose random pivot
    void *pivot = base + (num - 1) * size;
    myswap(pivot, base + (rand() % num) * size, size);

    // i: <= pivot, to_cmp: > pivot
    void *to_cmp = base;
    for (void *i = base; i < pivot; i += size) {
        if (cmp(i, pivot) <= 0) {
            myswap(i, to_cmp, size);
            to_cmp += size;
        }
    }
    myswap(pivot, to_cmp, size);

    // Recursion
    int n = (to_cmp - base) / size;
    mysort(base, n, size, cmp);
    mysort(to_cmp + size, num - n - 1, size, cmp);
}

int main()
{
    srand((unsigned)time(NULL));

    // File I/O
    FILE *fin = fopen("test.in", "r");
    assert(fin != NULL);
    FILE *fout = fopen("test.out", "w");
    assert(fout != NULL);

    // Testcase 1: Integer array
    int a[50];
    fprintf(fout, "Original sequence:\n");
    for (int i = 0; i < 50; ++i) {
        fscanf(fin, "%d", &a[i]);
        fprintf(fout, "%d%c", a[i], ((i == 49)? '\n' : ' '));
    }
    mysort(a, 50, sizeof(int), cmp1);
    fprintf(fout, "Sort in ascending order:\n");
    for (int i = 0; i < 50; ++i) {
        fprintf(fout, "%d%c", a[i], ((i == 49)? '\n' : ' '));
    }
    fprintf(fout, "\n");

    // Testcase 2: struct P array
    P mystr[20];
    fprintf(fout, "Original sequence:\n");
    for (int i = 0; i < 20; ++i) {
        fscanf(fin, "%d %c", &mystr[i].x, &mystr[i].c);
        fprintf(fout, "(%d, %c)%c",  mystr[i].x,  mystr[i].c, ((i == 19)? '\n' : ' '));
    }
    mysort(mystr, 20, sizeof(P), cmp2);
    fprintf(fout, "Sort first element in descending order:\n");
    for (int i = 0; i < 20; ++i) {
        fprintf(fout, "(%d, %c)%c",  mystr[i].x,  mystr[i].c, ((i == 19)? '\n' : ' '));
    }

    mysort(mystr, 20, sizeof(P), cmp3);
    fprintf(fout, "Sort second element in ascending order:\n");
    for (int i = 0; i < 20; ++i) {
        fprintf(fout, "(%d, %c)%c",  mystr[i].x,  mystr[i].c, ((i == 19)? '\n' : ' '));
    }
    return 0;
}
