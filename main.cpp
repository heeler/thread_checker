#include <iostream>
#include <omp.h>

int main() {
    unsigned int threads = omp_get_max_threads();
    std::cout << "Hello! Seeing " <<  threads << " threads" << std::endl;
    return 0;
}
