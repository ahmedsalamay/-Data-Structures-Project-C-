#include <iostream>
#include "tree.h"
#include "dictionary.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{
	dictionary hamada(10);
	
	ifstream file("EnglishWords.csv");

	string word = "";
	char temp;
	while (true)
	{
		file.get(temp);
		if (file.eof())	 break;
		if (temp != '\n') word += tolower(temp);
		else  hamada.add(word), word = "";
	}	   
	file.close();
	hamada.remove("pall");
	short choice;
	while (true)
	{
		puts("=================================================================");
		puts("Welcome to the spelling dictionary :) :D :");
		cout<<"\nEnter 1 to check the existance of a word in the dictionary, enter 0 to exist : ";
		cin >> choice;
		if (choice)
		{
			cout<<"Enter the word : ";
			cin >> word;
			for (unsigned int i = 0; i < word.size(); i++)word[i] = tolower(word[i]);
			if (hamada.contains(word)) puts("\nok\n");
			else puts("\nnot found\n");
		}
		else break;
	}

	puts("");
	system("pause");
	return 0;
}

