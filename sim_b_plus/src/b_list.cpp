#include "../include/b_list.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>

namespace sim_blist {

    void BList::delete_node_at(size_t index) {
        data_node[index] = std::shared_ptr<DataNode<int>>(nullptr);
    }

    BList::BList(BList *p_previous, BList *p_next)
        : previous(p_previous), next(p_next) {
        for (size_t i = 0; i < max_size; ++i) {
            delete_node_at(i);
        }
    }

    BList::~BList() {
        // Optional: explizit da sonst automatisch
        for (size_t i = 0; i < max_size; ++i) {
            delete_node_at(i);
        }
    }

    BList::BList(const BList &other) : previous(nullptr), next(nullptr) {
        for (size_t i = 0; i < max_size; ++i) {
            this->data_node[i] = other.data_node[i];
            // shared_ptr erhöht hier einfach den Ref-Count
        }
    }

    BList &BList::operator=(const BList &rhs) {
        if (this != &rhs) {
            for (size_t i = 0; i < max_size; ++i) {
                this->data_node[i] = rhs.data_node[i];
            }
        }
        // (*this).foo oder this->foo
        return *this;
    }

    void BList::setDataNode(size_t index, data_variant new_data) {
        if (index < max_size) {
            data_node[index] = new_data;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    data_variant BList::getDataNode(size_t index) {
        if (index >= max_size) {
            throw std::out_of_range("BList get DataNode: Index out of range");
        }
        return data_node[index];
    }

    void BList::setPreviousBList(BList *previous_blist) {
        if (!previous_blist) {
            throw std::invalid_argument("BList set previous: previous is null");
        } else {
            this->previous = previous_blist;
            previous_blist->next = this;
        }
    }

    BList *BList::getPreviousBList() {
        return previous;
    }

    void BList::setnextBList(BList *next_blist) {
        if (!next_blist) {
            throw std::invalid_argument("BList set next: next is null");
        } else {
            this->next = next_blist;
            next_blist->previous = this;
        }
    }

    BList *BList::getnextBList() {
        return next;
    }

    std::ostream &operator<<(std::ostream &os,
                             const data_variant &p_data_variant) {
        std::visit(
            [&os](const auto &ptr) {
                if (ptr) {
                    os << ptr->getValue();
                } else {
                    os << "[null]";
                }
            },
            p_data_variant);
        return os;
    }
} // namespace sim_blist