#include<iostream>
using namespace std;
template<typename T>
class Queue{
    T* data;
    int nextIndex;
    int size;
    int capacity;
    int firstIndex;

    public:
    //constructor
    Queue(int s)
    {
        data = new T[s];
        nextIndex = 0;
        size = 0;
        capacity = s;
        firstIndex = -1;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T val)
    {
        if(size == capacity)
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        data[nextIndex] = val;
        nextIndex = (nextIndex + 1)%capacity;
        size++;
        
        if(firstIndex == -1)
        {
            firstIndex = 0;
        }
        
    }

    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1)%capacity;
        size--;
        if(size == 0)
        {
            nextIndex = 0;
            firstIndex = -1;
        }
        return ans;
    }

    T front()
    {
        if(firstIndex == -1)
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
};