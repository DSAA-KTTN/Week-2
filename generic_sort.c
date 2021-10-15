
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stddef.h>

// ----------------------------------------
// typedef struct {
// 	int real;
// 	char complex;
// } data;
// ----------------------------------------

void swap(size_t size, void *a, void *b)
{
	void *temp = malloc(sizeof(size));

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	free(temp);
}

void exch(void* buf, size_t size, int i, int j)
{
	char* temp = (char*)malloc(sizeof(size));

	memcpy(temp, (char*)buf + i*size, size);
	memcpy((char*)buf + i*size, (char*)buf + j*size, size);
	memcpy((char*)buf + j*size, temp, size);

	free(temp);
}

int generic_compare(void* a, void* b)
{
	int m, n;
	m = *(int*)a;
	n = *(int*)b;

	if (m == n) return 0;
	else if (m < n) return -1;
	else return 1;
}

void genericSort(void* buf, size_t size, int low, int high, int (*compare)(void *, void *))
{
	if (low >= high) return;
	int i = low-1, j = high;
	int p = low-1, q = high;

	while(1)
	{
		while (compare((char*)buf+(++i)*size, (char*)buf+high*size) < 0);
		while (compare((char*)buf+high*size, (char*)buf+(--j)*size) < 0)
		{
			if (j == low) break;
		}
		if (i >= j) break;
		exch(buf, size, i, j);

		if (compare((char*)buf+i*size, (char*)buf+high*size) == 0)
			exch(buf, size, ++p, i);
		
		if (compare((char*)buf+j*size, (char*)buf+high*size) == 0)
			exch(buf, size, --q, j);
	}
	exch(buf, size, i, high);
	j = i - 1;
	i = i + 1;
	for (int k = low ; k <= p; k++) exch(buf, size, k, j--);
	for (int k = high-1; k >= q; k--) exch(buf, size, k, i++);
	genericSort(buf, size, low, j, compare);
	genericSort(buf, size, i, high, compare);
}

int main()
{
	// -----------------------------------------------------------
	int a[100], i, res;
    int n = 100, item = 5;
    for (i = 0; i < n; i++) a[i] = (rand() % (n-1+1))+1; // a[i] = (rand() % (upper - lower + 1)) + lower;

	for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");

	genericSort(a, sizeof(int), 0, n-1, generic_compare);
	for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");
	// -----------------------------------------------------------

	// -----------------------------------------------------------
	// char c[10];
	// c[0] = 'r';
	// c[1] = 'j';
	// c[2] = 'e';
	// c[3] = 'd';
	// c[4] = 'y';
	// c[5] = 'u';
	// c[6] = 'q';
	// c[7] = 'z';
	// c[8] = 'o';
	// c[9] = 'b';
	// int n = 10;
	// genericSort(c, sizeof(char), 0, n-1, generic_compare);
	// for(int j = 0; j < n; j++)
    //     printf("%c ", c[j]);
    // printf("\n");
	// -----------------------------------------------------------

}