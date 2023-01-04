#include "AVLTree.h"

/*	Function:  Default constructor
                -- Creates an object of the AVLTree class with default values.
	Inputs:    void
	Returns:   void
	Side effects:  The new object of AVLTree Class is initialized which has
                    numNodes=0 and root=nullptr            
*/
AVLTree::AVLTree()
{
    numNodes=0;
    root=nullptr;
}

/*	Function:  Copy constructor
                -- Creates an object of AVLTree class whose value is initalized by another object of same class
                    which is passed as an arguments ie it makes deep copy. Uses function cloneBinaryTree(AVLTreeNode*)
	Inputs:     const AVLTree& tree
                --Reference to the Object of AVLTree Class
	Returns:   void
	Side effects:  The new object of AVLTree Class is created and initialized with the value of
                    the object which is passed as argument by making deep copy.
                                
*/
AVLTree::AVLTree( const AVLTree& tree )
{
  numNodes=tree.numNodes;
  this->root = cloneBinaryTree( tree.root );
}


/*	Function:  cloneBinaryTree() 
                -- copy avltree to another avltree
	Inputs:     AVLTreeNode* subRoot
                -- Reference to the Object of AVLTreeNode Class
	Returns:   Reference to the root of copied avl tree
	Side effects:  Copy avl tree and return root node of the copied tree.       
*/
AVLTree::AVLTreeNode* AVLTree::cloneBinaryTree(AVLTreeNode* subRoot)
{
    if ( subRoot == nullptr )
    {
      return nullptr;
    }
    AVLTreeNode* newNode= new AVLTreeNode(subRoot->key,subRoot->value);
    newNode->left=cloneBinaryTree(subRoot->left);
    newNode->right=cloneBinaryTree(subRoot->right);
    return newNode;
}


/*	Function:  Destructor
                -- Release the memory allocated to the object of AVLTree Class. Uses the function deleteNode()
	Inputs:     void
	Returns:   void
	Side effects:  Destroy the objects by releasing the allocated memory.             
*/
AVLTree::~AVLTree()
{
  deleteNode(root);
}

//Helper function for destructor to release the memory occupied by the nodes
void AVLTree::deleteNode(AVLTreeNode* current)
{
  if (current == nullptr)
      return;
  deleteNode(current -> left);
  deleteNode(current -> right);
  delete current;
}

/*	Function:  operator= 
                -- Overload = operator
	Inputs:     &source
                -- Reference to the Object of AVLTree Class
	Returns:   Reference to the copied sequence
	Side effects:  Copy the value from object that is passed as argument to the object that called it.       
*/
AVLTree& AVLTree::operator=( const AVLTree& source )
{
  deleteNode(root);
  numNodes=source.numNodes;
  this->root = cloneBinaryTree( source.root );
  return (*this);
}



/*	Function:  insert
                -- add AVLTree node with provided values
	Inputs:    key--unique data for each value( int)
                value -- value of the key(string)
	Returns:   True if node is inserted successfully, false otherwise
	Side effects:  New AVLTree node is added with given values and ponters are updated
*/
bool AVLTree::insert(int key, string value)
{
  bool a= insert(key,value,root);
  return (a);
}

//Inserting through recursion
bool AVLTree::insert(int key, string value, AVLTreeNode *& subRoot)
{
    bool result;
    if (subRoot == nullptr) 
    {
      subRoot = new AVLTreeNode(key,value);
      numNodes++;
      return true;
    }

    if (key < subRoot -> key)
    {
      result = insert(key,value,subRoot -> left);
    } 
    else if (key > subRoot -> key) 
    {
      result = insert(key,value,subRoot -> right);
    } 
    else
    {      
      //No duplicate keys
      return false;
    }

    if (result == false) return result;
    
        int bf = getBalanceFactor(subRoot);
        // Left Left Case  
        if (bf > 1 && key < subRoot -> left -> key)
        {
          rightRotate(subRoot);
          return true;
        }
        

        // Right Right Case  
        else if (bf < -1 && key > subRoot -> right -> key)
        {
          leftRotate(subRoot);
          return true;
        }
          

        // Left Right Case  
        else if (bf > 1 && key > subRoot -> left -> key) 
        {
          leftRotate(subRoot->left);
          rightRotate(subRoot);
          return true;
        }

        // Right Left Case  
        else if (bf < -1 && key < subRoot -> right -> key) 
        {
          rightRotate(subRoot -> right);
          leftRotate(subRoot);
          return true;
        }
        else
        return true;
}



/* Function: getHeight
        Inputs: void
        Returns: The height of the AVL tree(int)
*/
int AVLTree::getHeight()
{
  return(height(root));
}


// Finding the height of the node through recursion
int AVLTree::height(AVLTreeNode* node) 
{
	if (node==nullptr)
	{
		return(-1);
	}
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return (lheight + 1);
		else return (rheight + 1);
	}
}


/*	Function:  getSize
                -- find the size of the AVLTree
	Inputs:    void
	Returns:   number of nodes in the AVLTree (int)
	Side effects:  Number of nodes in the AVLTree is returned
*/
int AVLTree::getSize()
{
    return(numNodes);
}

/* Fuction: find
            -- find the node with appropriate key and value
    Inputs: key and value pair
    Returns: True if it found the node with appropriate key and value pair, false otherwise
    Side effects: returns true if success and false if failure
*/
bool AVLTree::find(int key, string& value)
{
  return(find(key,value,root));
}

// Recursive helper function for find() 
bool AVLTree::find(int key, string& value, AVLTreeNode* current)
{ 
  if (current == NULL) 
    return false; 
  else if (key == current->key)
  {
    value=current->value;
    return true; 
  } 
  else if (key > current->key) 
    return find(key, value, current->right); 
  else 
    return find(key,value, current->left); 
} 

/* Function: findRange
            --return the vector of the values in the range of given keys
    Inputs: lowkey and highkey
    Returns: vector of values of the key in range lowkey<=key<=highkey
    Side effects: Vector of the values is returned if no values are found empty vector is returned
*/
vector<string> AVLTree::findRange(int lowkey, int highkey)
{
  vector<string> list;
  helpRange(root,lowkey,highkey,list); 
  return list;
}

//helper function for range function
void AVLTree::helpRange(AVLTreeNode * current, int lowkey, int highkey,vector<string>& list)
{
    if (current == NULL)
      return ;
    else
    {
      helpRange(current -> right,lowkey, highkey,list);
      helpRange(current -> left,lowkey,highkey,list);
      if (lowkey <= current->key && current->key <=highkey)
        list.push_back(current->value);
    }
}

/* Function: operator<<
    Inputs: referece of ostream object and reference of AVLTree object
    Returns: reference of ostream object
    Side effects: overload << operator so that objects of AVLTree can be printed
*/
ostream& operator<<(ostream& os,const AVLTree& me)
{
  me.printInGoodFormat(me.root,5);
  return(os);
}

//helper function for printing in proper tree format.
void AVLTree::printInGoodFormat(AVLTreeNode * current, int space) const
{
  if (current == NULL)
      return;
  space += 10; // Increase gap between levels 
  printInGoodFormat(current -> right, space);
  cout << endl;
  for (int i = 10; i < space; i++) 
    cout << " "; 
  cout << current -> key<<","<<current->value << "\n";
  printInGoodFormat(current -> left, space); 
}


// Function to get Balance factor of node using recursion  
int AVLTree::getBalanceFactor(AVLTreeNode * current) 
{
	if (current == nullptr)
		return -1;
	return (height(current->left) - height(current->right));
}


//Implementation of the right rotation
void AVLTree::rightRotate(AVLTreeNode*& pNode) 
{
	AVLTreeNode * hNode = pNode -> left;
	AVLTreeNode * tNode = hNode -> right;
	hNode -> right = pNode;
  pNode=pNode->left;
	hNode->right -> left = tNode;
}


//Implementation of left rotation
void AVLTree::leftRotate(AVLTreeNode*& pNode) 
{
	AVLTreeNode * hNode = pNode -> right;
	AVLTreeNode * tNode = hNode -> left;
	hNode -> left = pNode;
  pNode=pNode->right;
	pNode->left -> right = tNode;
  
}