#include "../include/b_list.hpp"

namespace sim_blist {
    BList::BList() : previous(nullptr), next(nullptr) {
        // Initialisierung: Alle Pointer auf nullptr setzen
        for (size_t i = 0; i < max_size; ++i) {
            data_node[i] = nullptr;
        }
    }

    BList::~BList() {
        for (size_t i = 0; i < max_size; ++i) {
            delete data_node[i];
        }
    }

    BList::BList(const BList &other) {
    }

    BList &BList::operator=(const BList &rhs) {
        if (this != &rhs) {
        }
        // (*this).foo oder this->foo
        return *this;
    }
}