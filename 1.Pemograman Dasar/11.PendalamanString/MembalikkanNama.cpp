#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
	char s[10001];
	cin>>s;
	int len=strlen(s);
	for(int i=len-1;i>=0;i--)
	{
		cout<<" "<<s[i]<<endl;
	}
	
}
