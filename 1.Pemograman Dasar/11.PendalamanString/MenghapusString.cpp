#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string n="Pak Dengklek beternak";
	n.erase(1, 3);
	
	cout<<n.c_str()<<endl; // PDengklek beternak
}
