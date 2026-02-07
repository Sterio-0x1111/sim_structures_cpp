#pragma once
#include <string>
#include <variant>

namespace sim_blist {
    class BList;
    using std::string;
    constexpr size_t MAX_SIZE = 10;

    template <typename T>
    class DataNode {
      private:
        BList *relation;
        T value;

        static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> ||
                          std::is_same_v<T, double> ||
                          std::is_same_v<T, std::string>,
                      "DataNode can only be used with int, float, double, "
                      "or string");

      protected:
      public:
        DataNode(T p_value, BList *p_relation = nullptr)
            : relation(p_relation), value(p_value) {
        }
        virtual ~DataNode() {
        }

        void setRelation(BList *p_relation);
        BList *getRelation() const;
        void setValue(T p_value);
        T getValue() const;
    };

    class BList {
      private:
        static constexpr size_t max_size = MAX_SIZE;
        std::variant<DataNode<int>, DataNode<float>, DataNode<double>,
                     DataNode<std::string>> *data_node[max_size];
        BList *previous;
        BList *next;

      public:
        BList();
        virtual ~BList();
        BList(const BList &);
        BList &operator=(const BList &);
    };
} // namespace sim_blist

#include "../src/b_list.tpp" // nur bei template