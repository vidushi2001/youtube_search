#include<iostream>
#include<climits>
using namespace std;
template<typename T>
class Stack
{
    private:
    T* data;
    int nextIndex;
    int capacity;
    public:
    Stack()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }
    //defining stack functions
    void push(T val)
    {
        if(nextIndex < capacity)
        {
            data[nextIndex] = val;
            nextIndex++;
        }
        else
        {
            T* newData = new T[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newData[i] = data[i];
            }
            capacity = capacity*2;
            delete [] data;
            data = newData;
            data[nextIndex] = val;
            nextIndex++;
        }
    }

    T pop()
    {
        T x;
        if(nextIndex != 0)
        {
            x = data[nextIndex-1];
            nextIndex--;
            return x;
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return 0;

    }

    T size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    T top()
    {
        if(!isEmpty())
        {
            return data[nextIndex-1];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return 0;
    }


};

int main()
{
    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    s.pop();
    int n = s.size();
    cout<<n<<endl;
    char x = s.top();
    cout<<x<<endl;
    s.pop();
    s.pop();
    s.top();
}