#include<bits/stdc++.h>

using namespace std;

signed main()
{
	string myFname="tmp\\my.out",ansFname="tmp\\ans.out";
	int comp=0;
	string tmp="fc /w "+myFname+" "+ansFname;
	comp=system(tmp.c_str());
	return comp;
}
