#ifndef tree_h
#define tree_h
#include "node.h"
#include <iostream>
using std::cout;
class tree
{

private:
	node* root;
	node* left;
	node *right;
	int count = 0;
public:
	tree();
	tree(node*root);
	bool add(string &val);
	bool remove(string &val);
	bool contains(string &val);
	int size();
	void print(node *x);
	void InOrder();

	void delete_all(node *x);
	~tree();
};

#endif
