#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "../IntermediateStruct.h"
#include <stdio.h>
#include <vector>

class BinaryTree {
	private:
		struct TreeNode {
			std::vector<char *> words;
			int count;
			TreeNode *left;
			TreeNode *right;
		};
		TreeNode *root;

		void insert(TreeNode *&, TreeNode *&);

		void displayInOrder(TreeNode *, size_t) const;
		void displayPreOrder(TreeNode *, size_t) const;
		void displayPostOrder(TreeNode *, size_t) const;
		
	public:
		BinaryTree() {
			root = nullptr;
		}

		void insertNode(IntermediateRep);

		void displayInOrder()const { // overload
			displayInOrder(root, 0); // helper function essentially that calls displayInOrder
		}
		void displayPreOrder()const {
			displayPreOrder(root, 0);
		}
		void displayPostOrder()const {
			displayPostOrder(root, 0);
		}



		
};


#endif
