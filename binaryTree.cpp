#include<iostream>
#include<queue>
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

void PrintBinaryTree(BinaryNode<int>* root)
{
	cout<<"Root is:"<<root->data<<endl;
	queue<BinaryNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0 )
	{
		BinaryNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		//for(int i=0;i<2;i++)
		{
			if(front->left != NULL)
			{
				cout<<front->left->data<<",";
			    pendingNodes.push(front->left);
			}
			if(front->right != NULL)
			{
				cout<<front->right->data;
			    pendingNodes.push(front->right);
			}
		}
		cout<<endl;
	}
}

void PreOrder(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data;
}

void InOrder(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	InOrder(root->left);
	cout<<root->data;
	InOrder(root->right);
}

int search(int inOrder[],int start,int end,int curr)
{
	for(int i=start;i<=end;i++)
	{
		if(inOrder[i] == curr)
			return i;
	}
	return -1;
}

BinaryNode<int>* PreIn(int inOrder[],int preOrder[],int start,int end)
{
	static int indx = 0;
	if(start > end)
	{
		return NULL;
	}
	int curr = preOrder[indx];
	indx++;
	BinaryNode<int>* node = new BinaryNode<int> (curr);
	if(start == end)
	{
		return node;
	}

	int pos = search(inOrder,start,end,curr);
    node->left = PreIn(inOrder,preOrder,start,pos-1);
    node->right = PreIn(inOrder,preOrder,pos+1,end);
    return node;
}

BinaryNode<int>* PostIn(int inOrder[],int postOrder[],int start,int end)
{
	static int indx = 6;
	if(start > end)
	{
		return NULL;
	}
	int curr = postOrder[indx];
	indx--;
	BinaryNode<int>* node = new BinaryNode<int> (curr);

	if(start == end)
	{
		return node;
	}
	int pos = search(inOrder,start,end,curr);
	node->right = PostIn(inOrder,postOrder,pos+1,end);
	node->left = PostIn(inOrder,postOrder,start,pos-1);
	return node;
}
int SumAtKLevel(BinaryNode<int>* root,int k)
{
	if(root == NULL)
	{
		return -1;
	}
	queue<BinaryNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	int sum = 0;
	int level = 0;
	while(pendingNodes.size() != 0)
	{
		BinaryNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		if(front != NULL)
		{
			if(level == k)
			{
				sum+=front->data;
			}
			if(front->left != NULL)
			{
				pendingNodes.push(front->left);
			}
			if(front->right != NULL)
			{
				pendingNodes.push(front->right);
			}
		}
		else if(pendingNodes.size() != 0)
		{
			pendingNodes.push(NULL);
			level++;
		}
	}
	return sum;
}

int CountN(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return CountN(root->left) + CountN(root->right) + 1;
}

int SumN(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}

	return SumN(root->left) + SumN(root->right) + root->data;
}

int HeightN(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int leftH = HeightN(root->left);
	int rightH = HeightN(root->right);

	return max(leftH,rightH) + 1;
}

/*bool isBalanced(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return true;
	}
	if(isBalanced(root->left) == false)
	{
		return false;
	}
	if(isBalanced(root->right) == false)
	{
		return false;
	}
	int l = HeightN(root->left);
	int r = HeightN(root->right);

	if(abs(l-r) <= 1)
	{
		return true;
	}
	else
		return false;
}*/

bool isBalanced(BinaryNode<int>* root,int* height)
{
	if(root == NULL)
	{
		return true;
	}

	int lh = 0,rh = 0;
	if(isBalanced(root->left,&lh) == false)
	{
		return false;
	}
	if(isBalanced(root->right,&rh) == false)
	{
		return false;
	}

	*height = max(lh,rh) + 1;

	if(abs(lh - rh) <= 1)
	{
		return true;
	}
	else
		return false;
}

void SumR(BinaryNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}

	SumR(root->left);
	SumR(root->right);

	if(root->left != NULL)
	{
		root->data+=root->left->data;
	}
	if(root->right != NULL)
	{
		root->data+=root->right->data;
	}
}

int DiamN(BinaryNode<int>* root)
{
	if( root == NULL)
	{
		return 0;
	}
	int l = HeightN(root->left);
	int r = HeightN(root->right);
	int curr = l+r+1;

	int ld = DiamN(root->left);
	int rd = DiamN(root->right);

	return max(curr,max(ld,rd));
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
	PrintBinaryTree(root);
	PreOrder(root);
	cout<<endl;
	/*PostOrder(root);
	cout<<endl;
	InOrder(root);*/

    cout<<endl;
	//int preOrder[] = {1,2,4,3,5,6,7};
	//int inOrder[] = {4,2,1,5,3,7,6};
	//int postOrder[] = {4,2,5,7,6,3,1};

	//BinaryNode<int>* root2 = PostIn(inOrder,postOrder,0,6);
	//PrintBinaryTree(root2);
    
	//SumR(root);
	//cout<<result<<endl;
	//PreOrder(root);
	int height = 0;
	bool result = isBalanced(root,&height);
	cout<<result;
	cout<<endl;
	return 0;
}