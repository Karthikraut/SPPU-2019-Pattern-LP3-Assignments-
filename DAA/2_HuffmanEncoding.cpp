#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Huffman Encoding

class Node {
public:
	string ch;
	int freq;
	Node* left;
	Node* right;
	Node(string ch,int freq) {
		this->ch = ch;
		this->freq = freq;
		left =NULL;
		right =NULL;
	}
};

// Recursive function to print Huffman Codes from the root of Huffman Tree
void printCodes(Node* root, string code) {
	if (!root) return;

	// if leaf node, print character and code
	if (!root->left && !root->right) {
		cout << root->ch << " : " << code << endl;
		return;
	}

	// traverse left (0) and right (1)
	printCodes(root->left, code + "0");
	printCodes(root->right, code + "1");
}

struct cmp {
	bool operator()(Node* a, Node* b) {
		return a->freq > b->freq;
	}
};

void huffman_enco(vector<Node*> v) {
	priority_queue<Node*,vector<Node*>,cmp> pq;
	for(int i=0; i<v.size(); i++) {
		pq.push(v[i]);
	}

	while(pq.size()>1) {
		Node* left = pq.top();
		pq.pop();
		Node* right = pq.top();
		pq.pop();

		Node* newNode = new Node("$",left->freq+right->freq);
		newNode->left =left;
		newNode->right =right;
		pq.push(newNode);
	}
	Node* root = pq.top();
	cout << "\nHuffman Codes:\n";
	printCodes(root, "");
}

int main() {
	int n;
	cout<<"Enter no. of characters: ";
	cin>>n;
	vector<Node*> v;
	for(int i=0; i<n; i++) {
		string ch;
		int freq;
		cout << "Enter character: ";
		cin >> ch;
		cout << "Enter Freq: ";
		cin >> freq;
		v.push_back(new Node(ch, freq));
	}
	huffman_enco(v);
}