#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string s="Pak Dengklek beternak";
	
	cout<<s.substr(0, 6).c_str(); //Pak De
	cout<<endl;
	cout<<s.substr(2,1).c_str(); //k
}
