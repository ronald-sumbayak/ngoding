#ifndef LIB_LINKEDLIST_H
#define LIB_LINKEDLIST_H

template <class Data>
class SinglyLinear {
    
    struct node {
        Data mData;
        struct node *next;
        SinglyLinear<Data> node (Data data);
    };
    
    typedef struct node Node;
    Node *head, *tail;
    unsigned int length;
    
    Node *assign_backward (Node *prev, Node *temp);
    
public:
    
    SinglyLinear ();
    void clear ();
    unsigned int size ();
    
    void insert_front (Data data);
    void insert_back (Data data);
    void insert_at (Data data, int position);
    void concat (SinglyLinear con);
    
    void remove_front ();
    void remove_back ();
    void remove_at (int position);
    
    Data front ();
    Data back ();
    Data at (int position);
    
    void reverse ();
};

#endif //LIB_LINKEDLIST_H
