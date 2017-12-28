#ifndef huffman_implementation

	#define huffman_implementation

	#include "binary_tree.h"
	#include <string>
	#include <unordered_map>

	class huffman {

	private:

		string text;
		int count[256];

	public:

		huffman(string text, int* count) {

			this->text.append(text);

			for(int i = 0 ; i < 256 ; i++) 
				this->count[i] = count[i];

			//TODO create priority_queue
		}

	};

#endif