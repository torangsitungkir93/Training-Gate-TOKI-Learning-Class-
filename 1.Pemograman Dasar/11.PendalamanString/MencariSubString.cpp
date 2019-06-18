#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string s="Pak Dengklek beternak";
	string t1="Dengklek";
	string t2="pak";
	string t3="ak";
	
	//Perhitungan dimulai dari 0
	
	cout<<s.find(t1)<<endl; // 4 
	cout<<s.find(t2)<<endl; // -1 (tak ditemukan) 
	cout<<s.find(t3)<<endl; // 8  
}
