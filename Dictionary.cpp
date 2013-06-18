#include "Dictionary.h"

Dictionary::Dictionary(){
  for(int i= 0; i < 5; i++){
		dict.push_back(vector<const char*>());
	}
}

void Dictionary::printAll(){
			for(vector<vector<const char*> >::iterator i = dict.begin(); i != dict.end();i++){
					cout << distance(dict.begin(), i) << " - ";
				for(vector<const char*>::iterator j = i->begin(); j != i->end();j++){
					cout << " '"<< *j << "' ";
				}
				cout << endl;

			}
		}

int Dictionary::size(){
	return dict.size();
}

void Dictionary::Insert(const char* str){
			int hashIndex;

			hashIndex = hash(str);

			dict[hashIndex].push_back(str);
}

void Dictionary::Delete(const char* str){
	int index = hash(str);

	vector<const char*>::iterator it;

	for(it = dict[index].begin(); it != dict[index].end() && strcmp(str, *it) != 0; it++);
	if(it == dict[index].end() ){
		cout << "Delete: Key not found" << endl;
	}
	else{
		dict[index].erase(it);
		cout << "Delete: Key deleted" << endl;
	}
}

const char* Dictionary::Search(const char* str){
	int index;
	const char* ptr;
	vector<const char*>::iterator it;
	index = hash(str);


	if(dict[index].size() == 0){
		ptr = NULL;
		cout << "Search: Key not found" << endl;
	}
	else{
		for(it = dict[index].begin(); it != dict[index].end() && strcmp(str, *it) != 0; it++);

		if(it == dict[index].end()){
			ptr = NULL;
			cout << "Search: Key not found" << endl;
		}
		else{
			ptr = *it;
			cout << "Search: Key found" << endl;
		}
	}


	return ptr;
}

int Dictionary::hash(const char* str){
	long intValue = 0;
	int hashIndex;
	int modValue = 5;

	while(*str != '\0'){
		intValue += (int)(*str);
		str++;
	}

	hashIndex = intValue % modValue;

	return hashIndex;
}
