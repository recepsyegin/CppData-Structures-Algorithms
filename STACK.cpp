#include <iostream>
using namespace std;
#define SIZE 5


									/*STACK YAPISI*/

class Node{
	private :
		int data;
	public:
		Node *next;
		Node (int data = 0) // Constructor
		{
			this -> data = data;
			next = NULL;
		}
		
		void setData(int data)
		{
			this -> data;
		}
		int getData()
		{
			return data;
		}
};

/* OPERASYONLAR */

class Stack{
	public:
		Node *root; // "Top" düðüm
		int cnt; // Konteynýr desek kötü olmaz... Yani ne kadar eleman tutacak?
		
		Stack()
		{
			root = NULL;
			cnt = 0;	// Baþlangýçta depo boþ !
		}
		
		bool isEmpty()
		{
			return root == NULL;
		}
		bool isFull()
		{
			return cnt == SIZE; // DEPO 5 ELEMANLI YANÝ SIZE'YE EÞÝTSE FULL DEMEK ! BAÞKA DEÐER ALAMAZ
		}
		
		void push(int value) // EKLEME ÝÞLEMÝ
		{
			if(isEmpty())
			{
				root = new Node(value);
				cout << "Stack yapisi olustu ve ilk eleman eklendi!" << endl;
				cnt++; // Eleman eklendiði için bir arttýrmak
			}
			else
			{
				if(isFull())
				{
					cout << "Stack yapisi dolu, ekleme yapilamaz" << endl;
				}
				else
				{
					Node *temp = new Node(value);
					temp -> next = root;
					root = temp;
					cout << value << " Stack'e eklendi" << endl;
					cnt++;
				}
			}
		}
		void pop() // SÝLME ÝÞLEMÝ
		{
			if(isEmpty()) cout << "Stack zaten bos! Silinecek deger yok !" << endl;
			else
			{
				Node *temp = root;
				root = root->next;
				cout << temp->getData() << "Stack'ten cikartildi" << endl;
				delete temp;
				cnt -- ; // Sildiðimiz için depoda yer açýyoruz!
			}
		}
		void print()
		{
			system("cls"); // Deðerleri print edeceðimiz zaman ekraný temizlemek
			if(isEmpty()) cout << "Stack bos, gosterilecek deger yok !" << endl;
			else
			{
				Node *temp = root;
				cout << "TOP" << endl;
				while(temp!=NULL)
				{
					cout << temp->getData()<<endl; // Deðeri "get" ediyoruz, yani gösteriyoruz.
					temp = temp -> next;
				}
				cout << "TABAN" << endl;
			}
		}
		
		void clear()
		{
			system("cls");
			if(isEmpty()) cout << "Stack zaten bos,SIFIRLAMA yapilamaz" << endl;
			else
			{
				Node *temp = root;
				while(root!=NULL)
				{
					temp = root;
					root = root -> next;
				}
				root = NULL;
				cout << "Stack temizlendi!"<<endl;
			}
		}
		
		void top()
		{
			system("cls");
			if(isEmpty())
			{
				cout << "Stack bos, top deger yok !" << endl;
			}
			else
			{
				cout << "TOP DEGER : " << root->getData() << endl ; // ROOT BAÞ, TOP DEÐER HER ZAMAN
			}
		}		
		
		void size() // STACK ELEMAN SAYISI GÖSTERMEK
		{
			system("cls");
			if(isEmpty()) cout << "Stack bos, eleman sayisi : 0" << endl;
			else
			{
				cout << "Stack eleman sayisi: " << cnt; 
			}
		}
};

int main()
{
	Stack stack;
	int sayi,secim;
	
	while(1)
	{
		cout << "\n1->PUSH" << endl;
		cout << "2-> POP" << endl;
		cout << "3-> PRINT" << endl;
		cout << "4-> RESET" << endl;
		cout << "5-> TOP DEGER" << endl;
		cout << "6-> SIZE" << endl;
		cout << "0-> CIKIS" << endl;
		cout << "SECIM:"; cin >> secim;
		
		switch(secim)
		{
			case 1:
				cout << "SAYI: " ; cin >> sayi;
				stack.push(sayi);
				break;
			case 2:
				stack.pop();
				break;
			case 3:
				stack.print();
				break;
			case 4:
				stack.clear();
				break;
			case 5:
				stack.top();
				break;
			case 6:
				stack.size();
				break;
			case 0:
				cout << "CIKIS YAPILDI" << endl;
				return 0;
			default:
				cout << "HATALI SECIM" << endl; break;
		}
	}
	return 0;
}




