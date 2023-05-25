#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;



// Fonksiyon Prototip Tan�mlar� :

template <class T>
class Stack{
	private:
		vector<T> elemanlar;
		
	public:
		void push(T const&); // Vekt�r�n sonuna eleman eklemek
		void pop();			 // Vekt�r�n son eleman�n� silmek
		T top() const; 		 // En �st de�eri g�stermek
		
		bool empty()
		{
			return elemanlar.empty(); // Vekt�re bo� ise TRUE 
		}
};

// FONKS�YONLARIN TANIMLANMASI:

template <class T>
void Stack<T> :: push (T const &eleman) // "void" geri d�n��l�, Stack<T> s�n�f�ndan push methodunu �a��rmak
{
	elemanlar.push_back(eleman);	// vektorIsmi.push_back(eklenecekEleman);
}

template <class T>

void Stack<T> :: pop()
{
	if(elemanlar.empty()) // Elemanlar vekt�r� bo� ise
	{
		throw out_of_range("EMPTY STACK");
	}
	// De�ilse,son eleman� silmek
	elemanlar.pop_back();
}

template <class T>
T Stack <T> :: top () const // Geri d�n�� tipi " T "
{
	if(elemanlar.empty())
		throw out_of_range("EMPTY STACK,NO TOP VALUE");
	
	return elemanlar.back(); // Son eleman�n, top de�erin kopyas�n� d�nd�r�r
}

int main()
{
	try
	{
		Stack <int> intStack; // integer stack veri t�r�
		Stack <string> stringStack; // string stack veri t�r�
		
		intStack.push(7);
		cout << intStack.top() << endl; // 7
		
		stringStack.push("Ogreniyorum");
		cout << stringStack.top() << endl;
		stringStack.pop(); // Ogreniyorum'u siler
		stringStack.pop(); // Hata f�rlat�r
	}
	catch (exception const &ex)
	{
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}
	
}
