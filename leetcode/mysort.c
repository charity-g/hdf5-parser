#include <stdio.h>
#include <math.h>

void print_array(const int *a, const int len) {
    printf("Printed array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selection_sort(const int *a, const int len) {
    //TODO sort in-place ascending
}


void insertion_sort(const int *a, const int len) {
    //TODO sort in-place ascending
}

void bubble_sort(const int *a, const int len) {
    //TODO sort in-place ascending
}

void heap_sort(const int *a, const int len) {
    //TODO sort in-place ascending
}


void quick_sort_helper(int *a, const int start, const int end) {
    if (start >= end) return;
    int pivot = a[start];
    int pivot_i = start;
    int to_see = pivot_i + 1;
    while (to_see <= end) {
        if (a[to_see] <= pivot) {
            a[pivot_i] = a[to_see];
            a[to_see] = a[pivot_i + 1];
            pivot_i++;
        }
        to_see++;
    }
    a[pivot_i] = pivot;
    quick_sort_helper(a, start, pivot_i - 1);
    quick_sort_helper(a, pivot_i + 1, end);
}
void quick_sort(int *a, const int len) {
    quick_sort_helper(a, 0, len - 1);
}

void mysort(int *a, const int len) {
    quick_sort(a, len);
}

// int main(int argc, char *argv[]) 
// {
//     int a[] = {5, 2, 9, 1, 5, 6};
//     int len = sizeof(a) / sizeof(a[0]);
//     print_array(a, len);
//     mysort(a, len);
//     print_array(a, len);
//     return 0;
// }