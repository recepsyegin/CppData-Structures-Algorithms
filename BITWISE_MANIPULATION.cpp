#include <bits/stdc++.h>
using namespace std;

int getIthBit(int n , int i) // Bit degerini bulmak
{
	int mask = (1<<i); 		// Bit olarak 1 olan sayýdaki 1 bitini istediðimiz bit'e iteliyoruz.
	return (n&mask) > 0 ? 1 : 0; // 'AND' operasyonu ile sonuc 0'dan buyukse 1'dir,0 'ise 0'dir (BIT OLARAK).
}

void clearIthBit(int n , int i) // Istenen biti silmek
{
	int mask = ~(1<<i); // 1 sayisini i kadar sola oteledik,tersini aldik.
	n = n & mask;	   // Ardindan 'AND' operasyonu ile biti 0'a cektik.
}

void setIthBit (int &n, int i)
{
	int mask = (1<<i); // Yine bol sifirlar arasinda 1'i istenen bite yerlestirdik
	n = n | mask ;    // 'OR' islemine tutup biti 'SET' ettik: '101' -> '111' yani
															  // 3 -> 7
}

void updateIthBit(int n , int i , int v) // Biti guncellemek
{
	clearIthBit(n,i);	// Guncellenecek biti ilk once '0' yaptik
	int mask = (v<<i); // Istenen bit degerini sayi olarak kaydirdik
	n = n | mask;      // 'OR' islemiyle sonucu elde ettik
					   // '110111' -> '111111'
					  // Yani n = '110111',i=3,v = '000101'
}
