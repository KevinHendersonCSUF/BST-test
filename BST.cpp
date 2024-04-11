#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) {
        val = k;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int value){
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}
TreeNode* FindSucc(TreeNode* node) {
    while(node-> left) {
        
    }
}
TreeNode* Delete(TreeNode* root, int value){
    if(root == nullptr) {
        return root;
    }
    if(value < root->val) {
        root->left = Delete(root->left, value);
    }
    else if (value > root->val) {
        root->right = Delete(root->right, value);
    }
   //node has no children is else statement below
    else {
        if(root->left == nullptr && root->right == nullptr){ delete root;
        return nullptr;
    }
    //node has one child is if statement below
    if(root->left == nullptr) {
    TreeNode* temp = root->right;
    delete root;
    return temp;
    }
    if(root->right == nullptr) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }
    //node has two children is code below
    TreeNode* succ = FindSucc(root->right);
    root->val = succ->val;
    root->right = Delete(root->right, succ->val);
    return root;
}
bool search(TreeNode* root, int value) {
    bool found = false;
    if(root) {
        if(value == root->val) {
            std::cout<< std::endl << "found " << value <<"!"<< std::endl;
            found = true;
        }
       else if(value < root->val) {
            search(root->left, value);
        }
        else {
            search(root->right, value);
        }
    }
    else{
        std::cout<< value << " not found!" << std::endl;
    }
 return found;   
}
void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        std::cout<< root->val << " ";
        inorder(root->right);
    }
}
int main() {
    TreeNode* root = nullptr;
    root = insert(root, 34);
    root = insert(root, 53);
    root = insert(root, 25);
    root = insert(root, 12);
    root = insert(root, 46);
    inorder(root);
    search(root, 25);
    search(root, 21);
    Delete(root, 25);
    inorder(root);
    Delete(root, 34);
    inorder(root);
    return 0;
}
