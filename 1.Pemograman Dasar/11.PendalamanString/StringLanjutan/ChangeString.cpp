#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string s="toki";
	int size=s.size();
	for(int i =0;i<size;i++)
	{
		s[i] -= 'a'-'A';
	}
	cout<<s.c_str(); // TOKI
}
