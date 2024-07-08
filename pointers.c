#include <stdio.h>
#include <stdbool.h>

void swap(int *i, int *j);
bool search(const int arr[], int size, int key);
void print_bool(bool x);
double inner_product(const double *arr1, const double *arr2, int size);
void convert_to_double(const int* arr1, int size, double* arr2 );

int main(void) {

    int arr1[] = {2, 3, 5, 7, 11, 13};
    int arr2[] = {4, 0, 2, -1, 0, 0};
    /*
    print_bool( search(arr1, 6, 3));
    print_bool( search(arr1, 6, 4));
    print_bool( search(arr1, 6, 2));
    print_bool( search(arr1, 6, 13));
     */

    double d1[6] = {0};
    double d2[6] = {0};
    convert_to_double(arr1, 6, d1);
    convert_to_double(arr2, 6, d2);

    printf("%f \n", inner_product(d1, d2, 6) );

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

void convert_to_double(const int* arr1, int size, double* arr2 ) {
    for (int i = 0; i < size; i++) {
        arr2[i] = (double) arr1[i];
    }
}