#ifndef node_h
#define node_h
#include <string>
using std::string;

class node
{
	string val;
	node*left;
	node*right;

public:
	node();
	node(string &val, node*left,node*right);

	void set_val(string &x);
	void set_right(node* x);
	void set_left(node *x);

	string get_val();
	node* get_right();
	node* get_left();

	~node();
	friend class tree;
};

#endif