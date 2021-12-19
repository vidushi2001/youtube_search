#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<deque>
using namespace std;

template<typename T>
class BinaryNode
{
public:
	T data;
	BinaryNode<T>* left;
	BinaryNode<T>* right;

	//constructor
	BinaryNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

BinaryNode<int>* BSTfromPreOrder(int PreOrder[],int* Preindx,int key,int min,int max,int n)
{
	if(*Preindx >=n)
	{
		return NULL;
	}
	BinaryNode<int>* root = NULL;
	if(key > min && key < max)
	{
		root = new BinaryNode<int>(key);
		*Preindx = *Preindx + 1;//incrementing the indx to point towards the next key in the array

		if(*Preindx < n)
		{
			root->left = BSTfromPreOrder(PreOrder,Preindx,PreOrder[*Preindx],min,key,n);
		}
		if(*Preindx < n)
		{
			root->right = BSTfromPreOrder(PreOrder,Preindx,PreOrder[*Preindx],key,max,n);
		}
	}
	return root;
}

void PrintBST(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	//cout<<root->data<<":"<<" ";
	queue<BinaryNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0)
	{
		BinaryNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		if(front->left != NULL)
		{
			cout<<front->left->data<<",";
			pendingNodes.push(front->left);
		}
		if(front->right != NULL)
		{
			cout<<front->right->data<<",";
			pendingNodes.push(front->right);
		}
		cout<<endl;
	}
}

bool BSTCheck(BinaryNode<int>* root,BinaryNode<int>* min,BinaryNode<int>* max)
{
	if(root == NULL)
	{
		return true;
	}

	if(min != NULL && root->data <= min->data)
	{
		return false;
	}
	if(max != NULL && root->data >= max->data)
	{
		return false;
	}

	bool leftvalid = BSTCheck(root->left,min,root);
	bool rightvalid = BSTCheck(root->right,root,max);

	return leftvalid and rightvalid;
}

BinaryNode<int>* BSTfromSArray(int sarray[],int start,int end)
{
	if(start > end)
	{
		return NULL;
	}

	int mid = (start + end)/2;
	BinaryNode<int>* root = new BinaryNode<int>(sarray[mid]);

	root->left = BSTfromSArray(sarray,start,mid-1);
	root->right = BSTfromSArray(sarray,mid+1,end);
	return root;
}

void ZigZag(BinaryNode<int>* root)
{
	deque<BinaryNode<int>*> pendingNodes;
	vector<int> v;
	pendingNodes.push_back(root);
	v.push_back(root->data);
	int l = 1;
	BinaryNode<int>* temp;
	while(pendingNodes.size() != 0)
	{
		int n = pendingNodes.size();
		for(int i = 0;i<n;i++)
		{
			if(l%2 == 0)//level is even -- right to left
			{
				temp = pendingNodes.back();
				pendingNodes.pop_back();
			}
			else
			{
				temp = pendingNodes.front();
				pendingNodes.pop_front();
			}

			if(l%2 == 0)
			{
				if(temp->left != NULL)
				{
					pendingNodes.push_front(temp->left);
					v.push_back(temp->left->data);
				}
				if(temp->right != NULL)
				{
					pendingNodes.push_front(temp->right);
					v.push_back(temp->right->data);
				}
			}
			else if(l%2 != 0)
			{
				if(temp->right != NULL)
				{
					pendingNodes.push_back(temp->right);
					v.push_back(temp->right->data);

				}
				if(temp->left != NULL)
				{
					pendingNodes.push_back(temp->left);
					v.push_back(temp->left->data);
				}
			}
		}
		l++;
	}

	//printing the vector
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

bool isIdentical(BinaryNode<int>* root1,BinaryNode<int>* root2)
{
	if(root1 == NULL && root2 == NULL)
		{
			return true;
		}
	if(root1 != NULL && root2 != NULL)
	{
		if(root1->data == root2->data)
		{
			return isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);
		}
	}
	return false;		
}

int main()
{
	//int PreOrder[] = {5,1,3,2,4,7};
	//int Preindx = 0;
	//int min = NULL,max = NULL;
	//int key = PreOrder[0];
	//int n = sizeof(PreOrder)/sizeof(PreOrder[0]);
	//BinaryNode<int>* root = BSTfromPreOrder(PreOrder,&Preindx,key,INT_MIN,INT_MAX,n);
	//PrintBST(root);
//	BinaryNode<int>* min = new BinaryNode<int>(INT_MIN);
	//BinaryNode<int>* max = new BinaryNode<int>(INT_MAX);
	//if(BSTCheck(root,min,max))
	{
		//cout<<"Valid BST"<<endl;
	}
	//else
	{
		//cout<<"Invalid BST"<<endl;
	}

	//int Array[] = {1,2,3,4,5,6};
	//BinaryNode<int>* root = BSTfromSArray(Array,0,5);
	BinaryNode<int>* root1 = new BinaryNode<int>(1);
	BinaryNode<int>* root2 = new BinaryNode<int>(1);
	BinaryNode<int>* child1 = new BinaryNode<int>(3);
	BinaryNode<int>* child2 = new BinaryNode<int>(2);
	BinaryNode<int>* child5 = new BinaryNode<int>(7);
	//BinaryNode<int>* child4 = new BinaryNode<int>(8);

	BinaryNode<int>* child6 = new BinaryNode<int>(3);
	BinaryNode<int>* child7 = new BinaryNode<int>(2);
	//BinaryNode<int>* child5 = new BinaryNode<int>(7);
	BinaryNode<int>* child8 = new BinaryNode<int>(8);
	root1->right = child1;
	root1->right->left = child2;
	root1->right->right = child5;

	root2->right = child6;
	root2->right->left = child7;
	root2->right->right = child8;
	
	PrintBST(root1);
	PrintBST(root2);

	if(isIdentical(root1,root2))
	{
		cout<<"Identical"<<endl;
	}
	else
	{
		cout<<"Not Identical"<<endl;
	}
	//ZigZag(root);
	return 0;
}