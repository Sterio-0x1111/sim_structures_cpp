#include "..\include\b_list.hpp"
#include "b_list.cpp"
#include <iostream>

int main(int, char **) {
    std::cout << "B+ Baum\n";
    blist::DataNode<int> test(1);
    std::cout << test.getValue();
    return EXIT_SUCCESS;
}