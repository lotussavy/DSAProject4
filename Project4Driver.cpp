/*
Name: Kamal Acharya
UID:U00997907
Project Name:  Indexing with AVL Trees
Description:
AVL tree is implemented as a map data type which contains key value pair where key is an integer and value is string 
type. It support insertion, finding of particular node, rejection of duplicate keys, overloading of = and >> operator.
Prototypes of the class along with their data and member fucntion are given in the AVLTree.h. 
The details of all the member fucntion is implemented in the AVLTree.cpp.
Project4Driver.cpp is used to test all the function that are implemented
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "AVLTree.h"

using namespace std;

void memoryLeakage()
{
	AVLTree tree;
	for (int i = 0; i < 100000; i++)
  	{
    	tree.insert(i,"hello");
  	}
}
 int main()
 {
	AVLTree tree,tree1;
	//cout<<tree.getHeight();
	//cout<<tree.getSize();
	tree.insert(50, "Fifty");
	//cout<<tree.getHeight();
	// This should print 0, because it returns false (no duplicates allowed):
	tree.insert(50, "Another fifty");
	tree.insert(100, "One hundred");
	tree.insert(200, "Two hundred");//single rotate left
	//cout << tree.getHeight();
	string result;
	cout<<tree.find(-1,result);
	

	// tree1=tree;
	// AVLTree tree2(tree1);
	// tree.insert(999,"tree");
	// tree1.insert(888,"tree1");
	// tree2.insert(777,"tree2");
	// cout << tree << endl;
	// cout<<tree1;
	// cout<<tree2;
	// cout << tree.insert(40, "Fourty");
	// cout << tree.insert(30, "Thirty");//single rotate right
	// cout << tree.insert(150, "One hundred fifty");
	// cout << tree.insert(175, "One hundred seventy-five");//double rotate right
	// cout << tree.insert(35, "Thirty-five");
	// cout << tree.insert(34,"Thirty-four");//double rotate left
	// cout << tree.insert(50, "Fifty yet again");//should be 0
	// cout << tree.insert(34, "Thirty-four again");//should be 0;
	// cout << tree.insert(200, "Two hundred");//should be 0;
	// //Expect: 1011111111000

	// 	cout << "\n\n";
	
	// cout << tree << endl;
	// cout << tree.getSize() << endl;//9
	// cout << tree.getHeight() << endl;//3

	// string result;

	// cout << tree.find(50, result) << endl;//1
	// cout << result << endl; //Fifty

	// cout << tree.find(40, result) << endl;//1
	// cout << result << endl; //Fourty

	// cout << tree.find(175, result) << endl;//1
	// cout << result << endl; //One hundred seventy-five

	// cout << tree.find(600, result) << endl; //0

	// vector<string> vec = tree.findRange(30, 200);//all of it
	// for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {	
	// 	cout << *it << endl;
	// }
	// cout << "\n\n" << endl;

	// vec = tree.findRange(100, 200);//right subtree
	// for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
	// 	cout << *it << endl;
	// }
	// cout << "\n\n" << endl;
	// vec = tree.findRange(30, 100);//left subtree
	// for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
	// 	cout << *it << endl;
	// }
	// cout << "\n\n" << endl;

	//code for the memory leakage check
//  		string answer;
//   cout << "Type anything to continue" << endl;
//   cin >> answer;
// cout << "Type anything to continue" << endl;
// cin >> answer;
// for (int i = 0; i < 4; i++)
// {
// 	memoryLeakage();
// }

	 return(0);
 }