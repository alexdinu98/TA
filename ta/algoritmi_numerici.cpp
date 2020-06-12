#include "algoritmi_numerici.h"
void algoritmi_numerici() {
	int p = 0,r;
restart:
	system("CLS");
	cout<<"Selectati programul: \n";
	cout<<"1. Acul lui Buffon \n";
	cout<<"2. Aruncarea sageti in patrat \n";
	cout<<"3. Aproximarea numerica a unei integrale pe [a,b] \n";
	cout<<"4. Intoarcerete la meniul anterior \n";
	cout<<"0. Inchide \n";
	if (p>4) cout<<"Nu exista programul "<<p<<"\nSelecteaza alt program.\n";
	cin>>p;
	switch (p)
	{
		case 0:f = 100; goto intoarcere;
		case 1:acul_lui_buffon();break;
		case 2:asp();break;
		case 3:anui();break;
		case 4:f = 1; goto intoarcere; break;
		default: goto restart;
	}
	if (f==1) { f = 0; goto restart; }
	cout<<"Restart ? "; cin>>r;
	if (r==1) goto restart;
intoarcere:;
}
void acul_lui_buffon() {
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
void asp() {
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
void anui() {
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

