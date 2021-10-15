#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int search(void* buf, int size, int left, int right, void* item, int (*compare) (void*, void*))
{
    int mid, result;
    if (right < left) return -1;
    mid = (right+left)/2;
    result = compare(item, (char*)buf+(size*mid));
    if (result == 0)
        return mid;
    else if (result < 0)
        return search(buf, size, left, mid-1, item, compare);
    else
        return search(buf, size, mid+1, right, item, compare);
}   

// <!-- hàm so sánh phần nguyên -->
int int_compare(void const* x, void const* y)
{
    int m, n;
    // <!-- Lấy giá trị nguyên của x -->
    m = *((int*)x); 
    n = *((int*)y);
    if (m == n) return 0;
    return m>n ? 1 : -1;
}

int main() {
    int a[100], i, res;
    int n = 100, item = 5;
    for (i = 0; i < n; i++) a[i] = (rand() % (n-1+1))+1; // a[i] = (rand() % (upper - lower + 1)) + lower;
    qsort(a, n, sizeof(int), int_compare);
    for(int j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");
    res = search(a, sizeof(int), 0, n-1, &item, int_compare);
    printf("%d\n", res);
}
    