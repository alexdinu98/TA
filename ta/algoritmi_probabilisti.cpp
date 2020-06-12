#include "algoritmi_probabilisti.h"
void algoritmi_probabilisti() {
	int p = 0,r;
restart:
	system("CLS");
	cout<<"Selectati programul: \n";
	cout<<"1. Algoritmi numerici \n";
	cout<<"2. Algoritmi Monte Carlo \n";
	cout<<"3. Algoritmi Las Vegas \n";
	cout<<"4. Intoarcerete la meniul anterior \n";
	cout<<"0. Inchide \n";
	if (p>4) cout<<"Nu exista programul "<<p<<"\nSelecteaza alt program.\n";
	cin>>p;
	switch (p)
	{
		case 0:f = 100; goto intoarcere;
		case 1:algoritmi_numerici();break;
		case 2:algoritmi_monte_carlo();break;
		case 3:algoritmi_las_vegas();break;
		case 4:f = 1; goto intoarcere; break;
		default: goto restart;
	}
	if (f==1) { f = 0; goto restart; } else if (f==100) goto intoarcere;
	cout<<"Restart ? "; cin>>r;
	if (r==1) goto restart;
intoarcere:;
}
