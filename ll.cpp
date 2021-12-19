#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node* next;

    //constructor
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template<typename T>
class LinkedList{
    public:
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    //constructor
    LinkedList()
    {
       head = NULL;
       tail = NULL;
    }
    //insert a node
    void insert_node(T val)
    {
        Node<T>* temp = new Node<T>(val);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            head->next = tail;
        }
        if(head != NULL)
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    //print the linked list
    void print(Node<T>* head)
    {
        Node<T>* temp;
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
    }
    //inserting a node at front
    void insert_at_front(T val)
    {
        Node<T>* temp = new Node<T>(val);
        temp->next = head;
        head = temp;
    }

    //functio to find the length of linked list
    int length(Node<T>* head)
    {
        Node<T>* temp;
        temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    //function to print ith node
    void iNode(Node<T>* head,int i)
    {
        if(i == 0)
        {
            cout<<head->data<<endl;;
        }
        int count = 0;
        int flag = 0;
        Node<T>* temp;
        temp = head;
        while(temp != NULL)
        {
            if(count == i)
            {
                cout<<temp->data<<endl;
                flag = 1;
                return;
            }
            count++;
            temp = temp->next;
        }
        if(flag == 0)
        {
            cout<<"No node exists at the given index"<<endl;
        }
    }

    //function to insert node at ith position
    void insert_at_i(T val,int i)
    {
        if(i == 0)
        {
            insert_at_front(val);
        }
        int count = 0;
        Node<T>* temp;
        temp = head;
        while(temp != NULL)
        {
            if(count == i-1)
            {
                Node<T>* n = new Node<T>(val);
                //connecting the new node to i+1 node
                n->next = temp->next;
                //placing the new node at ith position
                temp->next = n;
            }
            count++;
            temp = temp->next;
        }
    }
    //function to delete the ith node
    void delete_at_i(Node<T>* head,int i)
    {
        Node<T>* temp;
        if(i == 0)
        {
            //deleteing the head
            temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int count = 0;
        temp = head;
        while(temp != NULL)
        {
            if(count == i-1)
            {
                Node<T>* d;
                d = temp->next;
                temp->next = temp->next->next;
                delete d;
            }
            count++;
            temp = temp->next;
        }
    }

    //function to find the mid pointer
    T mid(Node<T>* head)
    {
        Node<T>* fast;
        Node<T>* slow;
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main()
{
    //Creating the linked list
    LinkedList<int> l;
    int n;
    cout<<"Enter total number of nodes in the linked list:"<<endl;
    cin>>n;

    //taking input of all the nodes 
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l.insert_node(x);
    }

    //printing the linked list
    cout<<"The entire linked list is as follows:"<<endl;
    l.print(l.head);
    cout<<endl;
    //inserting 0 at front
    cout<<"Inserting at front:"<<endl;
    l.insert_at_front(0);
    l.print(l.head);
    cout<<endl;

    //printing the length of list
    cout<<"Length of list: "<<l.length(l.head)<<endl;

    //printing the node at 5th position
    cout<<"Node at index 5 is:"<<endl;
    l.iNode(l.head,5);

    //inserting 69 at 7 index
    cout<<"Inserting at index 7:"<<endl;
    l.insert_at_i(69,7);
    l.print(l.head);
    cout<<endl;
    cout<<"Length of list: "<<l.length(l.head)<<endl;
    //deleting node at index 9
    cout<<"The list after deleting the tenth node:"<<endl;
    l.delete_at_i(l.head,9);
    l.print(l.head);
    cout<<endl;
    //mid node of list
    int result = l.mid(l.head);
    cout<<result;

    return 0;
}