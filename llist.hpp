#ifndef LLIST_HPP
#define LLIST_HPP
#include <atomic>

template <class T>
class Node {
    public:
        T *value;
        void *next;
};
// Why no delete method you ask
// well delete gets really complex, 
// you need RCU or ref counting or GC really 
template <class T>
class LinkedList {
    private:
        std::atomic<Node<T> *> head;
    public:
        void insert(T *value) {
            Node<T> *node = new Node<T>();
            node->value = value;
            while (1) {
                node->next = this->head.load(std::memory_order_seq_cst);

                if(std::atomic_compare_exchange_strong_explicit(
                        &head, 
                        (Node<T> **)&node->next, 
                        node, 
                        std::memory_order_seq_cst, 
                        std::memory_order_seq_cst)) {
                    return;
                }
            }
        }
};

#endif // LLIST_HPP
