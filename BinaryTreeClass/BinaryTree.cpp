#include "BinaryTree.h"

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if(nodePtr == nullptr) {
		nodePtr = newNode; //insert the node if there is nothing there
	}
	else if(newNode->count < nodePtr->count)
		insert(nodePtr->left, newNode);
	else if(newNode->count > nodePtr->count)
		insert(nodePtr->right, newNode);
	else {
		printf("%s and %s have the same count\n", nodePtr->word, newNode->word);
		if(newNode->word < nodePtr->word){
			printf("nodePtr: %s is larger then %s\n", nodePtr->word, newNode->word);
			insert(nodePtr->left, newNode);
		}
		else {
			printf("nodePtr: %s is smaller then %s\n", nodePtr->word, newNode->word);
			insert(nodePtr->right, newNode);
		}
	}
		
}

void BinaryTree::insertNode(IntermediateRep inter) {
	TreeNode *newNode = nullptr;
	
	newNode = new TreeNode;
	newNode->word = inter.word;
	newNode->left = newNode->right = nullptr;
	newNode->count = inter.count;

	insert(root, newNode);
}

void BinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		displayInOrder(nodePtr->left);
		printf("%s: %d\n", nodePtr->word, nodePtr->count);
		displayInOrder(nodePtr->right);
	}
}
