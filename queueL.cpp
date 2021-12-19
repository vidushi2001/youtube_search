#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;

    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template<typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;

    public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T val)
    {
       Node<T>* newNode = new Node<T>(val);
       if(head == NULL)
       {
           head = newNode;
           tail = newNode;
       }
       else{
           tail->next = newNode;
           tail = newNode;
       }
       size++;
    }

    T dequeue()
    {
        if(size != 0)
        {
            T ans = head->data;
            Node<T>* temp = head;
            head = head->next;
            delete(temp);
            size--;
            return ans;
        }
        return 0;
    }

    T front()
    {
        if(size != 0)
        {
            return head->data;
        }
        return 0;
    }



    
};