#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	BST<int> b;
	b.insert(32);
	BSTIterator<int> it(b.root);
	cout<<*it<<endl;
	return 0;

}