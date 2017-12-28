#include <iostream>
#include <string>
using namespace std;
#include "binary_tree.h"
#include "huffman_implementation.h"

string validate() {

	string text =  "";

	while(text.empty()) {
		
		getline(cin, text);
		
		if(text.empty())
			cout << "You have to type something to compress!" << endl;
	}

	return text;
}

int* get_count(string text) {

	int* count = new int[256];
	char ch;

	for(int i = 0 ; i < text.size() ; i++) {
		ch = text[i];
		count[ch]++;
	}

	return count;
}

int main() {

	cout << "\nWelcome to Huffman code generator!" << endl;
	cout << "----------------------------------" << endl;
	cout << "\nEnter the text to generate Huffman code: ";

	string text = validate();

	int* count = get_count(text);

	huffman(text, count);
}