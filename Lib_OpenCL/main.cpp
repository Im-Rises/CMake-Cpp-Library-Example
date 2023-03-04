#include <omp.h>
#include <iostream>

int main() {
    int i, n;
    float a[100], b[100], result;

    /* Some initializations */
    n = 100;
    for (i = 0; i < n; i++)
    {
        a[i] = i * 1.5;
        b[i] = i + 22.35;
    }
    result = 0.0;

#pragma omp parallel for reduction(+ \
                                   : result)
    for (i = 0; i < n; i++)
    {
        result = result + (a[i] * b[i]);
    }

    std::cout << "Final result = " << result << std::endl;
}
