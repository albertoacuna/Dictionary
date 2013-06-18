#include "Dictionary.h"

int main(){
  Dictionary dict;
	dict.Insert("Hello");
	dict.Insert("Cthullu");
	dict.Insert("monkey");
	dict.Insert("salem");
	dict.Insert("of");
	dict.Insert("narc");
	dict.Insert("Nero");
	dict.Insert("zulu");
	dict.Insert("nether");
	dict.Insert("poland");
	const char* word = dict.Search("poland");
	cout << word << endl;
	dict.Delete("poland");

	dict.printAll();


}
