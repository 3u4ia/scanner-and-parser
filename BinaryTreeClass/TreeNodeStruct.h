#ifndef TREENODESTRUCT_H 
#define TREENODESTRUCT_H
struct TreeNode {
	std::vector<char *> words;
	int count;
	TreeNode *left;
	TreeNode *right;
};
#endif
