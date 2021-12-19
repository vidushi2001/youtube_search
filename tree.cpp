#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout<<"Enter Root:"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int> (rootData);

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0)
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout<<"Enter number of children of "<<front->data<<":"<<endl;
		for(int i=0;i<numChild;i++)
		{
			cout<<"Enter the "<<i<<"th"<<" child of "<<front->data<<" :"<<endl;
			int x;
			cin>>x;
			TreeNode<int>* child = new TreeNode<int> (x);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput()
{
	int rootData;
	cout<<"Enter Root:"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int> (rootData);

	int n;
	cout<<"Enter number of children:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}

	return root;
}

void PrintTreeLevelWise(TreeNode<int>* root)
{
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	//cout<<"The root is:";
	while(pendingNodes.size() != 0)
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<": ";
		for(int i=0;i<front->children.size();i++)
		{
			cout<<front->children[i]->data<<",";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}

void PrintTree(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		PrintTree(root->children[i]);
	}
}

int numNodes(TreeNode<int>* root)
{
	int ans = 1;
	for(int i=0;i<root->children.size();i++)
	{
		ans+= numNodes(root->children[i]);
	}
	return ans;
}

int Sum(TreeNode<int>* root)
{
	int sum = root->data;
	for(int i=0;i<root->children.size();i++)
	{
		sum+=Sum(root->children[i]);
	}
	return sum;

}

int findHeight(TreeNode<int>* root)
{
	//using queue
	queue<TreeNode<int>*> pendingNodes;
	int height = 1;
	pendingNodes.push(root);
	if(root->children.size() != 0 )
		height = height+1;
	for(int i=0;i<root->children.size();i++)
	{
		pendingNodes.push(root->children[i]);
		findHeight(root->children[i]);
	}
	return height;
}

int MaxNode(TreeNode<int>* root)
{
	int maxi = root->data;
	for(int i=0;i<root->children.size();i++)
	{
		maxi = max(maxi,root->children[i]->data);
	}
	return maxi;
}

int PrintAtLevelK(TreeNode<int>* root,int k)
{
	if(root == NULL)
	{
		return -1;
	}
	if(k == 0)
	{
		return root->data;
	}
	for(int i = 0;i<root->children.size();i++)
	{
		PrintAtLevelK(root->children[i],k-1);
	}
}

int CountLeafNodes(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return -1;
	}
	
	if(root->children.size() == 0)
	{
		//sum = 1;
		return 1;
	}
    int sum = 0;
	for(int i=0;i<root->children.size();i++)
	{
		sum+=CountLeafNodes(root->children[i]);
	}
	return sum;
}

void PreOrder(TreeNode<int>* root)
{
	cout<<root->data;
	for(int i=0;i<root->children.size();i++)
	{
		PreOrder(root->children[i]);
		cout<<" ";
	}
	
}

void PostOrder(TreeNode<int>* root)
{
	for(int i = 0;i<root->children.size();i++)
	{
		PostOrder(root->children[i]);
	}
	cout<<root->data;
}

void deleteNode(TreeNode<int>* root)
{
	for(int i=0;i<root->childrem.size();i++)
	{
		deleteNode(root->children[i]);
	}
	delete root;
}

int main()
{
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	TreeNode<int>* node3 = new TreeNode<int>(4);
	TreeNode<int>* node4 = new TreeNode<int>(5);

	root->children.push_back(node1);
	root->children.push_back(node2);
	node1->children.push_back(node3);
	node2->children.push_back(node4);

	//int result = CountLeafNodes(root);
	//cout<<result<<endl;
    //TreeNode<int>* root = takeInputLevelWise();
    PrintTreeLevelWise(root);
    PostOrder(root);
	//PrintTree(root);
	return 0;
}