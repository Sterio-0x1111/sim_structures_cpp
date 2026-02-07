#pragma once
#include <string>
#include <variant>

namespace sim_blist {
    class BList;
    using std::string;
    constexpr size_t MAX_SIZE = 10;

    template <typename T> class DataNode {
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
            : relation(p_relation), value(p_value) {}
        virtual ~DataNode() {}
        // if (p_relation == nullptr) {
        //     throw std::invalid_argument("p_relation is null");
        // }

        inline void setRelation(BList *p_relation) { relation = p_relation; }
        inline BList *getRelation() const { return relation; }

        inline void setValue(T p_value) { value = p_value; }
        inline T getValue() const { return value; }
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

    inline BList::BList() : previous(nullptr), next(nullptr) {
        // Initialisierung: Alle Pointer auf nullptr setzen
        for (size_t i = 0; i < max_size; ++i) {
            data_node[i] = nullptr;
        }
    }

    inline BList::~BList() {
        for (size_t i = 0; i < max_size; ++i) {
            delete data_node[i];
        }
    }

    inline BList::BList(const BList &other) {}

    inline BList &BList::operator=(const BList &rhs) {
        if (this != &rhs) {
        }
        // (*this).foo oder this->foo
        return *this;
    }

} // namespace sim_blist