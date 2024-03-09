#include <iostream>
#include <queue>
#include <memory>
using namespace std;


struct TreeNode 
{
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void printLeftView(TreeNode* root) 
{
    if (!root) 
    {
        cout << "OOPS!!! Tree is empty!" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) 
    {
        int n = q.size();
        
        for (int i = 0; i < n; ++i) 
        {
            TreeNode* temp = q.front();
            q.pop();

            /* Print the leftmost element at the level */
            if (i == 0) 
            {
                cout << temp->val << " ";
            }
/* Print the left view of the tree */
#if 1

            if (temp->left)
            {
                q.push(temp->left.get());
            }

            if (temp->right) 
            {
                q.push(temp->right.get());
            }
            
/* Print the right view of the tree */
#else

            if (temp->right) 
            {
                q.push(temp->right.get());
            }
            
            if (temp->left)
            {
                q.push(temp->left.get());
            }

#endif
        }
    }
}

int main() 
{
    auto root = make_unique<TreeNode>(10);
    root->left = make_unique<TreeNode>(2);
    root->right = make_unique<TreeNode>(3);
    root->left->left = make_unique<TreeNode>(7);
    root->left->right = make_unique<TreeNode>(8);
    root->right->right = make_unique<TreeNode>(15);
    root->right->left = make_unique<TreeNode>(12);
    root->right->right->left = make_unique<TreeNode>(14);
    root->right->right->right = make_unique<TreeNode>(20);

    cout << "Left view of the binary tree: ";
    printLeftView(root.get());
    cout << endl;

    return 0;
}
