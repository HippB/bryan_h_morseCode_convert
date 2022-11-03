#include "binaryTree.h"
#include "function.h"
#include <iostream>
#include <string>

//initializes binary tree as nullptr
binaryTree::binaryTree(){
	root -> left = nullptr;
	root -> right = nullptr;

}

// this starts the binary tree with the root being the parameter
binaryTree::binaryTree(char root_data){
	root = new NodeB;
	root -> dataChar = root_data;
	root -> left = nullptr;
	root -> right = nullptr;
}

// this will set the left and right of the binary tree in parameters
binaryTree::binaryTree(char root_data, binaryTree left, binaryTree right){
	root = new NodeB;
	root -> dataChar = root_data;
	root -> left = left.root;
	root -> right = right.root;
}

// will return the height of the tree, if nullptr then tree is empty
int binaryTree::height(const NodeB* n) const{
	if (n == nullptr){ return 0; }
	else{ return 1 + std::max(height(n->left), height(n->right));}
}

// get height of tree
int binaryTree::height() const { return height(root); }

// if tree is empty
bool binaryTree::empty() const { return root == nullptr; }

char binaryTree::dataChar() { return root -> dataChar; }

binaryTree binaryTree::left() const{
	binaryTree result;
	result.root = root -> left;
	return result;
}

binaryTree binaryTree::right() const{
	binaryTree result;
	result.root = root -> right;
	return result;
}

//This will add the morse and letter equivalent into a binary tree
void binaryTree::insertMorse(std::string dataMorse, char dataChar){
	// morse code is either '.' or '-'
	NodeB* current = root;
	for(int i = 0; i < dataMorse.length(); i++){
		if(dataMorse[i] == '.'){ // moves the pointer current to the left subtree
			if(current -> left == nullptr){
				NodeB* new_node = new NodeB;
				current -> left = new_node; 
			}
			current = current -> left; 		
		} 
		else{	// moves the pointer current to the right subtree
			if(current -> right == nullptr){
				NodeB* new_node = new NodeB;
				current -> right = new_node; 
			}
			current = current -> right;
		}
	}
	if (current == nullptr){
		NodeB* new_node = new NodeB;
		current = new_node;
	}
	current -> dataChar = dataChar;	//sets the character to the current node
}

//this will traverse the binary tree using the morse code in the given text file
char binaryTree::readM(std::string dataMorse){
	NodeB* current= root;
	for(int i = 0; i < dataMorse.length(); i++){
		if(dataMorse[i] == '.'){
			current = current -> left; 
		}
		if(dataMorse[i] == '-'){
			current = current -> right;		}
	}
	return current -> dataChar;
}


