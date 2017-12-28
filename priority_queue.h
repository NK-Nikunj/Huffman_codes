#ifndef priority_queue

	#define priority_queue

	#include <vector>
	#include "binary_tree.h"

	class PQ {

	public:

		vector<BT*> store;

		bool is_empty() {
			return store.size() == 0;
		}

		int get_size() {
			return store.size();
		}

		void push(BT* address) {

			store.push_back(address);

			int child_index = store.size() - 1;

			while(child_index > 0) {

				int parent_index = (child_index - 1) / 2;

				if(store[child_index]->count < store[parent_index]->count) {

					BT* temp = store[child_index];
					store[child_index] = store[parent_index];
					store[parent_index] = temp;

				}
				else
					break;

				child_index = parent_index;
			}
		}

		void pop() {

			if(is_empty())
				return;

			store[0] = store[store.size() - 1];
			store.pop_back();

			int parent_index = 0;
			int left_child_index = 2 * parent_index + 1;
			int right_child_index = 2 * parent_index + 2;

			while(left_child_index < store.size()) {

				int min_index = parent_index;

				if(store[min_index]->count > store[left_child_index]->count)
					min_index = left_child_index;

				if(right_child_index < store.size() && store[right_child_index]->count < store[min_index]->count)
					min_index = right_child_index;

				if(min_index == parent_index)
					break;

				BT* temp = store[min_index];
				store[min_index] = store[parent_index];
				store[parent_index] = temp;

				parent_index = min_index;
				left_child_index = 2 * parent_index + 1;
				right_child_index = 2 * parent_index + 2;
			}
		}

		BT* top() {
			if(!is_empty())
				return store[0];
		}

/*
		void print() {

			for(int i = 0 ; i < store.size() ; i++)
				cout << store[i]->ch << ":" << store[i]->count << endl;
		}
*/
	};

#endif