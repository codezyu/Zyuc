//
// Created by 风格福德宫 on 2022/4/27.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	char c[10]={0};
	for(int i=0;i<s.size();i++)
	{
		c[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(c[i])
		{
			cout<<c[i];
			c[i]--;
		}
	}
}
