#include <stdio.h>
#include <stdbool.h>

void swap(int *i, int *j);
bool search(const int arr[], int size, int key);
void print_bool(bool x);
double inner_product(const double *arr1, const double *arr2, int size);

int main(void) {

    int arr1[] = {2, 3, 5, 7, 11, 13};
    print_bool( search(arr1, 6, 3));
    print_bool( search(arr1, 6, 4));
    print_bool( search(arr1, 6, 2));
    print_bool( search(arr1, 6, 13));
    return 0;
}

void print_bool(bool x) {
    printf("%s", (x ? "true\n": "false\n") );
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

bool search(const int arr[], int size, int key) {
    for (const int *p = arr; p < arr + size; p++) {
        if (*p == key) return true;
    }
    return false;
}

double inner_product(const double *arr1, const double *arr2, int size) {
    double product = 0;
    for (int i = 0; i < size; i++) {
        product += *(arr1 + i) * *(arr2 + i);
    }
    return product;
}