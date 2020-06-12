#include "backtracking.h"

void backtracking() {
	int p = 0,r;
restart:
	system("CLS");
	cout<<"Selectati programul: \n";
	cout<<"1. Generare Permutari \n";
	cout<<"2. Generare Combinari \n";
	cout<<"3. Generare Aranjamente \n";
	cout<<"4. Problema Reginelor \n";
	cout<<"5. Problema Turelor \n";
	cout<<"6. Problema Calutilor \n";
	cout<<"7. Problema Parantezelor \n";
	cout<<"8. Problema Comisului voiajor \n";
	cout<<"9. Generare Submultimi\n";
	cout<<"10. Numere de la 1 la 12 pe laturile unui cub \n";
	cout<<"11. Generare steaguri\n";
	cout<<"12. Intoarcerete la meniul anterior \n";
	cout<<"0. Inchide \n";
	if (p>11) cout<<"Nu exista programul "<<p<<"\nSelecteaza alt program.\n";
	cin>>p;
	switch (p)
	{
		case 0:f = 100; goto intoarcere;
		case 1:generare_permutari(); break;
		case 2:generare_combinari(); break;
		case 3:generare_aranjamente(); break;
		case 4:problema_reginelor(); break;
		case 5:problema_turelor();break;
		case 6:problema_calutilor();break;
		case 7:problema_Parantezelor();break;
		case 8:pb_comis_voiaj();break;
		case 9:generare_submultimi();break;
		case 10:generare_cub();break;
		case 11:generare_steaguri();break;
		case 12:f = 1; goto intoarcere; break;
		default: goto restart;
	}
	if (f==1) { f = 0; goto restart; }
	cout<<"Restart ? "; cin>>r;
	if (r==1) goto restart;
intoarcere:;
}
void generare_permutari() {/*--------------------------------1.Generare Permutari--------------------------------*/
	int k,n,x[10],i,v,c,r;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	cout<<"Numarul de elemente de permutat? N= "; // n = 10;
	cin>>n;
	if (n<1)
		goto restart;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	k = 1;
	x[1] = 0; //1-1
	cout<<"Permutarile de "<<n<<" sunt: \n";
	while (k>0)
	{
		v = 0; // varaiabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			if (validperm(x,k)) v = 1;
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==n) // agasit solutie si o afiseaza
			{
				c++;
				for (i = 1;i<=n;i++)
					cout<<x[i]<<" ";
				cout<<'\n';
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" permutari\n";
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Gen Permutari ? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void generare_combinari() {/*--------------------------------2.Generare Combinari--------------------------------*/
	int k,n,m,x[10],i,v,c,r;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	cout<<"Combinari de n= "; cin>>n;
	cout<<"luate cate m="; cin>>m;
	if (n<1)
		goto restart;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	k = 1;
	x[1] = 0; //1-1
	cout<<"Combinarile de "<<n<<" luate cate "<<m<<" sunt:\n";
	while (k>0)
	{
		v = 0; // varaiabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			if (validcomb(x,k)) v = 1;
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==m) // agasit solutie si o afiseaza
			{
				c++;
				for (i = 1;i<=m;i++)
					cout<<x[i]<<" ";
				cout<<'\n';
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" combinari\n";
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Gen Combinari? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void generare_aranjamente() {/*--------------------------------3.Generare Aranjamente--------------------------------*/
	int k,n,m,x[10],as,c,r;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	cout<<"Aranjamente de n= "; cin>>n;
	cout<<"Luate cate m="; cin>>m;
	if (n<1)
		goto restart;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	k = 1;
	x[1] = 0; //1-1
	cout<<"Aranjamente de "<<n<<" luate cate "<<m<<" sunt:\n";
	while (k>0)
	{
		do {} while ((as = am_succesor(x,n,k))&&!validaranj(x,k));
		if (as)
			if (k==m)
			{
				afisv(x,m);c++;
			} else
			{
				k++;
				x[k] = 0;
			} else  k--;
	}
	cout<<"Sunt "<<c<<" aranjamente\n";
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Gen Aranjamente? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void problema_reginelor() {/*--------------------------------4.Problema Reginelor--------------------------------*/
	unsigned r;
	int n,i,j,k,v,c;
	int* x;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	cout<<"Numarul de regine de aranjat n= "; cin>>n;
	x = (int*)calloc(10,sizeof(int*));
	k = 1;
	x[1] = 0; //1-1
	cout<<"Posibilitatile de aranjare a "<<n<<" regine sunt: \n";
	while (k>0)
	{
		v = 0; // variabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			v = valid_regine(x,k);
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==n) // a gasit solutie si o afiseaza
			{
				c++;
				for (i = 1; i<=n; i++)
					cout<<x[i]<<" ";
				cout<<'\n';
				for (j = 1; j<=n; j++)
				{
					for (i = 1; i<=n; i++)
					{
						if (x[j]==i) cout<<"X";
						else cout<<"0";
					}
					cout<<'\n';
				}
				cout<<'\n';
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" posibilitati\n";
	free(x);
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Regine? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void problema_turelor() {/*--------------------------------5.Problema Turelor--------------------------------*/
	unsigned r;
	int n,i,j,k,v,c;
	int* x;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	cout<<"Numarul de ture de aranjat n= "; cin>>n;
	x = (int*)calloc(10,sizeof(int*));
	k = 1;
	x[1] = 0; //1-1
	cout<<"Posibilitatile de aranjare a "<<n<<" ture sunt: \n";
	while (k>0)
	{
		v = 0; // variabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			if (valid_ture(x,k)) v = 1;
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==n) // a gasit solutie si o afiseaza
			{
				c++;
				for (i = 1; i<=n; i++)
					cout<<x[i]<<" ";
				cout<<'\n';
				for (j = 1; j<=n; j++)
				{
					for (i = 1; i<=n; i++)
					{
						if (x[j]==i) cout<<"X";
						else cout<<"0";
					}
					cout<<'\n';
				}
				cout<<'\n';
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" posibilitati\n";
	free(x);
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Ture? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void problema_calutilor() {/*--------------------------------6.Problema Calutilor--------------------------------*/
	unsigned r;
	int n,i,j,k,v,c;
	int* x;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	cout<<"Numarul de cai de aranjat n= "; cin>>n;
	x = (int*)calloc(10,sizeof(int*));
	k = 1;
	x[1] = 0; //1-1
	cout<<"Posibilitatile de aranjare a "<<n<<" cai sunt: \n";
	while (k>0)
	{
		v = 0; // variabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			if (valid_cai(x,k)) v = 1;
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==n) // a gasit solutie si o afiseaza
			{
				c++;
				for (i = 1; i<=n; i++)
					cout<<x[i]<<" ";
				cout<<'\n';
				for (j = 1; j<=n; j++)
				{
					for (i = 1; i<=n; i++)
					{
						if (x[j]==i) cout<<"X";
						else cout<<"0";
					}
					cout<<'\n';
				}
				cout<<'\n';
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" posibilitati\n";
	free(x);
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Cai? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void problema_Parantezelor() {/*--------------------------------7.Problema Parantezelor--------------------------------*/
	int r,n,ns;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	cout<<"N: ";cin>>n;
	int* x;
	ns = 0;
	x = (int*)calloc(n,sizeof(int*));
	if (n%2==0)
	{
		back_parant(x,n,ns,1);
	} else goto restart;
	cout<<"Total "<<ns<<" solutii";
	free(x);
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Problema Parantezelor? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void pb_comis_voiaj() {/*--------------------------------8.Problema Comis Voiajor--------------------------------*/
	int r,n;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	int cost = 0;
	cout<<"Numarul de sate: ";cin>>n;
	int i,j,** a,* v;
	v = (int*)calloc(n,sizeof(int*));
	a = (int**)calloc(n,sizeof(int*));
	for (i = 0; i<n; i++)
	{
		a[i] = (int*)calloc(n,sizeof(int));
	}
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			a[i][j] = rand()%100;
		}
		v[i] = 0;
	}
	cout<<"\nLista de costuri este:\n";
	for (i = 0;i<n;i++)
	{
		for (j = 0;j<n;j++)
			cout<<setw(3)<<a[i][j]<<' ';
		cout<<"\n";
	}
	costmin(0,n,a,v);
	cout<<"\n";
	free(v);
	freematrix(a,n);
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Comis Voiajor? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void generare_submultimi() {
	unsigned r;
	int n,*x;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	cout<<"N= ";cin>>n;
	x = (int*)calloc(n+1,sizeof(int));
	gen_s(1,n,x);
	cout<<'\n';
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
void generare_cub() {/*--------------------------------10.Generare Cub--------------------------------*/
	int k,n,x[13],i,v,c = 0,r;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	//cout<<"Numarul de elemente de permutat? N= "; // n = 10;
	n = 12;
	if (n<1)
		goto restart;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	k = 1;
	x[1] = 0; //1-1
	cout<<"Permutarile pentru cub sunt: \n";
	while (k>0)
	{
		v = 0; // varaiabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			if (validperm(x,k)) v = 1;
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==n) // a gasit solutie si o afiseaza
			{
				if (x[1]+x[2]+x[3]+x[4]==26&&
					x[9]+x[10]+x[11]+x[12]==26&&
					x[2]+x[6]+x[10]+x[5]==26&&
					x[3]+x[7]+x[11]+x[6]==26&&
					x[4]+x[8]+x[12]+x[7]==26&&
					x[1]+x[5]+x[9]+x[8]==26)
				{
					for (i = 1;i<=n;i++)
						cout<<x[i]<<" ";
					cout<<'\n';
					c++;

				}
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" permutari\n";
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Gen Cub ? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
void generare_steaguri() {/*--------------------------------11.Generare Steaguri--------------------------------*/
	unsigned r;
	int k,n = 7,m = 3,x[4],i,v,c;
restart:
	system("CLS");
	/*--------START-CORP--------*/
	c = 0;
	auto start = chrono::steady_clock::now(); /*--------Start cronometru--------*/
	k = 1;
	x[1] = 0; //1-1
	while (k>0)
	{
		v = 0; // varaiabila de validare
		// aleg x[k]
		while ((v==0)&&(x[k]+1<=n))
		{
			x[k] = x[k]+1;
			if (validcomb(x,k)) v = 1;
		}
		if (v==0)
			k--;
		else //v!=0
		{
			if (k==m) // agasit solutie si o afiseaza
			{


				if (x[2]==5)
				{
					c++;
					for (i = 1;i<=m;i++)
						cout<<x[i]<<" ";
					cout<<'\n';
				}
			} else
			{
				k++;
				x[k] = 0; //1-1
			}
		}
	}
	cout<<"Sunt "<<c<<" combinari\n";
	/*--------END-CORP--------*/
	auto end = chrono::steady_clock::now(); /*--------Stop cronometru--------*/
	auto diff = end-start;                /*--------Calculare timp--------*/
	cout<<chrono::duration<double,milli>(diff).count()<<" ms"<<'\n'; //----afisare timp in milisecunde----
	do
	{
		cout<<"\nRestart Gen Steaguri? ";
		cin>>r;
		if (r==1)
			goto restart;
		else
			f = 1;
		system("CLS");
	} while (r>1);
}
int am_succesor(int x[],int n,int k) {
	if (x[k]<n)
	{
		x[k]++;
		return 1;
	}
	return 0;
}
void afisv(int st[],int n) {
	for (int i = 1; i<=n; i++)
		cout<<st[i]<<' ';
	cout<<'\n';
}
int validperm(int x[10],int k) {
	for (int i = 1;i<k;i++)
		if (x[i]==x[k]) return 0;
	return 1;
}
int validcomb(int x[10],int k) {
	for (int i = 1;i<k;i++)
		if (x[k]==x[k-1]&&k>1) return 0;
	return 1;
}
int validaranj(int x[10],int k) {
	for (int i = 1;i<k;i++)
		if (x[k]==x[i])return 0;
	return 1;
}
bool valid_regine(int x[10],int k) {
	int i;
	for (i = 1; i<k; i++)
	{
		if (x[k]==x[i]||abs(k-i)==abs(x[k]-x[i]))
			return false;
	}
	return true;
}
bool valid_ture(int x[10],int k) {
	int i;
	for (i = 1; i<k; i++)
	{
		if (x[k]==x[i])
			return false;
	}
	return true;
}
int valid_cai(int x[10],int k) {
	int i = 0,v = 1;
	int a[8] = {-1,-2,-2,-1,1,2,2,1};
	int b[8] = {2,1,-1,-2,-2,-1,1,2};
	if (x[i]==x[k])
	{
		v = 0;
	} else
		for (i = 1; i<=k-1; i++)
			for (int p = 1; p<=8; p++)
				if (i==(k+a[p-1])&&x[i]==(x[k]+b[p-1]))
				{
					v = 0;
					break;
				}
	return v;
}
void costmin(int sat,int n,int** a,int* v) {
	int i,nsat,nc = 999,minim = 999,kminim,cost = 0;
	v[sat] = 1;
	cout<<sat+1<<"-->";
	for (i = 0;i<n;i++)
	{
		if ((a[sat][i]!=0)&&(v[i]==0))
			if (a[sat][i]+a[i][sat]<minim)
			{
				minim = a[i][0]+a[sat][i];
				kminim = a[sat][i];
				nc = i;
			}
	}
	if (minim!=999)
		cost += kminim;
	nsat = nc;
	if (nsat==999)
	{
		nsat = 0;
		cout<<nsat+1;
		cost += a[sat][nsat];
		return;
	}
	costmin(nsat,n,a,v);
}
void back_parant(int* x,int n,int &ns,int k) {
	int i,j,pi,pd;
	for (i = 0;i<=1;i++)
	{
		x[k] = i;
		pi = pd = 0;
		for (j = 1;j<=k;j++)
			if (x[j]==0)pd++;
			else pi++;
		if ((pd<=n/2)&&(pi<=pd))
			if (k==n)
			{
				ns++;
				cout<<"Solutia "<<ns<<" : \t";
				for (j = 1;j<=n;j++)
					if (x[j]==1)cout<<")";
					else cout<<"(";
				cout<<'\n';
			} else back_parant(x,n,ns,k+1);
	}
}
void gen_s(int k,int n,int*x ) 	{
  int i,j;
		for (i = 0;i<=1;i++)
		{
			x[k] = i;
			if (k==n)
			{
				cout<<"{";
				for (i = 1;i<=n;i++)
					if (x[i]==1)
						cout<<i<<" ";
				cout<<"}"<<'\n';
			}
			else
				gen_s(k+1,n,x);
		}
	}