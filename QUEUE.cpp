#include <iostream>
using namespace std;
#define SIZE 10 
								/* FIFO - FIRST IN FIRST OUT , ÝLK GÝREN DEÐER ÝLK ÇIKAR  */

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data = 0)
		{
			this -> data = data;
			next = NULL;
		}

};

class Queue{
	public:
		Node *root; // Baþ düðüm
		Node *tail; // Son düðüm
		int cnt; // Sýnýr. Dolduðunda ekleme yapýlamayacak.
		
		Queue() // Kurucu method
		{
			root = NULL;
			tail = NULL;
			cnt = 0;
		}
		
		bool isEmpty() // Boþ mu ?
		{
			return root == NULL;
		}
		bool isFull() // Dolu mu ?
		{
			return cnt == SIZE;
		}
		
		void enQueue(int value) // Eleman eklemek
		{
			if(isFull()) cout << "KUYRUK DOLU,EKLEME YAPILAMAZ!" << endl;
			else if(isEmpty())
			{
				root = new Node(value);
				tail = root; // Ýlk eleman olacaðý için,root = tail olmak zorunda.
				cout << "KUYRUGA ILK ELEMAN EKLENDI" << endl;
				cnt ++ ; // Eleman eklediðimiz için deðeri arttýrmayý ihmal etmiyoruz.
			}
			else
			{
				tail -> next = new Node(value); // Tail kuyruðun sonu idi. Next'ine düðüm oluþturduk
				tail = tail -> next ; // Artýk son düðüm, en son gelen olacaðý için tail'i next'i yaptýk
				cout << "KUYRUGUN SONUNA ELEMAN EKLENDI" << endl; 
				cnt++;			
			}
		}
		
		void deQueue() // Eleman silmek
		{
			if(isEmpty()) cout << "KUYRUK BOS, SILME ISLEMI YAPILAMAZ" << endl;
			else
			{
				if(root->next==NULL) // KUYRUKTA TEK ELEMAN VAR ÝSE:
				{
					delete root;
					root = NULL;
					tail = NULL;
					cout << "KUYRUKTAKI TEK DEGER SILINDI" << endl;
					cnt--;
				}
				else
				{
					Node *temp = root -> next;
					delete root;
					root = temp;
					cout << "KUYRUKTAN CIKARTMA ISLEMI YAPILDI" << endl;
					cnt--;
				}
				
			}			
		}
		void print()
		{
			system("cls");
			if(isEmpty()) cout << "KUYRUK BOS, GOSTERILECEK DEGER YOK" << endl;
			else
			{
				Node * temp = root ;
				cout << "BAS -> ";
				while(temp!=NULL)
				{
					cout << temp -> data << " -> ";
					temp = temp -> next;
				} 
				cout << " SON" << endl;
			}
		}
		
		void clear()
		{
			if(isEmpty()) cout << "KUYRUK ZATEN BOS, SILME ISLEMI YAPILAMAZ" << endl;
			else
			{
				while(!isEmpty()) // Kuyruk boþ olana kadar YAP ? NEYÝ:
				{
					deQueue();  // silmeyi!
				}
				system("cls");
				cout << "KUYRUK BOSALTILDI " << endl;
			}
		}
		void size()
		{
			system("cls");
			if(isEmpty()) cout << "KUYRUK BOS, ELEMAN SAYISI NULL" << endl;
			else
			{
				cout << "KUYRUKTAKI ELEMAN SAYISI: " << cnt << endl;
			}
		}
};

int main()
{
	Queue kuyruk;
	int sayi,secim;
	
	while(1)
	{
		cout << "\n1-> ENQUEUE" << endl;
		cout << "2-> DEQUEUE" << endl;
		cout << "3-> PRINT" << endl;
		cout << "4-> RESET" << endl;
		cout << "5-> SIZE" << endl;
		cout << "0-> EXIT" << endl;
		cout << "SECIM:"; cin >> secim;
		switch(secim)
		{
			case 1:
				cout << "SAYI: "; cin >> sayi;
				kuyruk.enQueue(sayi);
				break;
			case 2:
				kuyruk.deQueue();
				break;
			case 3:
				kuyruk.print();
				break;
			case 4:
				kuyruk.clear();
				break;
			case 5:
				kuyruk.size();
				break;				
			case 0:
				return 0;
		}		
	}
	return 0;
}
