#pragma once
#include "../include/b_list.hpp"

namespace sim_blist {
    template <typename T>
    inline void DataNode<T>::setRelation(BList *p_relation) {
        relation = p_relation;
    }

    template <typename T>
    inline BList *DataNode<T>::getRelation() const {
        return relation;
    }

    template <typename T>
    inline void DataNode<T>::setValue(T p_value) {
        value = p_value;
    }

    template <typename T>
    inline T DataNode<T>::getValue() const {
        return value;
    }
} // namespace sim_blist
