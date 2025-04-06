#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//* 그래프를 C++로 어떻게 구현할지 생각해보자.

// 하나의 노드에 여러 개의 노드가 결합할 수 있어야 한다.

int sequence = 0;

struct Node {
	int id = sequence++;
	Node* left;
	Node* right;
	int level = -1;

	Node() {
	}

	Node(Node* left, Node* right) {
		Node::left = left;
		Node::right = right;
	}
};

// 재귀 함수로 구현하고 싶다.
Node* create_tree(Node* node, int level) {
	if (level == 0) {
		return node;
	}

	node->level = level--;

	Node* left = create_tree(new Node(), level);
	Node* right = create_tree(new Node(), level);

	node->left = left;
	node->right = right;

	return node;
}

int main() {
	//* 여기서 new Node();를 해주지 않으면 메모리에 할당되지 않음.
	Node* root = create_tree(new Node(), 5);

	int counter = 5;

	while (counter-- != 0) {
		cout << root->level << endl;
	}

}