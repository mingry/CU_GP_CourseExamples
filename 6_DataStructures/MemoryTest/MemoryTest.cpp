#pragma optimize("", off)

#include <iostream>
#include <vector>


void recursion_depth_overflow_test(int depth = 0) {
    
    
    int x[1000]; // Increase size to reduce limit
    x[0] = 1;

    if (depth % 100 == 0) {
        std::cout << "Recursion depth: " << depth << std::endl;
    }
    recursion_depth_overflow_test(depth + 1);
}


void stack_memory_overflow_test() {

    // const int SIZE = 250000;
    const int SIZE = 260000;
    int arr[SIZE];
    arr[0] = 1;

    std::cout << "Array created successfully with size: " <<
        SIZE << std::endl;
}



int main() {

    stack_memory_overflow_test();
    //recursion_depth_overflow_test();

    return 0;
}




