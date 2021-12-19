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

    Node<T>* mergeSortedLists(Node<T>* head1,Node<T>* head2)
    {
        Node<T>* temp1;
        Node<T>* temp2;
        Node<T>* finalHead;
        Node<T>* finalTail;
        temp1 = head1;
        temp2 = head2;
        finalHead = NULL;
        finalTail = NULL;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(finalHead == NULL)
            {
                if(temp1->data < temp2->data)
                {
                finalHead = temp1;
                finalTail = temp1;
                temp1 = temp1->next;
                }
                else{
                finalHead = temp2;
                finalTail = temp2;
                temp2 = temp2->next;
                }
                finalHead->next = finalTail;
            }
            if(temp1->data < temp2->data)
            {
              finalTail->next = temp1;
              finalTail = finalTail->next;
              temp1 = temp1->next;
            }
            else{
              finalTail->next = temp2;
              finalTail = finalTail->next;
              temp2 = temp2->next;
            }
        }

        if(temp1 == NULL && temp2!= NULL)
        {
            while(temp2 != NULL)
            {
                finalTail->next = temp2;
                finalTail = finalTail->next;
                temp2 = temp2->next;
            }
        }

        if(temp2 == NULL && temp1!= NULL)
        {
            while(temp1 != NULL)
            {
                finalTail->next = temp1;
                finalTail = finalTail->next;
                temp1 = temp1->next;
            }
        }

        return finalHead;
    }

    //reverse linked list
    Node<T>* reverse(Node<T>* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        Node<T>* smallAns = reverse(head->next);

        Node<T>* temp;
        temp = smallAns;
        while(temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        head->next = NULL;
        return smallAns;
    }
};

int main()
{
    //Creating the linked list
    LinkedList<int> l1;
    int n;
    cout<<"Enter total number of nodes in the linked list 1:"<<endl;
    cin>>n;
    //taking input of all the nodes 
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        l1.insert_node(x);
    }
    Node<int>* t = l1.reverse(l1.head);
    cout<<endl;
    l1.print(t);

    /*LinkedList<int> l2;
    int n2;
    cout<<"Enter total number of nodes in the linked list 2:"<<endl;
    cin>>n2;
    
    //taking input of all the nodes 
    for(int i=0;i<n2;i++)
    {
        int x;
        cin>>x;
        l2.insert_node(x);
    }

    //printing the linked list
    cout<<"The entire linked list 1 is as follows:"<<endl;
    l1.print(l1.head);
    cout<<endl;

    cout<<"The entire linked list 2 is as follows:"<<endl;
    l2.print(l2.head);
    cout<<endl;
    LinkedList<int> l3;
    Node<int>* merged = l3.mergeSortedLists(l1.head,l2.head);
    l3.head = merged;
    l3.print(l3.head);*/

}