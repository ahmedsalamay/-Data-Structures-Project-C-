#include "dictionary.h"

//======================================[[Constructor]]===============================
dictionary::dictionary(int capacity)
{
	arr = new tree *[capacity];
	this->capacity= capacity;
	for (int i = 0; i < capacity; i++)
		arr[i] = new tree;
}
//====================================[[Hash Functions]]================================
//Was going to use it but no :v
/*int dictionary::get_hash(string &val)
{
	int seed = 77;
	unsigned long hash = 0;
	for (unsigned int i = 0; i < val.length(); i++)
		hash = (hash * seed) + val[i];
	
	return hash % size;
}
*/
int dictionary::get_hash(string &val)
{
	int sum = 0;
	for (unsigned int i = 0; i < val.size(); i++)
		sum += int(val[i]);

		return sum%capacity;
}
bool dictionary::add(string val)
{
	return arr[get_hash(val)]->add(val);
}
bool dictionary::remove(string val)
{
	return arr[get_hash(val)]->remove(val);
}
bool dictionary::contains(string val)
{
	return arr[get_hash(val)]->contains(val);
}
int dictionary::size()
{
	int sum = 0;
	for (unsigned int i = 0; i < capacity; i++)
		sum += arr[i]->size();
	return sum;
}

dictionary::~dictionary()
{
	delete arr;
}
