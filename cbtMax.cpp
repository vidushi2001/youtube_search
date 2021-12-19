#include <iostream>
#include <vector>
using namespace std;
class PQ
{
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
    int getMax()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int val)
    {
        pq.push_back(val);
        //up-heapify
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            childIndex = parentIndex;
        }
    }

    void removeMax()
    {
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while(leftChildIndex < pq.size())
        {
            if(pq[parentIndex] < pq[leftChildIndex])
        {
            swap(pq[parentIndex],pq[leftChildIndex]);
            parentIndex = leftChildIndex;
        }
        if(pq[parentIndex] < pq[rightChildIndex])
        {
            swap(pq[parentIndex],pq[rightChildIndex]);
            parentIndex = rightChildIndex;
        }
        else{
            break;
        }
        }
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

    cout<<p.getMax()<<endl;

    p.removeMax();

    cout<<p.getMax()<<endl;
    return 0;
}