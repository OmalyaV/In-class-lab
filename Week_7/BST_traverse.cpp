#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left = new node() ; 
  struct node *right;
};
void traverseInOrder(struct node *root) {
    if(root== nullptr){
        return;
    }
    else{
        traverseInOrder(root->left);
        cout << root->key<< " ";
        traverseInOrder(root->right);
    }
    

}

struct node *insertNode(struct node *root, int key){
    if(root == nullptr ){
        root = new node();
        root->key = key;
        return root;
    }
    else{
    struct node * temp = root;
    while(temp != nullptr){
        if (temp-> key >= key){
            temp= temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    temp->key  = key;
    return root;

    }
}
int main() {
    struct node* root = new node();
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);


    traverseInOrder(root);

}