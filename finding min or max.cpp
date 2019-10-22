// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};


// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right =  NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

int findmin(BstNode * root){
	if(root->left == NULL)return root->data;
	findmin(root->left);//all right here 
	
}

int findmax( BstNode * root){
		BstNode* current = root;
	   while( current->right !=NULL){
	   	current = current->right;
	   }
	   return current->data; //giving right output
	   
	 	
	    //findmin(root->right); 
	    //if(root == NULL)return root->data;  why giving 20
	    }
	    
	    
	    
int find_hieght(BstNode* root){
 if(root == NULL)return -1;
//return  find_hieght(root->left)+1;
//return find_hieght(root->right)+1;
 return max(find_hieght(root->left) ,find_hieght(root->right)) +1;
}
BstNode * max(BstNode* left,BstNode * right){
	if(left > right )return left ;
	else return right;
}

int main() {
 // Creating an empty tree
 	BstNode* root = NULL; 
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
    root = Insert(root,13);
	

	int min  = findmin(root);
	cout << "min is "<< min<<endl;
	int max = findmax(root);
	cout << "max is "<< max<<endl;
	int hieght = find_hieght(root);
	cout<<"hieght is "<< hieght<<endl;
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	
	
	
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
}
