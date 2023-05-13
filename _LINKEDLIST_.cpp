#include <iostream>
using namespace std;
/*
 						TEK YÖNLÜ VE DOĞRUSAL BAĞLI LİSTELER  										
*/


class Node{
	public:
		int data;
		Node *next; // Bir sonraki "data" gösterecek olan adres, pointer
		
		Node(int data = 0)	// KURUCU METHOD, DEFAULT DEĞERİ "0"
		{
			this->data = data;
			next = NULL;
		}
};

// OPERASYONLAR 
class List{	
	public:
		Node *root; // class Node yapısında bir KÖK düğüm oluşturmak !
		List()		// Kök ilk çağrıldığında NULL değeri atanacak !
		{
			root = NULL; //
		}
		
		bool isEmpty()	// DÜĞÜM BOŞ MU ? SORGUSU
		{
			return root == NULL; // Eğer BOŞ ise FALSE döner.
		}
		
		void insertBack(int value) // DÜĞÜM SONUNA ELEMAN EKLEMEK
		{
			if(isEmpty()) // LİSE BOŞ İSE, yeni düğüm oluşturacağız
			{
				root = new Node(value); // "root" için yer açtık ve parametreyi değer olarak girdik.
				cout << "LISTE OLUSTU ve ILK ELEMANI EKLEDIK!" << endl;
			}
			
			else // Daha önceden düğüm varsa sonuna ekleyeceğiz else ile.
			{
				Node *temp = root ;
				while(temp->next!=NULL) // Son düğüm NULL olacaktır, onu while ile buluyoruz.
				{
					temp = temp -> next;
				}
				temp -> next = new Node(value); // Burada temp son düğümdü ve next'ine bellekten yer açtık
												// ve içine "değer" atadık.
				cout << "LISTENIN SONUNA DUGUM EKLENDI!" << endl;
			}
		}
		
		void insertFront(int value) // DÜĞÜM BAŞINA ELEMAN EKLEMEK
		{
			if(isEmpty()) // Ee, düğüm boş ise yeni düğüm açacağız !
			{
				root = new Node(value);
				cout << "LISTE OLUSTURULDU VE ILK ELEMAN EKLENDI !" << endl;
			}
			else
			{
				Node *temp = new Node(value); // Değil ise yeni düğüm oluşturduk.
				temp -> next = root; 		  // Yeni düğüm'ün sonraki düğümü root'u göstermekte
				root = temp; 				  // Yeni düğüm artık "root" olarak güncellendi.
				cout << "LISTENIN BASINA ELEMAN EKLENDI" << endl; // bilgi...	
			}
		}
		
		void insert(int value) // *** ARAYA EKLEME METHODU ***
		{
			if(isEmpty())	// Sürekli liste boş mu diye kontrol etmeliyiz.
			{
				root = new Node(value); // Boş ise yeni düğüm oluşturmalıyız.
				cout << "LISTE OLUSTURULDU" << endl;
			}
			else
			{
				int data; // Hangi düğümün değerinden önce ekleyeceğiz ?!?!
				cout << "Hangi 'degerden' once bir dugum ekliyecegiz_?"; cin >> data;
				if(root -> next == NULL && root->data==data) // Tek düğüm varsa ve bu düğümden önce eklemek istiyor isek !
				{
					Node * temp = new Node(value); // Oluşturduk düğümü
					temp -> next = root; // İlk düğüm ve ondan önce eklemek istediğimiz için başa ekliyoruz
					root = temp; // Güncellemeyi unutmuyoruz.
					cout << "BASA EKLENDI !!!" << endl;
				}
				else if(root -> next != NULL && root->data==data)
				{
					Node * temp = new Node(value);
					temp -> next = root;
					root = temp;
					cout << "EKLEME YAPILDI!" << endl;
				}
				else
				{ // Araya ekleyeceğimiz için bağlantıları kaybetmememiz gerek !
					Node *temp = root;
					Node *prev = root;
					while(temp!=NULL)
					{
						if(temp->data==data) // Eklenecek düğümü bulunca if girmek
						{
							prev -> next = new Node(value);
							prev -> next -> next = temp;
							cout << "ARAYA ELEMAN EKLENDI" << endl;
						}
						prev = temp; // Prev , temp'ten bir önceki düğümü tutuyor
						temp = temp -> next; // temp'i de bir bir ilerletiyoruz,if'e girene kadar.
					}
				}
			}	
		}
		
		void print() // VERİLERİ YAZDIRMAK!
		{
			system("cls"); // Verileri yazdırmadan önce ekranımızı temizliyoruz.
			if(isEmpty())	// Boş ise yazdırılacak değer yoktur !!!
			{
				cout << "LISTE BOS,YAZDIRILACAK DATA YOK!"<< endl;
			}
			else
			{
				Node *temp = root ; // Temp ile bütün değerleri göreceğiz.
				while(temp!=NULL) // SON DÜĞÜME KADAR GİT! NULL'DA ÇIK !
				{
					cout << temp -> data << "->" ;
					temp = temp->next; // Tek tek ilerletiyoruz ! BUNU UNUTMAMAK GEREK.
				}
			}
		}
		
		// SİLME İŞLEMLERİ !
		
		void popFront() // "baştan" silmek
		{
			if(isEmpty()) // her seferinde sorgulatıyoruz fakat ÖNEMLİ, açık bırakmıyoruz.
			{
				cout << "SILINECEK ELEMAN YOK !"<<endl;
			}
			else if(root->next==NULL) // tek eleman var ise .
			{
				delete root;
				root = NULL;
				cout << "TEK DUGUM VARDI VE SILDIK !" << endl;
			}
			else
			{
				Node *temp = root; // temp baş düğüm 
				root = root -> next; // root ise bir sonraki düğüm,temp'i sileceğiz
				delete temp; // baştan sildik, root zaten bir sonraki olarak bir üstte güncellendi
				cout << "LISTENIN BASINDAN BIR DUGUM SILINDI" << endl;
			}
		}
		
		void popBack() // "sondan" silmek
		{
			if(isEmpty()) 
			{
				cout << "SILINECEK ELEMAN YOK !"<<endl;
			}
			else if (root -> next == NULL)  // TEK DÜĞÜM 
			{
				delete root;
				root = NULL;
				cout << "LISTEDEKI TEK ELEMAN SILINDI, LISTE BOS" << endl;
			}
			else
			{
				Node *temp = root;
				Node *prev = root;
				while(temp->next!=NULL)
				{
					prev = temp;	// prev temp'ten bir önceki düğüm
					temp = temp->next;
				}
				delete temp; // temp son düğüm,prev bir önceki düğüm !
				prev -> next = NULL; // prev son düğüm oldu ve tempi sildik.
				cout << "LISTENIN SONUNDAKI ELEMAN SILINDI!"<<endl;
			}
		}
		
		void aradanSil()
		{
			if (isEmpty())
			{
				cout << "LISTE BOS, SILINECEK DUGUM YOK" << endl;
			}
			
			else
			{
				int data;
				cout << "SILMEK ISTEDIGINIZ DUGUMUN DEGERI?(int data)"; cin >> data;
				if(root->next==NULL && root->data==data) // tek düğüm varsa ve silmek istediğimiz bu ise
				{
					delete root;
					root = NULL;
					cout << "LISTEDEKI TEK DUGUM SILINDI" << endl;
				}
				else if(root->next!=NULL && root->data==data) // baş düğümü silmek istiyorsak(fakat farklı düğümler de var)
				{
					Node *temp = root;
					root = root -> next;
					delete temp;
					cout << "BASTAKI DUGUM SILIDNDI" <<endl;				
				}
				else
				{
					Node *temp = root;
					Node *prev = root;
					while(temp->next!=NULL)
					{
						if(temp->data==data) // silmek istenen -> temp'in nexti
						{
							prev -> next = temp -> next; // ARAYI TUTTUK ! BAĞLADIK!
							delete temp;
							cout << "ARADAN SILME ISLEMI YAPILDI" << endl;
							break; // döngüye gerek kalmadı ! çıktık
						}
						prev = temp;
						temp = temp->next;
					}
					
					if(temp->data==data) // eğer son düğüm değeri girilmişse burası !
					{
						prev -> next = NULL; // prev son düğüm yapıldı,temp son düğümdü ve silicez prev yeni son düğüm
						delete temp;
						cout << "SON DUGUM SILINDI" << endl;
					}				
				}				
			}
		}	
};
int main()
{
	List lst;
	
	
	
	while (1)
	{
		int value;
		int secim;
		
		cout << endl<< "1-> BASA EKLE " << endl;
		cout << "2-> SONA EKLE " << endl;
		cout << "3-> ARAYA EKLE " << endl;
		cout << "4-> BASTAN SIL" << endl;
		cout << "5-> SONDAN SIL " << endl;
		cout << "0-> CIKIS" << endl;
		cout << "SECIMINIZ: " ; cin >> secim;
		
		switch(secim)
		{
			case 1:
				cout << "SAYI: "; cin>>value;
				
				lst.insertFront(value); lst.print();
				break;
				
			case 2:
				cout << "SAYI: "; cin>>value;
				lst.insertBack(value); 
				lst.print();
				break;
				
			case 3:
				cout << "SAYI: "; cin>>value;
				lst.insert(value); lst.print();
				break;
				
			case 4:
				lst.popFront(); lst.print();
				break;
				
			case 5:
				lst.popBack(); lst.print();
				break;
					
			default:
				cout << "HATALI SECIM YAPILDI !" << endl;
				break;
				
			case 0 :
				cout << "CIKIS YAPTINIZ" << endl;
				return 0;
				
		}	
	}
	
	return 0;
}






















