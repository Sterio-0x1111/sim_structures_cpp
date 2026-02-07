#include "..\include\b_list.hpp"
#include "b_list.cpp"
#include <iostream>

using std::cout;
using std::endl;
using namespace sim_blist;

int main(int, char **) {
    DataNode<int> test(1);
    BList r;
    DataNode<double> test2(20, &r);

    cout << "B+ Baum\n";
    cout << test.getValue() << " " << test2.getRelation() << endl;
    
    return EXIT_SUCCESS;
}