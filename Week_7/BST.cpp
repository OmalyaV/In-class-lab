#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left=NULL; 
  struct node *right=NULL;
};

// Inorder traversal
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

// Insert a node
struct node *insertNode(struct node *root, int key) {
    
    if(root == NULL){
      root = new node();
      root->key = key;
      return root;
    }
    else{
      if(root->key< key){
       root->right= insertNode(root->right, key);
       
      }
      else{
        root->left=  insertNode(root->left, key);

      }

    }
    return root;
}
/*struct node *insertNode(struct node *root, int key){
    if(root == NULL ){
        root = new struct node();
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
}*/

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL){
    return root;
  }
  else if (root->key > key){
   root->left= deleteNode(root->left, key);
    
  }
  else if(root->key< key){
    root->right = deleteNode(root->right , key);
    
  }

  else{
    struct node* temp = new node();
    if((root->left ==NULL) && (root->right == NULL)){
      
      root = NULL;
      
    }

    else if((root->left != NULL) && (root->right == NULL) ){
      temp = root;
      root = root->left;
      

    }
    else if(root->left ==nullptr && root->right != nullptr){
      temp = root;
      root = root->right;
      
    }
    else{
      temp = root->right;
      while(temp->left != nullptr){
        temp = temp->left;
      }
      root->key = temp->key;
      root->right=deleteNode(temp, key);
      
    }
  }
 return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}