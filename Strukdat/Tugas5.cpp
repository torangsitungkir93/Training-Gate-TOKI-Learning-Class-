

//================================================= //
//================ AUTHOR ========================= //
//=============== Torangto Situngkir ============== //
//================================================= //


#include <iostream>
#include <conio.h>
#include <string.h>
#define max 12
#define true 1
#define false 0
using namespace std;


int a,b;

struct barang {
	char kode[10],nama_barang[10],kategori[10];
	int jumlah;
};

typedef struct {
	barang info;
	int next;
} typenode;

typenode elemen[max];
int list,akhirlist,kosong,akhirkosong;
int listkosong();
void buatlist ();
void sisipnode (barang IB);
void hapusnode (barang IH);
void cetaklist ();
void data();
void search_nama(); // Void search 
void search_kode(); 
void search_jumlah();
void search_kategori();


int main () {
		
		char pilihan;
		buatlist();	
	do{
		menu :
		system("cls");
		cout<<"		+----------------------------+"<<endl;
		cout<<"		|          Pilihan           |"<<endl;
		cout<<"		|     [1] Tambah Data 	     |"<<endl;
		cout<<"		|     [2] Cari Data 	     |"<<endl;
		cout<<"		|     [3] Hapus Data 	     |"<<endl;
		cout<<"		|     [4] Tampil Data 	     |"<<endl;
		cout<<"		|     [ESC] EXIT     	     |"<<endl;
		cout<<"		+----------------------------+"<<endl;
		cout<<">>> ";
		pilihan=getch();
		switch (pilihan)
		{
			case '1':
				{
					system("cls");
					cout<<"================================================= "<<endl;
					cout<<"----------- Masukkan Data Barang Anda ----------- "<<endl;
					cout<<"================================================= "<<endl;
					data();
					getch();
					break;
				}
			case '2':
				{
					menu2 :
					char pilih_2;
					do{
						system("cls");
						cout<<"		+-------------------------------+"<<endl;
						cout<<"		|          Pencarian            |"<<endl;
						cout<<"		|     [1] Pencarian Nama        |"<<endl;
						cout<<"		|     [2] Pencarian Kode        |"<<endl;
						cout<<"		|     [3] Pencarian Jumlah      |"<<endl;
						cout<<"		|     [4] Pencarian Kategori    |"<<endl;
						cout<<"		|     [ESC] EXIT     	        |"<<endl;
						cout<<"		+-------------------------------+"<<endl;
						cout<<">>> ";
						pilih_2=getch();
						switch(pilih_2)
						{
							case '1':
								{
									search_nama();
									getch();
									break;
								}
							case '2':
								{
									
									search_kode();
									getch();
									break;
								}
							case '3':
								{
									
									search_jumlah();
									getch();
									break;
								}
							case '4':
								{
									
									search_kategori();
									getch();
									break;
								}
							case 27:
								{
									break;
								}
							default:
								{
									cout<<"============ Input yang anda masukkan salah ==========="<<endl;
									cout<<"              Press any key to continiue ....";
									getch();
									goto menu2 ;
								}
						}
					}while(pilih_2!=27);
					break;
				}
			case '3':
				{
					int n,cek;
					n=list;
					barang x;
					
					cout<<"====================================="<<endl;
					cout<<"---------- MENU HAPUS DATA ----------"<<endl;
					cout<<"====================================="<<endl;
					cout<<"Nama Barang : ";
					cin>>x.nama_barang;
					
					do
					{
					cek=strcmp(x.nama_barang,elemen[n].info.nama_barang);
					if(cek==0)
					{
						x=elemen[n].info;
					}
					n=elemen[n].next;
					}while(cek!=0&&n!=0);
		
					hapusnode(x);
					getch();
					system("cls");
					break;
				}
			case '4':
				{
					system("cls");
					cout<<"Tampil LIST"<<endl;
					cetaklist();
					getch();
					break;
				}
			case 27:
				{
					system("cls");
					cout<<"Terimakasih telah menggunakan program ini,jangan lupa mampir lagi :)"<<endl;
					exit(0);
					getch();
					break;
				}
			default:
				{
					cout<<"========== Input yang anda masukkan salah ==========="<<endl;
					cout<<"				Press any key to continiue ....";
					getch();
					goto menu ;
				}	
		}
	}while(pilihan!=5);
	getch();
	return 0;
}

void buatlist () {
	list=0;
	akhirlist=0;
	kosong=5;
	akhirkosong=10; // 5,3,6,2,9,4,1,8,7,10
	elemen[1].info.jumlah=0;		elemen [1].next =8;
	elemen[2].info.jumlah=0;		elemen [2].next =9;
	elemen[3].info.jumlah=0; 		elemen [3].next =6;
	elemen[4].info.jumlah=0; 		elemen [4].next =1;
	elemen[5].info.jumlah=0;		elemen [5].next =3;
	elemen[6].info.jumlah=0; 		elemen [6].next =2;
	elemen[7].info.jumlah=0; 		elemen [7].next =10;
	elemen[8].info.jumlah=0;		elemen [8].next =7;
	elemen[9].info.jumlah=0; 		elemen [9].next =4;
	elemen[10].info.jumlah=0; 		elemen [10].next =0;
	a=0; // Isi 
	b=10; // Yang kosong
}

int listkosong (){
	if (list==0) 
		return (true);
	else 
		return (false) ;
}

void sisipnode (barang IB ){
	int listbaru,k,m,n;
	barang x;
	
	
	if(b==0)
	{
		cout<<"Maaf Node Sudah penuh tidak bisa menambah data "<<endl;
	}
	else
	{
		// sisip pertama
		if(a==0)
		{
			listbaru = kosong;
			akhirlist= listbaru;
			kosong = elemen[listbaru].next;
			elemen[listbaru].info=IB;
			elemen[listbaru].next=0;
			list=listbaru;
			a++;
			b--;
		}
		else {
			
			// Sisip Diawal
			if (IB.jumlah<=elemen[list].info.jumlah)
			{
				listbaru = kosong;
				kosong = elemen[kosong].next;
				elemen[listbaru].info=IB;
				elemen[listbaru].next=list;
				list=listbaru;
				a++;
				b--;
			}
			// Sisip Akhir
			else if (IB.jumlah>elemen[akhirlist].info.jumlah){
				listbaru=kosong;
				kosong=elemen[kosong].next;
				elemen[listbaru].info=IB;
				elemen[listbaru].next =0;
				elemen[akhirlist].next =listbaru;
				akhirlist = listbaru;
				a++;
				b--;
				cout<<"SISIP AKHIR"<<endl;
			}
			//sisip tengah
			else {
				n=list;
				x=elemen[n].info;
				while (IB.jumlah>x.jumlah){
					m=n;
					n=elemen[n].next;
					x=elemen[n].info;
				}
				k=elemen[kosong].next;
				elemen[m].next=kosong;
				elemen[kosong].info=IB;
				elemen[kosong].next=n;
				kosong=k;
				a++;
				b--;
				cout<<"SISIP TENGAH"<<endl;	
			}
		}
//		cout<<"Index tempat yang kosong : ";
	}
//		m=kosong;
//		while(m!=0)
//		{
//			cout<<" "<<m;
//			m=elemen[m].next;
//		}
}

void cetaklist () {
	int n,i;
	n=list;
	i=0;
	cout<<"=========================================== \n";
	cout<<"------------- Isi List Barang ------------- \n";
	cout<<"=========================================== \n";
	if(a!=0)
	{
		do {
			i++;
			cout<<"Barang ke-"<<i<<endl;
			cout<<"Kode Barang     : "<<elemen[n].info.kode<<endl;
			cout<<"Nama Barang     : "<<elemen[n].info.nama_barang<<endl;
			cout<<"Kategori Barang : "<<elemen[n].info.kategori<<endl;
			cout<<"Jumlah Barang   : "<<elemen[n].info.jumlah<<endl;
			n=elemen[n].next;
			cout<<endl;
		}while (n!=0);
	}
	else{
		cout<<"Barang anda masih kosong ..."<<endl;
	}
}

void hapusnode (barang IH ) {
	int k,m,n;
	barang temp;
	//hapus awal
	if(a!=0)
	{
		if (IH.jumlah==elemen[list].info.jumlah){
			cout<<"HAPUS AWAL\n";
			k=kosong;
			kosong=list;
			list= elemen [list].next;
			elemen[kosong].next=elemen[k].next;
			cout<<list;
			a--;
			b++;
		}
		else if(IH.jumlah==elemen[akhirlist].info.jumlah)
		{
			cout <<"AKHIR LIST\n";
			m=list;
			while(elemen[m].next!=akhirlist)
			{
				m=elemen[m].next;
			}
			k=kosong;
			kosong=akhirlist;
			akhirlist=m;
			elemen[akhirlist].next=0;
			elemen[kosong].next=elemen[k].next;
			a--;
			b++;
		}
		else if((IH.jumlah>elemen[list].info.jumlah) && (IH.jumlah<elemen[akhirlist].info.jumlah)){
			cout<<"HAPUS TENGAH\n";
				n=list;
				temp=elemen[n].info;
				while (IH.jumlah>temp.jumlah){
					m=n;
					n=elemen[n].next;
					temp=elemen[n].info;
					cout<<"Hapus Tengah TEMPnya : "<<elemen[n].info.jumlah;
				}
				cout<<"end"<<endl;
			elemen[m].next=elemen[n].next;
			elemen[n].next=kosong;
			kosong = n;
			a--;
			b++;
		}
		else {
			cout<<"DATA TERSEBUT TIDAK ADAAAA !!! "<<endl;
			cout<<"					Press any key to continue .... ";
		}
	}
	else {
		cout<<"BARANG ANDA MASIH KOSONG !!! "<<endl;
		cout<<"					Press any key to continue .... ";
	}
}

void data ()
{
	int data;
	cout<<"Berapa banyak data : ";
	cin>>data;
	
	if(data<=b)
	{
		for(int i=0;i<data;i++)
		{
			cout<<"Barang ke-"<<i+1<<endl;cin.ignore();
			barang data_brg;
			cout<<"Kode Barang : ";
			cin.getline(data_brg.kode,(10));
			cout<<"Nama Barang  : ";
			cin.getline(data_brg.nama_barang,(10));
			cout<<"Kategori Barang : ";
			cin.getline(data_brg.kategori,(10));
			cout<<"Jumlah barang : ";
			cin>>data_brg.jumlah;
			sisipnode(data_brg);
			cout<<endl;
			a++;
			b--;
		}
	}
	else
	{
		cout<<"Anda memasukkan terlalu banyak Data Maks 10 untuk semua"<<endl;
		cout<<"======= DATA BARANG YANG SUDAH ANDA MASUKKAN : "<<a<<endl;
		cout<<"======= SISA MEMORI YANG BISA ANDA PAKAI : "<<b<<endl;
		cout<<"								Press any key to continue ...";
	}
}

void search_nama () {
	char search[10];
	int cek,count,n;
	barang name;
	count=0;
	n=list;
	cout<<"Masukkan nama barang : ";
	cin>>search;
		do
		{					
			cek=strcmp(search,elemen[n].info.nama_barang);
			if(cek==0)
				{
					count++;
					name=elemen[n].info;
					cout<<"Barang ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	Nama Barang     : "<<name.nama_barang<<endl;
					cout<<"#####	Kode Barang     : "<<name.kode<<endl;
					cout<<"#####	kategori Barang : "<<name.kategori<<endl;
					cout<<"#####	Jumlah Barang   : "<<name.jumlah<<endl;
					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}				
			n=elemen[n].next;
		}while(n!=0);
		if(count==0)
		{
			cout<<"Data yang anda cari tidak ada "<<endl;
		}
		cout<<"================ Press any key to continiue ... ";
}

void search_kategori () {
	char search[10];
	int cek,count,n;
	barang kat;
	count=0;
	n=list;
	cout<<"Masukkan kategori barang : ";
	cin>>search;
		do
		{					
			cek=strcmp(search,elemen[n].info.kategori);
			if(cek==0)
				{
					count++;
					kat=elemen[n].info;
					cout<<"Barang ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	Nama Barang     : "<<kat.nama_barang<<endl;
					cout<<"#####	Kode Barang     : "<<kat.kode<<endl;
					cout<<"#####	kategori Barang : "<<kat.kategori<<endl;
					cout<<"#####	Jumlah Barang   : "<<kat.jumlah<<endl;
					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}				
			n=elemen[n].next;
		}while(n!=0);
		if(count==0)
		{
			cout<<"Data yang anda cari tidak ada "<<endl;
		}
		cout<<"================ Press any key to continiue ... ";
}

void search_kode (){
	char search[10];
	int cek,count,n;
	barang kode;
	count=0;
	n=list;
	cout<<"Masukkan kode barang : ";
	cin>>search;
		do
		{					
			cek=strcmp(search,elemen[n].info.kode);
			if(cek==0)
				{
					count++;
					kode=elemen[n].info;
					cout<<"Barang ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	Nama Barang     : "<<kode.nama_barang<<endl;
					cout<<"#####	Kode Barang     : "<<kode.kode<<endl;
					cout<<"#####	kategori Barang : "<<kode.kategori<<endl;
					cout<<"#####	Jumlah Barang   : "<<kode.jumlah<<endl;
					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}	
			n=elemen[n].next;
		}while(n!=0);
		if(count==0)
		{
			cout<<"Data yang anda cari tidak ada "<<endl;
		}
		cout<<"================ Press any key to continiue ... ";
}

void search_jumlah (){
	int search;
	int count,n;
	barang jumlah;
	count=0;
	n=list;
	cout<<"Masukkan Jumlah barang : ";
	cin>>search;
		do
		{					
			if(search==elemen[n].info.jumlah)
				{
					count++;
					jumlah=elemen[n].info;
					cout<<"Barang ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	Nama Barang     : "<<jumlah.nama_barang<<endl;
					cout<<"#####	Kode Barang     : "<<jumlah.kode<<endl;
					cout<<"#####	kategori Barang : "<<jumlah.kategori<<endl;
					cout<<"#####	Jumlah Barang   : "<<jumlah.jumlah<<endl;
					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}	
			n=elemen[n].next;
		}while(n!=0);
		if(count==0)
		{
			cout<<"Data yang anda cari tidak ada "<<endl;
		}
		cout<<"================ Press any key to continiue ... ";
}
