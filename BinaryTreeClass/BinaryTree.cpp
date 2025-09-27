#include "BinaryTree.h"



void BinaryTree::fileInitHelper(FILE **filePtr, const char *extension) {
	size_t newSize = strlen(baseFileName) + strlen(extension);
	char *fullFileName = (char *)malloc(newSize + 1);
	strcpy(fullFileName, baseFileName);
	strcat(fullFileName, extension);
	*filePtr = fopen(fullFileName, "w");
	if(!*filePtr) {
		perror("fopen failed");
	}
	free(fullFileName);
}

void BinaryTree::buildTree(std::vector<IntermediateRep> interArr) {
	for(size_t i = 0; i < interArr.size(); i++) {
		insertNode(interArr[i]);
	}
}



void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if(nodePtr == nullptr) {
		nodePtr = newNode; //insert the node if there is nothing there
	}
	else if(newNode->count < nodePtr->count)
		insert(nodePtr->left, newNode);
	else if(newNode->count > nodePtr->count)
		insert(nodePtr->right, newNode);
	else {
		// If two words have the same count append the new node to the equal nodes word list
		nodePtr->words.push_back(newNode->words[0]);
	}
		
}

void BinaryTree::insertNode(IntermediateRep inter) {
	TreeNode *newNode = nullptr;
	
	newNode = new TreeNode;
	newNode->words.push_back(inter.word);
	newNode->left = newNode->right = nullptr;
	newNode->count = inter.count;

	insert(root, newNode);
}

void BinaryTree::displayInOrder(TreeNode *nodePtr, size_t depth) const {
	if(nodePtr) {
		displayInOrder(nodePtr->left, depth+1);

		for(size_t i = 0; i < depth * 2; i++) fprintf(inOrderFile, " ");

		fprintf(inOrderFile, "%d: ", nodePtr->count);
		for(size_t i = 0; i < nodePtr->words.size(); i++) {
			fprintf(inOrderFile, "%s ", nodePtr->words[i]);
		}
		fprintf(inOrderFile, "\n");


		displayInOrder(nodePtr->right, depth+1);
	}
}


void BinaryTree::displayPreOrder(TreeNode *nodePtr, size_t depth) const {
	if(nodePtr) {
		for(size_t i = 0; i < depth * 2; i++) fprintf(preOrderFile, " ");

		fprintf(preOrderFile, "%d: ", nodePtr->count);
		for(size_t i = 0; i < nodePtr->words.size(); i++) {
			fprintf(preOrderFile, "%s ", nodePtr->words[i]);
		}
		fprintf(preOrderFile, "\n");
		displayPreOrder(nodePtr->left, depth+1);
		displayPreOrder(nodePtr->right, depth+1);

	}
}

void BinaryTree::displayPostOrder(TreeNode *nodePtr, size_t depth) const {
	if(nodePtr) {
		displayPostOrder(nodePtr->left, depth+1);
		displayPostOrder(nodePtr->right, depth+1);
		for(size_t i = 0; i < depth * 2; i++) fprintf(postOrderFile, " ");

		fprintf(postOrderFile, "%d: ", nodePtr->count);
		for(size_t i = 0; i < nodePtr->words.size(); i++) {
			fprintf(postOrderFile, "%s ", nodePtr->words[i]);
		}
		fprintf(postOrderFile, "\n");

	}
}

