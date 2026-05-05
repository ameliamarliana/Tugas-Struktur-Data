#include <iostream>
#include <queue>
using namespace std;

// struktur node
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

// fungsi buat cari minimum depth
int minDepth(TreeNode* root) {
	if (root == NULL) return 0;

	// queue buat BFS (node + depth)
	queue<pair<TreeNode*, int>> q;
	q.push({root, 1}); // mulai dari root, depth = 1

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		TreeNode* node = now.first;
		int depth = now.second;

		// kalau ketemu leaf (ga punya anak)
		if (node->left == NULL && node->right == NULL) {
			return depth; // langsung return, karena ini yang paling deket
		}

		// masukin anak kiri
		if (node->left != NULL) {
			q.push({node->left, depth + 1});
		}

		// masukin anak kanan
		if (node->right != NULL) {
			q.push({node->right, depth + 1});
		}
	}

	return 0;
}

int main() {
	// bikin tree sesuai soal: [3, 9, 20, null, null, 15, 7]
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	int hasil = minDepth(root);

	cout << "Minimum depth = " << hasil << endl;

	return 0;
}
