#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data)
	{
		this->data = data;
	}
}

TreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout<<"Enter root:"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int> (rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0)
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int n;
		cout<<"Enter the number of children of "<<front->data<<":";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int child;
			cout<<"Enter the "<<i<<"th"<<" child of "<<front->data<<":";
			cin>>child;
			TreeNode<int>* child = new TreeNode<int>* (child);
			pendingNodes.push(child);
			front->children.push_back(child);
		}
	}
	return root;
}

void PrintTreeLevelWise(TreeNode<int>* root)
{
	cout<<root->data<<":";
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		for(i=0;i<front->children.size();i++)
		{
			cout<<front->children[i]->data<<",";
			pendingNodes.push(front->childre[i]);
		}
	}
}



int main()
{
	TreeNode<int>* root = takeInputLevelWise();
	PrintTreeLevelWise(root);
	return 0;
}