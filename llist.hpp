#ifndef LLIST_HPP
#define LLIST_HPP

template <class T>
class LinkedList {
    private:
        T *head;
    public:
        void insert(T *value);
};

#endif // LLIST_HPP