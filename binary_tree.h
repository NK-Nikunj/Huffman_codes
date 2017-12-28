#ifndef binary_tree
	
	#define binary_tree
	
	class BT {

	public:

		int count;
		string ch;
		string code;
		BT* right;
		BT* left;

		BT(int count, string ch) {

			this->count = count;
			this->ch.append(ch);
			this->right = NULL;
			this->left = NULL;
		
		}

		BT(BT* right, BT* left) {

			this->count = right->count + left->count;
			this->ch.append(right->ch + left->ch);
			this->right = right;
			this->left = left;

		}
	};

#endif