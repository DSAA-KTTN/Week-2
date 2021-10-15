#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stddef.h>
#include"jval.h"

jval* create_array_i (int n) {
	jval * array = (jval *) malloc(sizeof(jval)*n);
	for (int i=0; i<n; i++) array[i] = new_jval_i( rand() );
	return array;
}

void swap(void *a, void *b)
{
	void *temp = (jval*)malloc(sizeof(jval));

	memcpy(temp, a, sizeof(jval));
	memcpy(a, b, sizeof(jval));
	memcpy(b, temp, sizeof(jval));

	free(temp);
}

void sort_gen(jval a[], int low, int high, int (*compare)(jval*, jval*))
{
    if (high <= low) return;
	int i = low-1, j = high;
	int p = low-1, q = high;
	int k;
	while(1)	{
		while (compare(&a[++i], &a[high]) < 0);
		while (compare(&a[high], &a[--j]) < 0)
            if (j == low) break;
		if (i >= j) break;

		swap(&a[i],&a[j]);
		if (compare(&a[i], &a[high]) == 0) swap(&a[++p],&a[i]);
		if (compare(&a[j], &a[high]) == 0) swap(&a[--q],&a[j]);
	}

	swap(&a[i],&a[high]);
	j = i - 1;
	i = i + 1;
	
	for (k = low ; k <= p; k++) swap(&a[k],&a[j--]);		
	for (k = high-1; k >= q; k--) swap(&a[k],&a[i++]);

    sort_gen(a, low, j, compare);
    sort_gen(a, i, high, compare);
}

int search_gen(jval a[], int low, int high, jval item, int (*compare)(jval*, jval*))
{
    int mid, result;
    if (high < low) return -1;
    mid = (high+low)/2;
    result = compare(&item, &a[mid]);
    if (result == 0)
        return mid;
    else if (result < 0)
        return search_gen(a, low, mid-1, item, compare);
    else
        return search_gen(a, mid+1, high, item, compare);
}

int main()
{
    jval a[100];
    int n = 100;
    for (size_t k = 0; k < n; k++) 
        a[k] = new_jval_i((rand() % (n-1+1))+1); // a[i] = (rand() % (upper - lower + 1)) + lower;
    
    printf("Chua sap xep:\n\t");
    for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");

    sort_gen(a, 0, n-1, compare_i);

    printf("Da sap xep:\n\t");
    for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");

    jval item = new_jval_i((rand() % (n-1+1))+1);
    int index = search_gen(a, 0, n-1, item, compare_i);
    printf("\nVi tri cua %d la: %d\n", item.i, index);
}