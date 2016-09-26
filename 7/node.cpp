#include "node.h"


node::node()
{
	val = "";
	right = '\0';
	left = '\0';
}
node::node(string &val, node*left, node*right)
{
	this->val = val;
	this->left = left;
	this->right = right;
}

void node::set_val(string &x)
{
	val = x;
}
void node::set_right(node* x)
{
	right = x;
}
void node::set_left(node *x)
{
	left = x;
}

string node::get_val()
{
	return val;
}
node* node::get_right()
{
	return left;
}
node* node::get_left()
{
	return left;
}
node::~node()
{
	delete left;
	delete right;
}