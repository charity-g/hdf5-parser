#ifndef MYSORT_H
#define MYSORT_H

void selection_sort(const int *a, const int len);
void insertion_sort(const int *a, const int len);
void bubble_sort(const int *a, const int len);
void heap_sort(const int *a, const int len);
void quick_sort(int *a, const int len);
void mysort(int *a, const int len); // Declare mysort as a wrapper function

#endif // MYSORT_H