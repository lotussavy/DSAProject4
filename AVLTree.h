// FILE: AVLTree.h
// CLASS PROVIDED: AVLTree
//
//
// CONSTRUCTORS for the AVLTree class:
//	AVLTree()
//		Postcondition: Creates an empty AVLTree (numNodes == 0)
//
//	AVLTree( const AVLTree& AT )
//	Uses the function static AVLTreeNode* cloneBinaryTree(AVLTreeNode* root)
//		Postcondition: Creates a (deep) copy of AVLTree AT.
//
// DESTRUCTOR for the AVLTree class
//	~AVLTree()
//	Uses fucntion void deleteNode(AVLTreeNode*)
//		Postcondition: Destroys all nodes in the AVLTree and release the memory associated with the Tree
//
//
//	void deleteNode(AVLTreeNode*)
//		Postcondition: Destroy all the nodes in the AVLTree recursively whose root node as passed.
//
// INFORMATIONAL / ACCESSOR MEMBER FUNCTIONS for the AVLTree class:
//   int getSize( )
//     Postcondition: The return value is the number of nodes in the AVLTree.
//
//  int getHeight()
//     Postcondition: The return value is the height of the AVL tree. It uses function height(AVLTreeNode* node) as 
//						the helper.
//
//
//	int height(AVLTreeNode* node)
//		Postcondition:Return the height of the tree that has node as the root node.
//
//
//
//	int getBalanceFactor(AVLTreeNode*)
//		Postcondtion: returns the balance factor of the node which is passed as argument
//
//
//
//
//	vector<string> findRange(int lowkey, int highkey)
//	Uses helpRange(AVLTreeNode * r,int lowkey, int highkey,vector<string>& list) as helper function
//		Precondtion: Valid range of keys
//		Postcondition: Return vector of the values within the range of the keys otherwise empty vector
//
//	void helpRange(AVLTreeNode * r,int lowkey, int highkey,vector<string>& list)
//		Precondtion: Valid range of keys
//		Postcondition: Return vector of the values within the range of the keys otherwise empty vector
//
//	bool find(int key, string& value)
//	Use function find(int key, string& value, AVLTreeNode* current) as the helper function	
//		Precondition: key to find and reference to insert value corresponding to the key
//		Postcondition: Return true and update the value with the value of node if key exist. Otherwise return false
//						and value can contain any garbage value. 
//
//	bool find(int key, string& value, AVLTreeNode* current)
//		Postcondtion: Return true and update the value with the value of node if key exist. Otherwise return false
//						and value can contain any garbage value.
//
//
//
//	friend ostream& operator<<(ostream& os, const AVLTree& me)
//	Uses the function void printInGoodFormat(AVLTreeNode *root, int space) const
//		Postcondition: Overload << operator so that it can print AVLTree object in appropriate format 
//	
//
//	void printInGoodFormat(AVLTreeNode *root, int space) const
//		Postcondition: print the AVLTree with the root node as tree in appropriate format using the space integer
//
//
//
// MUTATOR MEMBER FUNCTIONS for the AVLTree class:
//	AVLTree& operator=( const AVLTree& tree )
//	Uses the function static AVLTreeNode* cloneBinaryTree(AVLTreeNode* root) and void deleteNode(AVLTreeNode*)
//		Postcondition: The current AVLTree is released and replaced by a (deep) copy of AVLTree (tree).
//		A reference to the copied AVLTree is returned.
//
//
//	static AVLTreeNode* cloneBinaryTree(AVLTreeNode* root)
//		Postcondtion: Create deep copy of the tree whose rootnode is passed as root and return the root node of the
//						copied tree.
//
//
//
//	bool insert( int key, string value )
//	Uses the function getBalanceFactor(AVLTreeNode*), rightRotate(AVLTreeNode*& pNode) and leftRotate(AVLTreeNode*& pNode)
//		Precondition: No duplicate key.
//		Postcondition: Tree node with given key-value pair is added to the tree if no duplicates
//		
//						
//	bool insert(int key, string value, AVLTreeNode *&)
//	Postcondtion: Insert the node key-value if no duplicate keys. Maintain balance by using the functions
//						
//
//
//	
//	void rightRotate(AVLTreeNode*& pNode)
//		Precondtion: valid probleme Node as pNode in the argument
//		Postcondition: Perform right rotation in the pNode.
//
//
//	void leftRotate(AVLTreeNode*& pNode)
//		Precondtion: valid probleme Node as pNode in the argument
//		Postcondition: Perform left rotation in the pNode.


#pragma once

#include <iostream>
#include <exception>
#include<string>
#include<vector>

using namespace std;

class AVLTree
{

private:
	class AVLTreeNode {
	public:
		AVLTreeNode *left;
		AVLTreeNode *right;
		int key;
		string value;

		AVLTreeNode() {
			left = nullptr;
			right = nullptr;
			key=0;
			value="";
		}

		AVLTreeNode(int key, string value, AVLTreeNode* rptr=nullptr, AVLTreeNode* lptr=nullptr) {
			right = rptr;
			left = lptr;
			this->key = key;
			this->value=value;
		}



		~AVLTreeNode() {
		};

	};
	
	AVLTreeNode *root;
	int numNodes;   // Number of nodes in the AVLTree

public:

	AVLTree();					// creates a AVLTree

	AVLTree( const AVLTree& tree );					// create a AVLTree from the existing AVLTree s 
	~AVLTree();									// destroys the AVLTree

	AVLTree& operator=( const AVLTree& s );		// assign AVLTree s to the AVLTree

	bool insert( int key, string value );		// insert the node with key and value
	

	int getSize();
	int getHeight();
	bool find(int key, string& value);
	vector<string> findRange(int lowkey, int highkey);
	friend ostream& operator<<(ostream& os, const AVLTree& me);
	void printInGoodFormat(AVLTreeNode *root, int space) const;
	static AVLTreeNode* cloneBinaryTree(AVLTreeNode* root);
	bool insert(int key, string value, AVLTreeNode *&);
	int height(AVLTreeNode* node);
	bool find(int key, string& value, AVLTreeNode* current);
	void helpRange(AVLTreeNode * r,int lowkey, int highkey,vector<string>& list);
	void deleteNode(AVLTreeNode*);
	int getBalanceFactor(AVLTreeNode*);
	void rightRotate(AVLTreeNode*& pNode);
	void leftRotate(AVLTreeNode*& pNode);

};  // End of class AVLTree



