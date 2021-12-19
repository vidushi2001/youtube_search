#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class BST
{
	public:
		T data;
		BST<T>* left;
		BST<T>* right;

		BST(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

BST<int>* InsertBST(BST<int>* root,int val)
{
	if(root == NULL)
	{
		return new BST<int> (val);
	}
	if(val < root->data)
	{
		root->left = InsertBST(root->left,val);
	}
	if(val > root->data)
	{
		root->right = InsertBST(root->right,val);
	}

	return root;
}

int main()
{
	int build[] = {5,1,3,4,2,7};
	int n = sizeof(build)/sizeof(build[0]);

	BST<int>* root = NULL;
	root = InsertBST(root,build[0]);
	for(int i=1;i<n;i++)
	{
		InsertBST(root,build[i]);
	}
	return 0;

}