//executing prooirity queues with the help of min heap(CBT but in the form of array)
#include<iostream>
#include<vector>
using namespace std;

class PQ{
    vector<int> pq;

    public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int val)
    {
        pq.push_back(val);
        //checking for min heap property
        //up-heapify
        int childIndex = pq.size() - 1;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1)/2;
            if(pq[parentIndex] > pq[childIndex])
            {
                swap(pq[parentIndex],pq[childIndex]);
            }

            childIndex = parentIndex;
        }
    }

    void removeMin()
    {
        if(isEmpty())
        {
            return;
        }
        int ans = pq[0];
        swap(pq[0],pq[pq.size()-1]);
        //down heapify
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        //int minIndex = 0;
        while(leftChildIndex < pq.size())
        {
            if(pq[parentIndex] > pq[leftChildIndex])
            {
                swap(pq[parentIndex],pq[leftChildIndex]);
                //minIndex = leftChildIndex;
                parentIndex = leftChildIndex;
            }
            if(pq[parentIndex] > pq[leftChildIndex])
            {
                swap(pq[parentIndex],pq[rightChildIndex]);
                //minIndex = rightChildIndex;
                parentIndex = rightChildIndex;
            }
            else{
                minIndex = parentIndex;
                break;
            }
        }

        return;
    }
};

int main()
{
    PQ p;
    p.insert(2);
    p.insert(7);
    p.insert(8);
    p.insert(3);
    p.insert(4);

    cout<<p.getMin()<<endl;

    p.removeMin();

    cout<<p.getMin()<<endl;
    return 0;
}