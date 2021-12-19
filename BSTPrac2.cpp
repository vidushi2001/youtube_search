#include<iostream>
#include<climits>
using namespace std;

template<typename T>
class BinaryNode
{
public:
	T data;
	BinaryNode<T>* left;
	BinaryNode<T>* right;

	BinaryNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class Info
{
public:
	int min;
	int max;
	int size;
	int maxBST;
	bool isBST;
};

Info Func(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return {INT_MIN,INT_MAX,0,0,true};
	}

	if(root->left == NULL && root->right == NULL)
	{
		return {root->data,root->data,1,1,true};
	}

	Info LeftInfo = Func(root->left);
	Info RightInfo = Func(root->right);

	Info curr;
	curr.size = (LeftInfo.size + RightInfo.size + 1);
	if(LeftInfo.isBST && RightInfo.isBST && LeftInfo.max < root->data && RightInfo.min > root->data)
	{
		curr.min = min(LeftInfo.min , min(root->data,RightInfo.min));
		curr.max = max(max(LeftInfo.max,root->data),RightInfo.max);
		curr.isBST = true;
		curr.maxBST = (LeftInfo.maxBST + RightInfo.maxBST + 1);
	}

	curr.isBST = false;
	curr.maxBST = max(LeftInfo.maxBST,RightInfo.maxBST);
	curr.min = min(LeftInfo.min , min(root->data,RightInfo.min));
	curr.max = max(max(LeftInfo.max,root->data),RightInfo.max);

	return curr;
}

void RestoreBST(BinaryNode<int>* root)
{
	BinaryNode<int>* first = NULL;
	BinaryNode<int>* mid = NULL;
	BinaryNode<int>* last = NULL;
	BinaryNode<int>* prev = NULL;

	calcPointers(root,&first,&mid,&last,&prev);

	if(first && last)
	{
		swap(&(first->data),&(last->data));
	}
	else if(first && mid)
	{
		swap(&(first->data),&(mid->data));
	}
}

int main()
{
	//creating and initializing the nodes
	BinaryNode<int>* root = new BinaryNode<int> (1);
	BinaryNode<int>* child1 = new BinaryNode<int> (2);
	BinaryNode<int>* child2 = new BinaryNode<int> (3);
	BinaryNode<int>* child3 = new BinaryNode<int> (4);
	BinaryNode<int>* child4 = new BinaryNode<int> (5);
	BinaryNode<int>* child5 = new BinaryNode<int> (6);
	BinaryNode<int>* child6 = new BinaryNode<int> (7);

	//coneecting the nodes
	root->left = child1;
	root->right = child2;
	root->left->left = child3;
	root->right->left = child4;
	root->right->right = child5;
	root->right->right->left = child6;

	Info res = Func(root);
	cout<<res.maxBST<<endl;
	return 0;
}