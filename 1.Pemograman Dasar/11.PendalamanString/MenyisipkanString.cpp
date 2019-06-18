#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string s="Pak Dengklek beternak";
	string t="dan Bu ";
	
	s.insert(4,t);
	cout<<s.c_str()<<endl; //P dan Bu Dengklek beternak
}
