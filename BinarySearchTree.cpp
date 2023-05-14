#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int data = 0)
		{
			this -> data = data;
			left = NULL;
			right = NULL;
		}
};

class BST{
	public:
		Node *root;
		BST()
		{
			root = NULL;
		}
		bool isEmpty()
		{
			return root == NULL;
		}
		
		Node * insert (Node *start, int data) // Yard�mc� ekleme methodu (rek�rsif yap�)
		{
			if(start!=NULL)
			{
				if(data < start->data)
					start -> left = insert(start->left,data);
				else
					start -> right = insert(start->right,data);				
			}
			else
			{
				return new Node(data);
			}
			return start;
		}
		void insert(int data) // As�l ekleme methodu
		{
			root = insert(root,data);
		}
		
		void preOrder(Node *root) // �NCE K�K YAPISI �LE SIRALAMA
		{
			if(root!=NULL)
			{
				cout << root->data << " ";
				preOrder(root->left);
				preOrder(root->right);
			}
		}
		
		void inOrder(Node *root) // ORTADA K�K YAPISI �LE SIRALAMA
		{
			if(root!=NULL)
			{
			inOrder(root->left);
			cout << root -> data << " ";
			inOrder(root->right);
			}	
		}
		
		void postOrder(Node *root) // SONDA K�K YAPISI �LE SIRALAMA
		{
			if(root!=NULL)
			{
			postOrder(root->left);
			postOrder(root->right);
			cout << root -> data << " ";
			}			
		}
		
		int size(Node *root) // D���m say�s�n� bulmak
		{
			if(root==NULL) return 0;
			
			else
				return size(root->left) + 1 + size(root->right);
		}
		
		int height(Node *root) // BST'nin uzunlu�unu bulmak
		{
			if(root == NULL) return 0;
			else
			{
				int sag,sol;
				sol = height(root -> left);
				sag = height(root -> right);
				if(sol>sag) return sol + 1 ;
				else return sag + 1	;
			}
		}
		
		int min(Node *root) // Minimum de�er BST'de en solda olur !
		{
			Node *temp = root;
			if(root==NULL)
				return 0;
			
			else
			{
				while(temp->left!=NULL)
					temp = temp -> left;
					
					return temp -> data;
			}
		}
		
		int max(Node *root) // Max de�er BST'de en sa�da olur !
		{
			Node *temp = root;
			if(root==NULL)
				return 0;
			else
			{
				while(temp->right!=NULL)
					temp = temp -> right;
					
					return temp -> data;
			}
		}
		
		Node *search(Node *root,int data)
		{
			// REK�RS�F OLARAK DE�ERE G�RE REK�RS�F OLARAK DATA ARANACAK
			if(root!=NULL)
			{
				if(root->data==data)
					return root;
				else if(data < root -> data)
					search(root->left,data);
				else
					search(root->right,data);
			}
			else 
				return NULL;
		}	
};
int main()
{
	
	BST bst;
	
	bst.insert(10);
	bst.insert(20);
	bst.insert(5);
	bst.insert(30);
	bst.insert(40);
	bst.insert(15);
	bst.insert(3);
	bst.insert(99);
	 
	cout << "PREORDER: "; bst.preOrder(bst.root);
	cout << "\nINORDER: "; bst.inOrder(bst.root);
	cout << "\nPOSTORDER: "; bst.postOrder(bst.root);
	cout << "\nDUGUM SAYISI: "<< bst.size(bst.root);   // ??
	cout << endl;
	cout << "YUKSEKLIK: "<< bst.height(bst.root);
	cout << endl;
	cout << "EN KUCUK DEGER: " << bst.min(bst.root);
	cout << endl;
	cout << "EN BUYUK DEGER: " << bst.max(bst.root); 
	cout << endl;
	cout << "ARANAN SAYI:(30)-> ";
	if(bst.search(bst.root,30) == NULL)
	cout << "YOK"; else cout << "VAR";
	
	return 0;
}
