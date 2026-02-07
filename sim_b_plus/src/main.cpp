#include "../include/b_list.hpp"
#include <iostream>

using std::cout;
using std::endl;
using namespace sim_blist;

int main(int, char **) {
    BList r;
    DataNode<int> test(1);
    test.setRelation(&r);

    cout << "B+ Baum\n";
    cout << test.getValue() << " " << test.getRelation() << endl;
    
    return EXIT_SUCCESS;
}