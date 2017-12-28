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
		BT* root;
		unordered_map<string, string> codes;

	public:

		huffman(string text, int* count) {

			this->text.append(text);

			for(int i = 0 ; i < 256 ; i++) 
				this->count[i] = count[i];

			root = NULL;

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
			
			root = top;

			generate_codes(top);
			
			//print(top, 0);
			//cout << endl;

			hashmap(top);
			compress();
		}

/*
		void print(BT* top, int space) {

			if(top == NULL) 
				return;

			space += 20;

			print(top->right, space);

			cout << endl;
			for(int i = 10 ; i < space; i++)
				cout << " ";
			cout << top->ch << ", " << top->count << ", " << top->code;

			print(top->left, space); 

		}
*/
		void generate_codes(BT* top) {

			if(top->left == NULL && top->right == NULL)
				return;

			top->left->code.append(top->code + "1");
			top->right->code.append(top->code + "0");

			generate_codes(top->left);
			generate_codes(top->right);
		}

		void hashmap(BT* top) {

			if(top->left == NULL && top->right == NULL) {
				codes[top->ch] = top->code;
				return;
			}

			hashmap(top->left);
			hashmap(top->right);
		}

		void compress() {

			string size_ = "";
			cout << "\n\nHuffman code should look like: \n" << endl;

			for(int i = 0 ; i < text.size() ; i++) {

				char ch[1] = {text.at(i)};
				string to_compress = "";
				to_compress.append(ch);

				size_ += codes[to_compress];

				cout << codes[to_compress];
			}

			cout << endl << endl;

			extras(size_);
		}

		void extras(string size_) {

			char ch;
			cout << "\nDo you wish to know more about compression? (y/n): ";
			cin >> ch;
			
			while(ch != 'n' && ch != 'y' && ch != 'N' && ch != 'Y') {
			
				cout << "Incorrect response, try again!" << endl;
				cout << "Do you wish to know more about compression? (y/n): ";
				cin >> ch;
			
			}
			
			if(ch == 'Y' || ch == 'y')
				more(size_);
			else
				cout << "\nThanks for using!" << endl;

		}

		void more(string size_) {

			cout << "\nHere is the computer genereated code for all the characters: " << endl;
			print_codes(root);

			cout << "\nThe original text will take " << text.size() << " bytes" << endl;
			cout << "The compressed text will take " << size_.size()/8 << " bytes" << endl;
		
		}

		void print_codes(BT* top) {

			if(top->left == NULL && top->right == NULL) {
				cout << top->ch << " : " << "count: " <<  top->count << ", code: " << top->code << endl;
				return;
			}
			
			print_codes(top->right);
			print_codes(top->left);

		}
	};

#endif