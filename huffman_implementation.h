#ifndef huffman_implementation

	#define huffman_implementation

	#include "binary_tree.h"
	#include "priority_queue.h"
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

			create_heap();		
		}

		void create_heap() {

			PQ min_heap;

			for(int i = 0 ; i < 256 ; i++) {

				if(count[i] != 0) {
					
					char ch[1] = {(char) i};
					
					string to_push = "";
					to_push.append(ch);

					BT* node = new BT(count[i], to_push);

					min_heap.push(node);
				}
			}

			//min_heap.print();
			generate_tree(min_heap);
		}

		void generate_tree(PQ min_heap) {

			BT* right;
			BT* left;
			BT* top;

			while(min_heap.get_size() > 1) {

				right = min_heap.top();
				min_heap.pop();

				left = min_heap.top();
				min_heap.pop();

				top = new BT(right, left);
				min_heap.push(top);
			}

			//print(top, 0);
			//cout << endl;
		}

/*
		void print(BT* top, int space) {

			if(top == NULL) 
				return;

			space += 10;

			print(top->right, space);

			cout << endl;
			for(int i = 10 ; i < space; i++)
				cout << " ";
			cout << top->ch << ", " << top->count;

			print(top->left, space); 

		}
*/
	};

#endif