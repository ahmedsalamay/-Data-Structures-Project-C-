#include "tree.h"

//====================================[[Constructors]]==========================================
tree::tree()
{
	root = '\0';
	left = '\0';
	right = '\0';
}

tree::tree(node*root)
{
	this->root = root;
}
//=========================================[[Add]]===============================================
bool tree::add(string &val)
{
	if (root == '\0')
	{
		root = new node(val,'\0','\0');
		count++;
		return 1;
	}
	node *current = root, *previous;
	while (true)
	{
		if (current->val > val)
		{
			previous = current;
			current = current->left;
			if (current == '\0')
			{
				current = new node(val, '\0', '\0');
				previous->left = current;
				//puts("Done Left\n");
				count++;
				return 1;
			}
			continue;
		}
		else if (current->val < val)
		{
			previous = current;
			current = current->right;
			if (current == '\0')
			{
				current = new node(val, '\0', '\0');
				previous->right = current;
				//puts("Done Right\n");
				count++;
				return 1;
			}
			continue;
		}
		else {
			//puts("already there :v ");
			return 0;
		}
	}
}
//=========================================[[Remove]]============================================
bool tree::remove(string &val)
{

	if (root == '\0')
	{
		puts("Tree is empty");
		return 0;
	}
	node *current = root, *previous='\0';
	while (true)
	{
		if (current->val > val)
		{
			previous = current;
			current = current->left;
			if (current == '\0') return 0;
			else continue;
		}
		else if (current->val < val)
		{
			previous = current;
			current = current->right;
			if (current == '\0') return 0;
			continue;
		}
		else 
		{
			//First Case  ==> my current node has no children
			if (current->left == '\0'&&current->right == '\0')
			{
				if (previous != '\0')
				{
					if (previous->right == current)   previous->right = '\0';
					else previous->left = '\0';
				}
				else root = previous;
				
				count--;
				return 1;
			}
			//Second Case  ==> my current node has one child and it is on its left
			else if (current->left != '\0'&&current->right == '\0')
			{
				if (previous->right == current)   previous->right = current->left;
				else previous->left = current->left;
			
				count--;
				return 1;
			}
			//third Case  ==> my current node has one child and it is on its right
			else if (current->right != '\0'&&current->left == '\0')
			{
				if (previous->right == current)   previous->right = current->right;
				else previous->left = current->right;
			
				count--;
				return 1;
			}  
			//Fourth case and the worst one :3 my current node has two children :3
			//try to get the node with minimum value to replace my current node	from the left branch
			else
			{
				previous = current;
				node* temp = current;
				current = current->right;
				while (true)
				{
					//We reached the node with minimum value and it has no children
					if (current->left == '\0'&&current->right == '\0')
					{
						previous->val = current->val;
						if (temp->right == current) temp->right = '\0';
						else temp->left = '\0';

						count--;
						return 1;
					}
					//We reached the node with minimum value and it has a child on its right
					else if (current->left == '\0'&&current->right != '\0')
					{
						previous->val = current->val;
						if (temp->right == current) temp->right = current->right;
						else temp->left = current->right;
					
						count--;
						return 1;
					}
					temp = current, current = current->left;
				}
			}

		}
	
	}
}
//========================================[[Contains]]===========================================
bool tree::contains(string &val)
{
	if (root == '\0') return 0;

	node *current = root, *previous;
	while (true)
	{
		if (current->val > val)
		{
			previous = current;
			current = current->left;
			if (current == '\0') return 0;
			else continue;
		}
		else if (current->val < val)
		{
			previous = current;
			current = current->right;
			if (current == '\0') return 0;
			else continue;
		}
		else
			return 1;
	}
}
//======================================[[Size of tree]]=========================================
int tree::size()
{
	return count;
}
//==========================================[[Print]]============================================
void tree::print(node *x)
{
	node *p = x->left;

	if (p != '\0') print(p);
	cout << x->val << " ";

	p = x->right;
	if (p != '\0') print(p);

}
void tree::InOrder()
{
	if (root != '\0')
		print(root);
}
//======================================[[Destructor]]===========================================
tree::~tree()
{ 
	delete root;
}

