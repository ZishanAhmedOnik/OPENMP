#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N (100.0)

double my_rand() {
    return ((double) rand() / ((double) RAND_MAX + 1) * N);
}

void f2c(double f) {
    double c = (5.0 / 9.0) * (f - 32.0);

    printf("%.2fF is %.2fC\n", f, c);
}

int main() {
    srand(time(0));

    #pragma omp parallel 
    {
        f2c(my_rand());
    }

    puts("That's all, folks!");

    return 0;
}