#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode():left(NULL),right(NULL){}
	TreeNode(int val):left(NULL),right(NULL)
	{}
};
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL)return NULL;
		Node* head = root;
		queue<Node*>q;
		q.push(head);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				Node* node = q.front();
				q.pop();
				if (size == 0) {
					node->next = NULL;
					if (node->left)q.push(node->left);
					if (node->right)q.push(node->right);
					break;
				}
				if (node) {
					node->next = q.front();
					if (node->left)q.push(node->left);
					if (node->right)q.push(node->right);
				}
			}
		}
		return root;
	}
};
//class Solution {
//public:
//	vector<int> largestValues(TreeNode* root) {
//		vector<int>res;
//		queue<TreeNode*>q;
//		if (root == NULL)return res;
//		q.push(root);
//		while (!q.empty()) {
//			int size = q.size();
//			vector<int>temp;
//			while (size--) {
//				TreeNode* node = q.front();
//				q.pop();
//				if (node) {
//					temp.push_back(node->val);
//					if (node->left)q.push(node->left);
//					if (node->right)q.push(node->right);
//				}
//			}
//			sort(temp.begin(), temp.end(), [](int a, int b) {return a > b; });
//			res.push_back(temp[0]);
//		}
//		return res;
//	}
//};
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//    }
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root) {
//        vector<vector<int>>res;
//        queue<Node*>q;
//        if (root == NULL)return res;
//
//        q.push(root);
//        while (!q.empty()) {
//            vector<int>temp;
//            int size = q.size();
//            while (size--) {
//                Node* node = q.front();
//                q.pop();
//                if (node) {
//                    temp.push_back(node->val);
//                    for (int i = 0; i < node->children.size(); i++) {
//                        if (node->children[i])q.push(node->children[i]);
//                    }
//                }
//            }
//            res.push_back(temp);
//        }
//        return res;
//    }
//};