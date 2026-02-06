#pragma once

namespace blist {
    class BList {
      private:
      public:
        BList();
        virtual ~BList();
        BList(const BList &);
        BList &operator=(const BList &);
    };

    inline BList::BList() {}

    inline BList::~BList() {}

    inline BList::BList(const BList &other) {}

    inline BList &BList::operator=(const BList &rhs) {
        if (this != &rhs) {
        }
        // (*this).foo oder this->foo
        return *this;
    }

} // namespace blist