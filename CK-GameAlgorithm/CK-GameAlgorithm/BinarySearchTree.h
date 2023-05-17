#pragma once
using namespace std;

struct Node 
{
	int data;
	Node* left;
	Node* right;
	Node(int d) :
		data(d), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
	Node* node;

public:
	BinarySearchTree() { }
	~BinarySearchTree() { }

	Node* insertNode(Node* T, int key);
	Node* deleteNode(Node* T, int key);
	Node* search(Node* T, int key);
};

Node* BinarySearchTree::insertNode(Node* T, int key)
{
	if (T == nullptr) 
	{
		T = new Node(key);
	}
	else if (T->data > key) 
	{
		T->left = insertNode(T->left, key);
	}
	else 
	{
		T->right = insertNode(T->right, key);
	}

	return T;
}

Node* BinarySearchTree::deleteNode(Node* T, int key)
{
	// there is no data
	if (T == nullptr) 
	{
		return nullptr;
	}
	// move left
	else if (T->data > key) 
	{
		T->left = deleteNode(T->left, key);
		return T;
	}
	// move right
	else if (T->data < key) {
		T->right = deleteNode(T->right, key);
		return T;
	}
	// found data
	else if (T->data == key)
	{
		// Case 1 : The node is leaf node.
		if ((T->left == nullptr) && (T->right == nullptr))
		{
			delete T;

			return nullptr;
		}
		// Case 2 : The node has one children.
		else if (T->left == nullptr)
		{
			Node* Temp = T->right;
			delete T;

			return Temp;
		}
		// Case 2 : The node has one children.
		else if (T->right == nullptr)
		{
			Node* Temp = T->left;
			delete T;

			return Temp;
		}
		// Case 3 : The node has two children.
		else
		{
			Node* rightMin = T->right;

			while (rightMin->left != nullptr)
			{
				rightMin = rightMin->left;
			}

			T->data = rightMin->data;
			deleteNode(rightMin, rightMin->data);

			return T;
		}
	}
}

Node* BinarySearchTree::search(Node* T, int key) {
	if (T == nullptr) 
	{
		return nullptr;
	}
	else if (T->data == key) 
	{
		return T;
	}
	else if (T->data > key) 
	{
		search(T->left, key);
	}
	else 
	{
		search(T->right, key);
	}
}