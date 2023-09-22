#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findMaxSum(int arr[], int n) {
    int incl = arr[0];
    int excl = 0;
    int temp;
    
    for (int i = 1; i < n; i++) {
        temp = max(incl, excl);
        incl = excl + arr[i];
        excl = temp;
    }
    
    return max(incl, excl);
}

int main() {
    int v1[] = {2, 4, 6, 2, 5};
    int n1 = 5;
    printf("Exemplo 1: %d\n", findMaxSum(v1, n1));

    int v2[] = {2, 1, 1, 5};
    int n2 = 4;
    printf("Exemplo 2: %d\n", findMaxSum(v2, n2));
    
    return 0;
}
