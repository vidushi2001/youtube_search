#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;

    Node(T val)
    {
        this->data = val;
        next = NULL;
    }
};
template<typename T>
class Stack{
    Node<T>* head;
    int Csize;
    public:
    Stack()
    {
        head = NULL;
        Csize = 0;
    }
    void push(T val)
    {
        if(head == NULL)
        {
            head->data = val;
            head->next = NULL;
        }
        else
        {
            Node<T>* temp = new Node<T>(val);
            temp->next = head;
            head = temp;
        }
        Csize++;
    }

    T top()
    {
        if(Csize!=0)
        {
            return head->data;
        }
        return 0;
    }

    T pop()
    {
        T ans = head->data;
        Node<T>* temp = head;
        head=head->next;
        delete(temp);
        Csize--;
        return ans;
    }

    int size()
    {
        if(Csize > 0)
        {
            return Csize;
        }
    }

    bool isEmpty()
    {
        return csize == 0;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    int x = s.pop();
    cout<<x<<endl;
    int n = s.size();
    return 0;
}