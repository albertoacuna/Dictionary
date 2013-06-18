#include <vector>
#include <iostream>
#include <string.h>
using namespace std;


class Dictionary{
  	vector< vector<const char*> > dict;

	public:
		Dictionary();
		void Insert(const char* str);
		void Delete(const char* str);
		const char* Search(const char* str);
		int size();
		int hash(const char*);

		void printAll();
};
