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
            //capacity = 2*capacity;
            T* newData = new T[2*capacity];
            int j = 0;
            for(int i = firstIndex;i<capacity;i++)
            {
                newData[j] = data[i];
                j++;
            }
            for(int i=0;i,firstIndex;i++)
            {
                newData[j] = data[i];
                j++;
            }
            data = newData;
            delete [] newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = capacity*2;
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