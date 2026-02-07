#include "../include/b_list.hpp"
#include <iostream>

using std::cout;
using std::endl;
using namespace sim_blist;

int main(int, char **) {
    // std::unique_ptr oder std::shared_ptr risiko für Dangling Pointers <-- to do
    DataNode<int> *test = new DataNode<int>(1);
    BList r;
    test->setRelation(&r);
    data_variant *dv = new data_variant(test);

    cout << "B+ Baum\n";
    cout << test->getValue() << " " << test->getRelation() << endl;
    r.setDataNode(5, *dv);
    cout << r.getDataNode(5) << " " << test->getValue() << endl;

    delete dv;
    delete test;

    cout << r.getDataNode(5); // wert wird angezeigt obwohl bereits freigegeben

    return EXIT_SUCCESS;
}