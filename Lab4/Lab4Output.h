#pragma once

#include "..\Common\Input.h"
#include "HashTable.h"
#include "Dictionary.h"

void MainMenuText();
void MenuHashTableText();
void MenuDictionaryText();
void PrintTable(HashTable* hashTable);
void PrintHashTableSearchingElement(string,string);
void PrintDictonary(Dictionary* dictonary);
void PrintEnterKey();
void PrintEnterValue();
void InsertErrorMessage();
void DeleteErrorMessage();
void OverwriteErrorMessage();
void PrintNode(Node*);
void PrintDictionarySearchingElement(string);
void FindErrorMessage();
