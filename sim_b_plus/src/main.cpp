#include "../include/b_list.hpp"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using namespace sim_blist;

void test();

int main(int, char **) {
    test();

    auto i = std::make_shared<DataNode<int>>(100);
    // nicht effizient std::shared_ptr<DataNode<int>> i(new DataNode<int>(100)); 
    
    BList s;
    s.setDataNode(0, i);
    cout << i->getRelation()->getDataNode(0);

    return EXIT_SUCCESS;
}

void test() {
    // std::unique_ptr oder std::shared_ptr risiko für Dangling Pointers <-- to
    // do
    std::shared_ptr<DataNode<int>> test = std::make_shared<DataNode<int>>(5);
    BList r;
    BList j;
    test->setRelation(&r);
    r.setnextBList(&j);

    cout << "B+ Baum\n";
    cout << test->getValue() << " " << test->getRelation() << endl;
    r.setDataNode(5, test);
    cout << r.getDataNode(5) << " " << test->getValue() << endl;

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        cout << r.getDataNode(static_cast<size_t>(i)) << " ";
    }

    cout << endl;

    cout << test->getRelation() << endl;
    test->setRelation(r.getnextBList());
    cout << test->getRelation() << endl;

    BList *h = test->getRelation();

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        cout << h->getPreviousBList()->getDataNode(static_cast<size_t>(i))
             << " ";
    }

    cout << endl;

    // test.reset(); setzt auf 0
    cout << r.getDataNode(5);
}