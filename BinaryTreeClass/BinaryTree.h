#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "../IntermediateStruct.h"
#include <stdio.h>
#include <vector>

class BinaryTree {
	private:
		struct TreeNode {
			vector<char *> words;
			int count;
			TreeNode *left;
			TreeNode *right;
		};
		TreeNode *root;

		void insert(TreeNode *&, TreeNode *&);
		void displayInOrder(TreeNode *) const;
		
	public:
		BinaryTree() {
			root = nullptr;
		}

		void insertNode(IntermediateRep);

		void displayInOrder()const { // overload
			displayInOrder(root); // helper function essentially that calls displayInOrder
		}
		
};


#endif
