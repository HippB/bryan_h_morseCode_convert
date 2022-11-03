#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

class NodeB{
private:
	char dataChar;
    std::string dataMorse;
    NodeB* left;
    NodeB* right;
friend class binaryTree;
};

//the binary tree class from textbook where each NodeB has two children
class binaryTree{
public:
	binaryTree();	//empty tree
	binaryTree(char root_data);	//with NodeB that is the root
	// with root, and left and right subtrees
	binaryTree(char root_data, binaryTree left, binaryTree right);
	binaryTree left() const; //gets left side of subtree
	binaryTree right() const; //gets right side of subtree
	int height() const; // height of tree
	bool empty() const; // checks if tree is empty
	
	//std::string dataM() const; //the morse data input
	char dataChar(); // the character data input
	
	void insertMorse(std::string dataMorse, char dataChar);
	char readM(std::string dataMorse);

private:
int height(const NodeB* n) const;	//returns height of subtree
NodeB* root;	
};

#endif
