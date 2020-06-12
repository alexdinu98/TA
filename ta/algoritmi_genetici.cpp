#include "algoritmi_genetici.h"
void algoritmi_genetici() {
	int p = 0,r;
restart:
	system("CLS");
	cout<<"Selectati programul: \n";
	cout<<"1. Determinarea maximului unei functii \n";
	cout<<"2. Intoarcerete la meniul anterior \n";
	cout<<"0. Inchide \n";
	if (p>2) cout<<"Nu exista programul "<<p<<"\nSelecteaza alt program.\n";
	cin>>p;
	switch (p)
	{
		case 0:f = 100; goto intoarcere;
		case 1:det_max_unei_functii();break;/*-----------------------------NU E GATA-----------------------------*/
		case 2:f = 1; goto intoarcere; break;
		default: goto restart;
	}
	if (f==1) { f = 0; goto restart; }
	cout<<"Restart ? "; cin>>r;
	if (r==1) goto restart;
intoarcere:;
}
void det_max_unei_functii() {
	unsigned r;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/


	not_ready();

		/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Suma maxima cu numar minim de elemente? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}