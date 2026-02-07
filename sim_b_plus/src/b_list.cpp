#include "../include/b_list.hpp"
#include <iostream>
#include <stdexcept>

namespace sim_blist {

    void delete_node_at(data_variant &node) {
        std::visit([](auto *ptr) { delete ptr; }, node);
    }

    BList::BList(BList *p_previous, BList *p_next)
        : previous(p_previous), next(p_next) {
        for (size_t i = 0; i < max_size; ++i) {
            data_node[i] = static_cast<DataNode<int> *>(nullptr);
        }
    }

    BList::~BList() {
        for (size_t i = 0; i < max_size; ++i) {
            delete_node_at(data_node[i]);
        }
    }

    BList::BList(const BList &other) {
    }

    BList &BList::operator=(const BList &rhs) {
        if (this != &rhs) {
            for (size_t i = 0; i < max_size; ++i) {
                delete_node_at(this->data_node[i]);
            }

            for (size_t i = 0; i < max_size; ++i) {
                this->data_node[i] = std::visit(
                    [](auto *ptr) -> data_variant {
                        if (!ptr)
                            return static_cast<decltype(ptr)>(nullptr);
                        return new std::remove_pointer_t<decltype(ptr)>(*ptr);
                    },
                    rhs.data_node[i]);
            }
        }
        // (*this).foo oder this->foo
        return *this;
    }

    void BList::setDataNode(size_t index, data_variant new_data) {
        if (index >= 0 && index < max_size) {
            delete_node_at(data_node[index]);
            data_node[index] = new_data;
        } else {
            throw std::out_of_range("BList: Index out of range");
        }
    }

    data_variant BList::getDataNode(size_t index) {
        if (index < 0 || index >= max_size)
            throw std::out_of_range("BList: Index out of range");
        return data_node[index];
    }

    std::ostream &operator<<(std::ostream &os,
                                    const data_variant &p_data_variant) {
        std::visit(
            [&os](auto *ptr) {
                if (ptr) {
                    // Greift auf den Wert im DataNode zu
                    os << ptr->getValue();
                } else {
                    os << "nullptr";
                }
            },
            p_data_variant);
        return os;
    }

    void BList::setPreviousBList(BList *) {
    }

    BList *BList::getPreviousBList() {
    }

    void BList::setnextBList(BList *) {
    }

    BList *BList::getnextBList() {
    }
} // namespace sim_blist