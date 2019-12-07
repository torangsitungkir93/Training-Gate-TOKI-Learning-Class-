// ----------------------------------- //
//	Author : Torangto Situngkir   //
//		 Agave Yonatan	       //
// ----------------------------------- //

#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <windows.h>

//---- Queue ----//
#define max_queue 50
#define max_list 30

//---- WARNA ----//
#define putih 15  
#define abu 8					
#define hijau 10
#define biru 9														
#define merah 12													
#define sky 11			
#define kuning 14
#define hitam 0
#define ungu 13

using namespace std;

// Untuk Hiasan Template **********
void garis1(int n);
void header_program();
void temp_judul();
void mainMenu();
void menuPasien();
void exitProgram();
void lihatAntrian();

// Untuk Hiasan Setting ***********
void gotoxy(int x,int y);
void SetColor(char text,char bg);

// Untuk Antrian **********
struct typequeue {
	int belakang;
	char elemen[max_queue][20];
};
struct typequeue queue;
void buatqueue();
void cetakqueue();
void enqueue (char IB[20]);
void dequeue();
int isEmpty_queue();
int isFull_queue();
void lihatAntrian();

// Untuk Linked List ***********

int a,b,jml_pasien=1,cek_que=0;

struct pasien {
	int umur, biaya, nomor;
	char nama[20], jk[3], goldar[3], poli[20], nik[20];
};

typedef struct {
	pasien info;
	int next;
} typenode;

typenode elemen[max_list];
int list, akhirlist, kosong, akhirkosong;
int listkosong();
void buatlist();
void sisipnode(pasien IB);
void hapusnode(pasien IH);
void printPasien();
void search1();
void search2();
void search3();
void menuSearch();
void data_pasien(char nama[20]);

// Untuk File Handling ***********
void file_request();
FILE *input_pasien;
FILE *read_pasien;
FILE *delete_pasien;
FILE *input_queue;
FILE *read_queue;
FILE *delete_queue;
char myFileQueue[20],myFileList[20];


// --------------------------------------- //
// ************ MAIN CONTENT ************* //
// --------------------------------------- //

int main(){
	header_program();
	buatlist();
	file_request();
	char pilih;
	do{	
	mainMenu();
	pilih=getch();Beep(2500,75);
	switch(pilih)
	{
		case '1' :
			{
				int choice;
				char que[20];
					do{
					menuPasien();
					cin>>choice;
					switch(choice){
						case 1 :
						{
							char pasien[20];
							cin.ignore();
							system("cls");
							temp_judul();
							input_queue=fopen(myFileQueue,"a");
							cout<<"Masukkan Nama Pasien Antrian : ";
							cin.getline(pasien,20);
							strcpy(que,pasien);
							fwrite(&que,sizeof(que),1,input_queue);
							fclose(input_queue);
							enqueue(pasien);
							cout<<queue.elemen[0];
							getch();
							break;
						}
						case 2 :
						{
							system("cls");
							temp_judul();
							dequeue();
							getch();
							break;
						}
						case 3 :
						{
							system("cls");
							temp_judul();
							cout<<setw(65)<<"+--------------------------+"<<endl;
							cout<<setw(65)<<"|====== | Antrian | =======|"<<endl;
							cout<<setw(65)<<"+--------------------------+"<<endl;
							cout<<setw(65)<<"|            ^             |"<<endl;
							cetakqueue();
							if(isEmpty_queue()){
							cout<<setw(44)<<"|      ";
							SetColor(sky,hitam);cout<<"Antrian KOSONG !";SetColor(putih,hitam);	
							cout<<"    |"<<endl;
							}
							cout<<setw(65)<<"+--------------------------+"<<endl;
							getch();
							break;
						}
						case 4 :
						{
							break;
						}
						default :
						{
							SetColor(merah,hitam);	
							cout<<"Angkan yang anda inputkan salah !!"<<endl;
							SetColor(putih,hitam);	
							getch();
							
							break;
						}
					}
				}while(choice!=4);
					break;
			}
		case '2' :
			{
				system("cls");
				temp_judul();
				if(listkosong()){
					SetColor(merah,hitam);
					cout<<"Pasien Masih kosong,Silahkan Antri !! "<<endl;
					SetColor(putih,hitam);
					gotoxy(35,10);cout<<"Press Any key to continue ... ";
				}else{
					printPasien();
				}
				getch();
				break;
			}
		case '3' :
			{
				int choice;
				if(listkosong()){
					SetColor(merah,hitam);
					cout<<"Data Pasien Masih kosong !! "<<endl;
					SetColor(putih,hitam);
				}else{
					do{
					menuSearch();
					cin>>choice;
					cout<<endl;
						switch(choice){
							case 1:{
								search1();
								getch();
								break;
							}
							case 2:{
								search2();
								getch();
								break;
							}
							case 3:{
								search3();
								getch();
								break;
							}
							case 4:{
								
								break;
							}
							default : {
								SetColor(merah,hitam);
								cout<<"Inputan anda salah Pilih (1..3)"<<endl;
								SetColor(putih,hitam);
								getch();
								break;
							}
						}
					}while(choice!=4);
				}
				getch();
				break;
			}
		case '4' :
			{
				system("cls");
				temp_judul();
				int n,cek;
				n=list;
				pasien x;
				
				cout<<"====================================="<<endl;
				cout<<"---------- MENU HAPUS DATA ----------"<<endl;
				cout<<"====================================="<<endl;
				cout<<"NIK : ";
				cin>>x.nik;
				
				do
				{
				cek=strcmp(x.nik,elemen[n].info.nik);
				if(cek==0)
				{
					x=elemen[n].info;
				}
				n=elemen[n].next;
				}while(cek!=0&&n!=0);
				hapusnode(x);
				getch();
				break;
			}
		case 27 :
		{
			exitProgram();
			break;
		}
		default :
			{
				cout<<"Tekan (1..4) !!! "<<endl;

				getch();
				break;
			}
	}
}while(pilih!=27);
	return 0;
}

// --------------------------------------- //
// *************************************** //
// --------------------------------------- //


//*********************** FLOWER **********************//

void garis1(int n){
	for(int i=0;i<n;i++){
		cout<<"-";
	}	
}

void temp_judul ()
{
cout<<"+==================================================================================================+"<<endl;
cout<<"|---------------------------------||"; 
SetColor(kuning,hitam);
cout<<"Sistem Informasi Rumah Sakit";
SetColor(putih,hitam);
cout<<"||---------------------------------|"<<endl;
cout<<"+==================================================================================================+"<<endl;
time_t now =time(0);
	char * dt = ctime(&now);
	SetColor(hijau,hitam);
	cout<<"Time : "<<dt<<endl;
	SetColor(putih,hitam);
}

void header_program()
{
		cout << endl << endl << endl << endl << endl << endl << endl;
		SetColor(hijau,hitam);	
		cout<<setw(10)<<" "; garis1(80);cout<<endl;
		SetColor(putih,hitam);	
		cout << setw(82) << "S1 Informatika - Universitas Pembangunan Veteran Yogyakarta \n\n";
		cout << setw(55) << "2019\n\n";
		SetColor(hijau,hitam);	
		cout<<setw(10)<<" "; garis1(80);cout<<endl;
		SetColor(putih,hitam);	
		cout << endl << endl << endl;
		cout << setw(65) << "press any key to continue...";
		getch();
}

void mainMenu(){
	system("cls");
	temp_judul();
	cout<<endl;
	cout << setw(63) << "+=========================+" << endl;
	cout << setw(63) << "|  ***   MENU UTAMA  ***  |" << endl;
	cout << setw(63) << "+-------------------------+" << endl;
	cout << setw(63) << "| [1] Antri Pasien        |" << endl;  
	cout << setw(63) << "| [2] Data Pasien         |" << endl;   
	cout << setw(63) << "| [3] Searching           |" << endl;   
	cout << setw(63) << "| [4] Hapus Data          |" << endl;   
	cout << setw(63) << "| [ESC] Exit              |" << endl;   
	cout << setw(63) << "+=========================+" << endl << endl;
	cout<<"Pilih >> ";
}

void menuPasien(){
	system("cls");
	temp_judul();
	cout<<endl;
	cout << setw(63) << "+=========================+" << endl;
	cout << setw(63) << "|  ** ANTRIAN PASIEN **   |" << endl;
	cout << setw(63) << "+-------------------------+" << endl;
	cout << setw(63) << "| [1] Tambah Antrian      |" << endl;  
	cout << setw(63) << "| [2] Panggil Antrian     |" << endl;   
	cout << setw(63) << "| [3] Lihat Antrian       |" << endl;   
	cout << setw(63) << "| [4] Kembali             |" << endl;   
	cout << setw(63) << "+=========================+" << endl << endl;
	cout << "Pilih >>> ";
}

void menuSearch(){
	system("cls");
	temp_judul();
	cout<<endl;
	cout << setw(63) << "+=========================+" << endl;
	cout << setw(63) << "| ** Searching PASIEN **  |" << endl;
	cout << setw(63) << "+-------------------------+" << endl;
	cout << setw(63) << "| [1] Search NIK          |" << endl;  
	cout << setw(63) << "| [2] Search Nama Pasien  |" << endl;   
	cout << setw(63) << "| [3] Search Nama Poli    |" << endl;   
	cout << setw(63) << "| [4] Kembali             |" << endl;   
	cout << setw(63) << "+=========================+" << endl << endl;
	cout << "Pilih >>> ";
}

void exitProgram(){
	cout<<endl;
	garis1(30);
	cout<<endl;
	gotoxy (18,18);cout<<"Terimakasih telah menggunakan Program ini !!"<<endl;
	gotoxy (18,19);cout<<"Autor : Torangto Situngkir "<<endl;
	gotoxy (18,20);cout<<"        Agave Yonathan"<<endl;
}
//*********************** Untuk Hiasan Setting **********************//

void gotoxy(int x, int y){
   COORD k = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void SetColor(char text,char bg)  //UNTUK SET WARNA BORDER DAN TEXT
{
	unsigned short color=bg*16+text;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}

//*********************** Untuk Queue **********************//
void buatqueue ()
{
	queue.belakang=0;
}

int isFull_queue()
{
	if(queue.belakang==max_queue)
	{
		return (true);
	}
	else
	return (false);
}

int isEmpty_queue()
{
	if(queue.belakang==0)
	{
		return (true);
	}
	else
	return (false);
}

void enqueue(char IB[20]){
	if(isFull_queue()){
		SetColor(merah,hitam);	
		cout<<"Antrian Penuh "<<endl;
		SetColor(putih,hitam);	
	}
	else {
		queue.belakang++;
		strcpy(queue.elemen[queue.belakang],IB);
		if(cek_que!=0){
		SetColor(sky,hitam);	
		cout<<"Antrian Bertambah 1 ! "<<endl;
		SetColor(putih,hitam);	
		gotoxy(35,10);cout<<"Press Any key to continue ... ";
	}
	}
}

void dequeue (){
	int i;
	char ID[20];
	if(isEmpty_queue()){
		SetColor(merah,hitam);	
		gotoxy(39,5);cout<<"Antrian Kosong !"<<endl;
		SetColor(putih,hitam);	
		gotoxy(35,8);cout<<"Press Any key to continue ... ";
	}
	else if (b!=0){
		char que[20];
		strcpy(ID,queue.elemen[1]);
		cout<<"                             Panggil "<<queue.elemen[1]<<" dari Antrian !! "<<endl;
		for(i=1;i<queue.belakang;i++)
		{
			strcpy(queue.elemen[i],queue.elemen[i+1]);
		}
		queue.belakang--;
		data_pasien(ID);
		gotoxy(35,28);cout<<"Press Any key to continue ... ";
		read_queue=fopen(myFileQueue,"r");
		delete_queue=fopen("temporarybag2.txt","w");
		while (fread(&que,sizeof(que),1,read_queue)){
			if(strcmp(que,ID)!=0){
				fwrite(&que,sizeof(que),1,delete_queue);
			}
		}
		fclose(delete_queue);
		fclose(read_queue);
		remove(myFileQueue);
		rename("temporarybag2.txt",myFileQueue);
	}
	else{
		SetColor(merah,hitam);	
		gotoxy(39,5);cout<<"Node Pasien Penuh !"<<endl;
		SetColor(putih,hitam);	
		gotoxy(35,8);cout<<"Press Any key to continue ... ";
	}
	
}

void cetakqueue(){
	int i=1;
	while(i<=queue.belakang)
	{
		gotoxy(37,8+i);cout<<"| ";
		cout<<queue.elemen[i];
		gotoxy(64,8+i);cout<<"|";
		cout<<endl;
		i++;
	}
}

//----- Untuk Menu Antrian ---- //

void lihatAntrian(){
	system("cls");
	temp_judul();
	gotoxy (3,7);cout<<"+===========================================================================================+"<<endl;
	gotoxy (3,8);cout<<"| NO |      Nama Pasien      |  NIK Pasien | JK | Darah | Umur |      Poli      |   Biaya   | "<<endl;
	gotoxy (3,9);cout<<"+===========================================================================================+"<<endl;
	gotoxy (3,10);cout<<"|  ";
	gotoxy (4,10);cout<<"212";
	gotoxy (8,10); cout<<"| ";
	gotoxy (10,10); cout<<"Torangto Situngkir";
	gotoxy (32,10); cout<<"| ";
	gotoxy (34,10);cout<<"123180122"<<endl;
	gotoxy (46,10); cout<<"| ";
	gotoxy (48,10);cout<<"L"<<endl;
	gotoxy (51,10);cout<<"| "<<endl;
	gotoxy (53,10);cout<<"AB"<<endl;
	gotoxy (59,10);cout<<"| "<<endl;
	gotoxy (61,10);cout<<"17"<<endl;
	gotoxy (66,10);cout<<"| "<<endl;
	gotoxy (68,10);cout<<"Umum"<<endl;
	gotoxy (83,10);cout<<"| Rp "<<endl;
	gotoxy (87,10);cout<<"90000"<<endl;
	gotoxy (95,10);cout<<"| "<<endl;
	gotoxy (3,11);cout<<"+-------------------------------------------------------------------------------------------+"<<endl;
	
}



//*********************** Untuk Linked List **********************//

void buatlist(){
	list=0;
	kosong=8; //8, //2, //5, //1, //7, //4, //3, //6, //10, //14, //17, //12, //11, //16, //21, //20, //25, //19, //13, //23, //18, //26, //15, //22, //24 
	akhirlist=0;
	akhirkosong =9;
	elemen[1].info.nomor=0; elemen [1].next =7;
	elemen[2].info.nomor=0; elemen [2].next =5;
	elemen[3].info.nomor=0; elemen [3].next =6;
	elemen[4].info.nomor=0; elemen [4].next =3;
	elemen[5].info.nomor=0; elemen [5].next =1;
	elemen[6].info.nomor=0; elemen [6].next =10;
	elemen[7].info.nomor=0; elemen [7].next =4;
	elemen[8].info.nomor=0; elemen [8].next =2;
	elemen[9].info.nomor=0; elemen [9].next =0;
	elemen[10].info.nomor=0; elemen [10].next =14;
	elemen[11].info.nomor=0; elemen [11].next =16;
	elemen[12].info.nomor=0; elemen [12].next =11;
	elemen[13].info.nomor=0; elemen [13].next =23;
	elemen[14].info.nomor=0; elemen [14].next =17;
	elemen[15].info.nomor=0; elemen [15].next =22;
	elemen[16].info.nomor=0; elemen [16].next =21;
	elemen[17].info.nomor=0; elemen [17].next =12;
	elemen[18].info.nomor=0; elemen [18].next =26;
	elemen[19].info.nomor=0; elemen [19].next =13;
	elemen[20].info.nomor=0; elemen [20].next =25;
	elemen[21].info.nomor=0; elemen [21].next =20;
	elemen[22].info.nomor=0; elemen [22].next =24;
	elemen[23].info.nomor=0; elemen [23].next =18;
	elemen[24].info.nomor=0; elemen [24].next =9;
	elemen[25].info.nomor=0; elemen [25].next =19;
	elemen[26].info.nomor=0; elemen [26].next =15;
	a=0; // jumlah node terisi
	b=30; // jumlah node yang kosong
}

int listkosong (){
	if (a==0)
		return (true);
	else
		return (false) ;
}

void sisipnode (pasien IB){
	int listbaru, k, m, n;
	pasien orang;
	jml_pasien++;
	if (b==0) {
		SetColor(merah,hitam);	
		cout<<"Node Tidak Tersedia" << endl;
		SetColor(putih,hitam);	
	}
	// sisip pertama
	else if (list==0) {
		listbaru = kosong;
		akhirlist=listbaru;
		kosong = elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=0;
		list=listbaru;
		a++;
		b--;
	}
	// sisip awal
	else if (IB.nomor<elemen[list].info.nomor)
	{
		listbaru = kosong;
		kosong = elemen[kosong].next;
		elemen[listbaru].info=IB;
		elemen[listbaru].next=list;
		list=listbaru;
		a++;
		b--;
	}
	//sisip akhir
	else {
		if (IB.nomor>elemen[akhirlist].info.nomor){
			listbaru=kosong;
			kosong=elemen[kosong].next;
			elemen[listbaru].info=IB;
			elemen[listbaru].next =0;
			elemen[akhirlist].next =listbaru;
			akhirlist = listbaru;
			a++;
			b--;
		}
		//sisip tengah
		else {
			n=list;
			orang=elemen[n].info;
			while (IB.nomor>orang.nomor){
				m=n;
				n=elemen[n].next;
				orang=elemen[n].info;
			}
			k=elemen[kosong].next;
			elemen[m].next=kosong;
			elemen[kosong].info=IB;
			elemen[kosong].next=n;
			kosong=k;
			a++;
			b--;
		}
	}
}

void printPasien(){
	int n, m;
	n=list;
	m=kosong;
	cout<<"\nISI LIST" << endl;
	if (a==0){
		SetColor(merah,hitam);	
		cout<<"TIDAK ADA LIST" << endl;
		SetColor(putih,hitam);	
	}
	else {
		int cek=0;
		gotoxy (3,7);cout<<"+===========================================================================================+"<<endl;
		gotoxy (3,8);cout<<"| NO |      Nama Pasien      |  NIK Pasien | JK | Darah | Umur |      Poli      |   Biaya   | "<<endl;
		gotoxy (3,9);cout<<"+===========================================================================================+"<<endl;
		do {
//			cout << "Pasien ke-[" << i << "]" << endl;
		gotoxy (3,10+cek);cout<<"|  ";
		gotoxy (4,10+cek);cout<<elemen[n].info.nomor;
		gotoxy (8,10+cek); cout<<"| ";
		gotoxy (10,10+cek); cout<<elemen[n].info.nama;
		gotoxy (32,10+cek); cout<<"| ";
		gotoxy (34,10+cek);cout<<elemen[n].info.nik;
		gotoxy (46,10+cek); cout<<"| ";
		gotoxy (48,10+cek);cout<<elemen[n].info.jk;
		gotoxy (51,10+cek);cout<<"| "<<endl;
		gotoxy (53,10+cek);cout<<elemen[n].info.goldar;
		gotoxy (59,10+cek);cout<<"| "<<endl;
		gotoxy (61,10+cek);cout<<elemen[n].info.umur;
		gotoxy (66,10+cek);cout<<"| "<<endl;
		gotoxy (68,10+cek);cout<<elemen[n].info.poli;
		gotoxy (83,10+cek);cout<<"| Rp "<<endl;
		gotoxy (87,10+cek);cout<<elemen[n].info.biaya;
		gotoxy (95,10+cek);cout<<"| "<<endl;
			n=elemen[n].next;
			cout<<endl;
				cek++;
		}while (elemen[n].next!=0);
			if (a>1){
//			cout << "Pasien ke-[" << i << "]" << endl;
		gotoxy (3,10+cek);cout<<"|  ";
		gotoxy (4,10+cek);cout<<elemen[n].info.nomor;
		gotoxy (8,10+cek); cout<<"| ";
		gotoxy (10,10+cek); cout<<elemen[n].info.nama;
		gotoxy (32,10+cek); cout<<"| ";
		gotoxy (34,10+cek);cout<<elemen[n].info.nik;
		gotoxy (46,10+cek); cout<<"| ";
		gotoxy (48,10+cek);cout<<elemen[n].info.jk;
		gotoxy (51,10+cek);cout<<"| "<<endl;
		gotoxy (53,10+cek);cout<<elemen[n].info.goldar;
		gotoxy (59,10+cek);cout<<"| "<<endl;
		gotoxy (61,10+cek);cout<<elemen[n].info.umur;
		gotoxy (66,10+cek);cout<<"| "<<endl;
		gotoxy (68,10+cek);cout<<elemen[n].info.poli;
		gotoxy (83,10+cek);cout<<"| Rp "<<endl;
		gotoxy (87,10+cek);cout<<elemen[n].info.biaya;
		gotoxy (95,10+cek);cout<<"| "<<endl;
			cek++;
//			do {
//				cout<<m<<" ";
//				m=elemen[m].next;
//			} while (elemen[m].next!=0);
//			if (b==1){
//				cout<<" "<<akhirkosong<<endl;
//		}
	}
	cout<<"   +-------------------------------------------------------------------------------------------+"<<endl;
	
}
}
void hapusnode (pasien IH) { //penghapusan berdasarkan nik
	int k,m,n,cek=0;
	pasien temp,cek_pasien,orang;
	//hapus awal
	if(a!=0)
	{
		SetColor(merah,hitam);	
		pasien cek_pasien;
		if (IH.nomor==elemen[list].info.nomor){
			cout<<"Data Pasien >>> "<<IH.nama<<" Terhapus !!! "<<endl;
			strcpy(cek_pasien.nama,IH.nama);
			k=kosong;
			kosong=list;
			list= elemen [list].next;
			elemen[kosong].next=elemen[k].next;
			a--;
			b++;
			cek++;
		}
		else if(IH.nomor==elemen[akhirlist].info.nomor)
		{
			cout<<"Data Pasien >>> "<<IH.nama<<" Terhapus !!! "<<endl;
			strcpy(cek_pasien.nama,IH.nama);
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
			cek++;
		}
		else if((IH.nomor>elemen[list].info.nomor) && (IH.nomor<elemen[akhirlist].info.nomor)){
			cout<<"Data Pasien >>> "<<IH.nama<<" Terhapus !!! "<<endl;
			strcpy(cek_pasien.nama,IH.nama);
				n=list;
				temp=elemen[n].info;
				while (IH.nomor>temp.nomor){
					m=n;
					n=elemen[n].next;
					temp=elemen[n].info;
				}
			elemen[m].next=elemen[n].next;
			elemen[n].next=kosong;
			kosong = n;
			a--;
			b++;
			cek++;
			SetColor(putih,hitam);	
			gotoxy(35,28);cout<<"Press Any key to continue ... ";
		}
		else {
			SetColor(merah,hitam);	
			cout<<"DATA TERSEBUT TIDAK ADAAAA !!! "<<endl;
			SetColor(putih,hitam);	
			cout<<"					Press any key to continue .... ";
		}
		if(cek!=0){
			read_pasien=fopen(myFileList,"rb");
			delete_pasien=fopen("temporarybag.txt","w");
			while(fread(&orang,sizeof(orang),1,read_pasien)){
				if(orang.nama!=cek_pasien.nama){
					fwrite(&orang,sizeof(orang),1,delete_pasien);
				}
			fclose(delete_pasien);
		}
		fclose(read_pasien);
		remove(myFileList);
		rename("temporarybag.txt",myFileList);
		}
	}
	else {
		SetColor(merah,hitam);	
		cout<<"PASIEN ANDA MASIH KOSONG !!! "<<endl;
		SetColor(putih,hitam);	
		cout<<"					Press any key to continue .... ";
	}
}

void search1 (){ //pencarian dengan nik
	char search[20];
	int m, i, cek, count;
	m=list;
	count=0;
	pasien orang;
	cin.ignore();
	cout<<"Masukkan NIK Pasien:"; cin.getline(search,sizeof(search));
		do
		{					
			cek=strcmp(search,elemen[m].info.nik);
			if(cek==0)
				{
					count++;
					orang=elemen[m].info;
					cout<<"Pasien ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	nik Pasien      : "<<orang.nik<<endl;
					cout<<"#####	Nama Pasien     : "<<orang.nama<<endl;
					cout<<"#####	Nomor Pasien    : "<<orang.nomor<<endl;
					cout<<"#####	Umur Pasien     : "<<orang.umur<<endl;
					cout<<"#####	Jenis Kelamin   : "<<orang.jk<<endl;
					cout<<"#####	Golongan Darah  : "<<orang.goldar<<endl;
					cout<<"#####	Poli            : "<<orang.poli<<endl;
					cout<<"#####	Biaya           : "<<orang.biaya<<endl;
					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}				
			m=elemen[m].next;
		}while(m!=0);
		if(count==0)
		{
			SetColor(merah,hitam);	
			cout<<"Data yang anda cari tidak ada "<<endl;
			SetColor(putih,hitam);	
		}
		cout<<"================ Press any key to continiue ... ";
}

void search2 (){ //pencarian dengan nama
	char search[20];
	int m, i, cek, count;
	m=list;
	count=0;
	pasien orang;
	cin.ignore();
	cout<<"Masukkan Nama Pasien:"; cin.getline(search,sizeof(search));
		do
		{					
			cek=strcmp(search,elemen[m].info.nama);
			if(cek==0)
				{
					count++;
					orang=elemen[m].info;
					cout<<"Pasien ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	NIK Pasien      : "<<orang.nik<<endl;
					cout<<"#####	Nama Pasien     : "<<orang.nama<<endl;
					cout<<"#####	Nomor Pasien    : "<<orang.nomor<<endl;
					cout<<"#####	Umur Pasien     : "<<orang.umur<<endl;
					cout<<"#####	Jenis Kelamin   : "<<orang.jk<<endl;
					cout<<"#####	Golongan Darah  : "<<orang.goldar<<endl;
					cout<<"#####	Poli            : "<<orang.poli<<endl;
					cout<<"#####	Biaya           : "<<orang.biaya<<endl;

					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}				
			m=elemen[m].next;
		}while(m!=0);
		if(count==0)
		{
			SetColor(merah,hitam);	
			cout<<"Data yang anda cari tidak ada "<<endl;
			SetColor(putih,hitam);	
		}
		cout<<"================ Press any key to continiue ... ";
}

void search3 (){ //pencarian dengan nama poli
	char search[20];
	int m, i, cek, count;
	m=list;
	count=0;
	pasien orang;
	cin.ignore();
	cout<<"Masukkan Nama Poli:"; cin.getline(search,sizeof(search));
		do
		{					
			cek=strcmp(search,elemen[m].info.poli);
			if(cek==0)
				{
					count++;
					orang=elemen[m].info;
					cout<<"Pasien ke-"<<count<<endl;
					cout<<"===================================="<<endl;
					cout<<"#####	NIK Pasien      : "<<orang.nik<<endl;
					cout<<"#####	Nama Pasien     : "<<orang.nama<<endl;
					cout<<"#####	Nomor Pasien    : "<<orang.nomor<<endl;
					cout<<"#####	Umur Pasien     : "<<orang.umur<<endl;
					cout<<"#####	Jenis Kelamin   : "<<orang.jk<<endl;
					cout<<"#####	Golongan Darah  : "<<orang.goldar<<endl;
					cout<<"#####	Poli            : "<<orang.poli<<endl;
					cout<<"#####	Biaya           : "<<orang.biaya<<endl;
					cout<<"===================================="<<endl;
					cout<<endl<<endl;
				}				
			m=elemen[m].next;
		}while(m!=0);
		if(count==0)
		{
			SetColor(merah,hitam);	
			cout<<"Data yang anda cari tidak ada "<<endl;
			SetColor(putih,hitam);	
		}
		cout<<"================ Press any key to continue ... ";
}

void data_pasien(char nama[20]){
	int jumlah;
	pasien orang;
	input_pasien=fopen(myFileList,"a");
	cout<<endl; 
	cout << "         ============" << endl;
	cout << "         Tambah Data " << endl;
	cout << "         ============" << endl;
	cin.ignore();
	strcpy(orang.nama,nama);
	orang.nomor=jml_pasien;
	cout << "   Nomor Pasien    : "<<orang.nomor<<endl;
	cout << "   Nama Pasien     : "<<nama<<endl;
	cout << "   NIK             : "; cin.getline(orang.nik, sizeof(orang.nik));
	cout << "   Umur Pasien     : "; cin >> orang.umur;
	cin.ignore();
	cout << "   Jenis Kelamin   : "; cin.getline(orang.jk, sizeof(orang.jk));;
	cout << "   Golongan Darah  : "; cin.getline(orang.goldar, sizeof(orang.goldar));
	cout <<"    Poli (Kandungan,Anak,Mata,Syaraf,Psikologi,Fisioterapi,Radiologi)"<<endl;
	cout << "   Poli            : "; cin.getline(orang.poli, sizeof(orang.poli));
	cout << "   Biaya           : "; cin >> orang.biaya;
	fwrite(&orang,sizeof(orang),1,input_pasien);
	fclose(input_pasien);
	sisipnode(orang); 
}

void file_request(){
	system("cls");
	temp_judul();
	char add_file[100],que[20];
	pasien orang;
	
	cout<<" ** Masukkan Nama file yg anda ingin tambah data : ";
	cin>>add_file;
	strcpy(myFileQueue,add_file);
	strcat(add_file,"_list.txt");
	strcpy(myFileList,add_file);
	strcat(myFileQueue,"_queue.txt");
	
	input_pasien=fopen(myFileList,"r");
	input_queue=fopen(myFileQueue,"r");
	if((input_pasien==NULL)&&(input_queue==NULL))
	{	
		SetColor(hijau,hitam);
		cout<<"=======|Anda membuat file baru|======="<<endl;
		SetColor(putih,hitam);
		gotoxy(35,8);cout<<"Press Any key to continue ... ";
		cek_que=11;
	}
	else
	{
		SetColor(biru,hitam);
		cout<<"=======|Anda akan memakai data data di file lama|======="<<endl;
		SetColor(putih,hitam);
		read_queue=fopen(myFileQueue,"r");
		while(fread(&que,sizeof(que),1,read_queue)){
			enqueue(que);
		}
		cek_que=11;
		fclose(read_queue);
		
		read_pasien=fopen(myFileList,"r");
		while(fread(&orang,sizeof(orang),1,read_pasien)){
			sisipnode(orang);
		}
		fclose(read_pasien);
		gotoxy(35,8);cout<<"Press Any key to continue ... ";
		
	}
	fclose(input_pasien);
	fclose(input_queue);
	getch();
}

