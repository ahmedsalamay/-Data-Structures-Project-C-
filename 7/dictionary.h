#ifndef dictionary_h
#define dictionary_h
#include "tree.h"

class dictionary
{
private:
	tree **arr;
	int capacity;
public:
	dictionary(int capacity);
	int get_hash(string &val);
	bool add(string val);
	bool remove(string val);
	bool contains(string val);
	int size();
	~dictionary();
};

#endif