#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int key;
	int data;
	int height;
	Node* left;
	Node* right;
	Node(int inputKey, int inputData) {
		key = inputKey;
		data = inputData;
		height = 1;
		left = nullptr;
		right = nullptr;
	}
};

int treeHeight(Node* treeNode) {
	if (treeNode) {
		return treeNode->height;
	}
	else {
		return 0;
	}
}

int balance(Node* treeNode) {
	if (treeNode) {
		return treeHeight(treeNode->left) - treeHeight(treeNode->right);
	}
	else {
		return 0;
	}
}

Node* rotateRight(Node* node) {
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	node->height = max(treeHeight(node->left), treeHeight(node->right)) + 1;
	temp->height = max(treeHeight(temp->left), treeHeight(temp->right)) + 1;
	return temp;
}

Node* rotateLeft(Node* node) {
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node->height = max(treeHeight(node->left), treeHeight(node->right)) + 1;
	temp->height = max(treeHeight(temp->left), treeHeight(temp->right)) + 1;
	return temp;
}
Node* insert(Node* node, int key, int data) {
	if (!node) {
		cout << "Inserted key " << key << " with value " << data << endl;
		return new Node(key, data);
	}
	if (key < node->key) {
		node->left = insert(node->left, key, data);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key, data);
	}
	else {
		node->data = data;
		return node;
	}
	node->height = max(treeHeight(node->left), treeHeight(node->right)) + 1;
	int balanceValue = balance(node);

	if (balanceValue > 1 && key < node->left->key) {
		return rotateRight(node);
	}

	if (balanceValue < -1 && key > node->right->key) {
		return rotateLeft(node);
	}

	if (balanceValue > 1 && key > node->left->key) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	if (balanceValue < -1 && key < node->right->key) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

void inOrdertreverse(Node* root) {
	if (root) {
		inOrdertreverse(root->left);
		cout << " (" << root->key << " " << root->data << ") ";
		inOrdertreverse(root->right);
	}
}

void printTree(Node* root) {
	inOrdertreverse(root);
	cout << endl;
	cout << "Tree height is: " << treeHeight(root) << endl;
}

Node* minValueNode(Node* node) {
	while (node->left) {
		node = node->left;
	}
	return node;
}

Node* deleteNode(Node* root, int key) {
	if (!root) {
		return root;
	}

	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if (!root->left || !root->right) {
			Node* temp = root->left ? root->left : root->right;
			if (!temp) {
				temp = root;
				root = nullptr;
			}
			else {
				*root = *temp;
			}
			delete temp;
		}
		else {
			Node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (!root) {
		return root;
	}

	root->height = max(treeHeight(root->left), treeHeight(root->right)) + 1;
	int balanceValue = balance(root);

	if (balanceValue > 1 && balance(root->left) >= 0)
		return rotateRight(root);

	if (balanceValue > 1 && balance(root->left) < 0) {
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	if (balanceValue < -1 && balance(root->right) <= 0)
		return rotateLeft(root);

	if (balanceValue < -1 && balance(root->right) > 0) {
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}
	return root;
}

int main() {

	Node* root = nullptr;
	int insertions[][2] = { {5, 2}, {7, 3}, {15, 5}, {20, 7}, {25, 4}, {17, 7},
						   {32, 10}, {44, 10}, {48, 3}, {50, 5}, {62, 21}, {78, 29},
						   {88, 6}, {62, 40}, {90, 7} };

	cout << "Performing insertions:\n";
	for (auto& pair : insertions) {
		root = insert(root, pair[0], pair[1]);
		printTree(root);
	}
	cout << "-----------------------------" << endl;
	cout << "Final root after all insertions: " << root->key << " with value " << root->data << endl;


	root = deleteNode(root, 32);
	printTree(root);

	root = deleteNode(root, 88);
	printTree(root);

	root = deleteNode(root, 90);
	printTree(root);

	cout << "-----------------------------" << endl;
	cout << "Final root after all deletions: " << root->key << " with value " << root->data << endl;

	return 0;
}