#include <bits/stdc++.h>
using namespace std;


/*
	*BINARY SAYILARA DIKKAT EDILDIGINDE, EN SAGDAKI YANI "LSB" BITI -> 1 ise SAYI TEKTIR
	*AKSI TAKDIRDE LSB '0' ISE SAYI CIFTTIR.
	*BUNUN ICIN SAYIYI 1 ILE "AND" OPERASYONUNA ALIRSAK, SON BIT "AND"LENMIS OLUR VE 
	SON BITIN NE OLDUGU ORTAYA CIKAR. 1 ISE TEK DERIZ, 0 ISE CIFT DERIZ.
*/

int main()
{	
	int x;
	cin >> x;
	
	if(x&1) cout << "TEK" << endl;
	else cout << "CIFT" ;
	
	return 0;
}
