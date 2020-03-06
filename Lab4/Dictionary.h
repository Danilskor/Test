#pragma once

#include <string>
#include "HashTable.h"
#include "Dictionary.h"

using namespace std;

struct Dictionary
{
	HashTable* Table;
};

const int START_DICTIONARY_SIZE = 5;

Dictionary* CreateDictionary();
string FindEntry(Dictionary*, string);
bool InsertEntry(Dictionary*, Node*, string);
void DeleteEntry(Dictionary*, string);
void DeleteDictionary(Dictionary*);