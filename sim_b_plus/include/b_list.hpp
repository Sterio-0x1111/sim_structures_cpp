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
        DataNode(T p_value = 0, BList *p_relation = nullptr)
            : relation(p_relation), value(p_value) {
        }
        virtual ~DataNode() {
        }

        void setRelation(BList *p_relation = nullptr);
        BList *getRelation() const;
        void setValue(T p_value);
        T getValue() const;
    };

    using data_variant =
        std::variant<DataNode<int> *, DataNode<float> *, DataNode<double> *,
                     DataNode<std::string> *>;

    std::ostream &operator<<(std::ostream &os,
                             const data_variant &p_data_variant);

    class BList {
      private:
        static constexpr size_t max_size = MAX_SIZE;
        data_variant data_node[max_size];
        BList *previous;
        BList *next;

      public:
        BList(BList *p_previous = nullptr, BList *p_next = nullptr);
        virtual ~BList();
        // BList(const BList &);
        BList &operator=(const BList &);

        void setDataNode(size_t, data_variant);
        data_variant getDataNode(size_t);
        void setPreviousBList(BList *);
        BList *getPreviousBList();
        void setnextBList(BList *);
        BList *getnextBList();
    };
} // namespace sim_blist

#include "../src/b_list.tpp" // nur bei template