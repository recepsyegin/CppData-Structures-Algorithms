#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;



// Fonksiyon Prototip Tanýmlarý :

template <class T>
class Stack{
	private:
		vector<T> elemanlar;
		
	public:
		void push(T const&); // Vektörün sonuna eleman eklemek
		void pop();			 // Vektörün son elemanýný silmek
		T top() const; 		 // En üst deðeri göstermek
		
		bool empty()
		{
			return elemanlar.empty(); // Vektöre boþ ise TRUE 
		}
};

// FONKSÝYONLARIN TANIMLANMASI:

template <class T>
void Stack<T> :: push (T const &eleman) // "void" geri dönüþlü, Stack<T> sýnýfýndan push methodunu çaðýrmak
{
	elemanlar.push_back(eleman);	// vektorIsmi.push_back(eklenecekEleman);
}

template <class T>

void Stack<T> :: pop()
{
	if(elemanlar.empty()) // Elemanlar vektörü boþ ise
	{
		throw out_of_range("EMPTY STACK");
	}
	// Deðilse,son elemaný silmek
	elemanlar.pop_back();
}

template <class T>
T Stack <T> :: top () const // Geri dönüþ tipi " T "
{
	if(elemanlar.empty())
		throw out_of_range("EMPTY STACK,NO TOP VALUE");
	
	return elemanlar.back(); // Son elemanýn, top deðerin kopyasýný döndürür
}

int main()
{
	try
	{
		Stack <int> intStack; // integer stack veri türü
		Stack <string> stringStack; // string stack veri türü
		
		intStack.push(7);
		cout << intStack.top() << endl; // 7
		
		stringStack.push("Ogreniyorum");
		cout << stringStack.top() << endl;
		stringStack.pop(); // Ogreniyorum'u siler
		stringStack.pop(); // Hata fýrlatýr
	}
	catch (exception const &ex)
	{
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}
	
}
