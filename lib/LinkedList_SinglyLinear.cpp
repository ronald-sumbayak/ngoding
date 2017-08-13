#include "LinkedList.h"

template <class Data> SinglyLinear::node::node (Data data) {
    mData = data;
    next = nullptr;
}

SinglyLinear::SinglyLinear () {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class Data> void SinglyLinear::clear () {
    Node *temp = head->next;
    while (head != tail) {
        delete head;
        head = temp;
    }
    delete head;
    head = tail = nullptr;
    length = 0;
}

unsigned int SinglyLinear::size () {
    return length;
}

template <class Data> void SinglyLinear::insert_front (Data data) {
    if (head == nullptr) {
        head = tail = new Node (data);
        length++;
    }
    else {
        Node *insert = new Node (data);
        insert->next = head;
        head = insert;
        length++;
    }
}

template <class Data> void SinglyLinear::insert_back (Data data) {
    if (head == nullptr) {
        head = tail = new Node (data);
        length++;
    }
    else {
        Node *insert = new Node (data);
        tail->next = insert;
        tail = insert;
        length++;
    }
}

template <class Data> void SinglyLinear::insert_at (Data data, int position) {
    if (position == 0) insert_front (data);
    else if (position == length) insert_back (data);
    else {
        Node *temp = head;
        while (position--) {
            temp = temp->next;
        }
        
        Node *insert = new Node (data);
        insert->next = temp->next;
        temp->next = insert;
        length++;
    }
}

void SinglyLinear::concat (SinglyLinear con) {
    tail->next = con.head;
    tail = con.tail;
}

void SinglyLinear::remove_front () {
    if (length > 0) {
        Node *remove = head;
        head = head->next;
        if (length == 1) tail = nullptr;
        delete remove;
        length--;
    }
}

void SinglyLinear::remove_back () {
    if (length > 0) {
        if (length == 1) remove_front ();
        else {
            Node *temp, *remove;
            temp = head;
            remove = tail;
    
            while (temp->next != tail) temp = temp->next;
            tail = temp;
            delete remove;
            length--;
        }
    }
}

void SinglyLinear::remove_at (int position) {
    if (length > 0 && position <= length) {
        if (position == 0) remove_front ();
        else if (position == length-1) remove_back ();
        {
            Node *temp, *remove;
            temp = head;
            
            while (position-- > 1) temp = temp->next;
            remove = temp->next;
            temp->next = temp->next->next;
            if (remove == tail) tail = temp;
            delete remove;
            length--;
        }
    }
}

template <class Data> Data SinglyLinear::front () {
    if (length > 0) return head->mData;
    else return nullptr;
}

template <class Data> Data SinglyLinear::back () {
    if (length > 0) return tail->mData;
    else return nullptr;
}

template <class Data> Data SinglyLinear::at (int position) {
    if (length > 0 && position <= length) {
        if (position == 0) return front ();
        else if (position == length-1) return back ();
        else {
            Node *temp = head;
            while (position--) temp = temp->next;
            return temp->mData;
        }
    }
    
    return nullptr;
}

void SinglyLinear::reverse () {
    assign_backward (nullptr, head)->next = nullptr;
    Node *temp = head;
    head = tail;
    tail = temp;
}

SinglyLinear::Node * SinglyLinear::assign_backward (Node *prev, Node *temp) {
    if (temp == tail) return prev;
    assign_backward (temp, temp->next)->next = temp;
    return temp;
}