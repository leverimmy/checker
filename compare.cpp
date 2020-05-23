#include<bits/stdc++.h>
#define rgi register int
#define ll long long
class fastin{
	private: int _ch,_f;
	public: template<typename _Tp> inline fastin& operator>>(_Tp&_x){
		_x=0; while(!isdigit(_ch)) _f|=(_ch==45),_ch=getchar();
		while(isdigit(_ch)) _x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
		_f&&(_x=-_x,_f=0); return *this;}
	fastin() {_ch=_f=0;}
}fin;
class fastout{
	private: int _num[32],_head;
	public: int SUF; template<typename _Tp> inline fastout& operator<<(_Tp _x){
		_Tp _k; if(_x==0) {putchar('0'),putchar(SUF);return *this;} if(_x<0) putchar('-'),_x=-_x;
		while(_x>0) _k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
		while(_head>0) putchar(_num[_head]),--_head; putchar(SUF); return *this;}
	fastout() {_head=0,SUF=' ';}
}fout;
// ----------------------------
using namespace std;

signed main()
{
	string myFname="tmp\\my.out",ansFname="tmp\\ans.out";
	int comp=0;
	//--------------------------
	
	string tmp="fc /w "+myFname+" "+ansFname;
	comp=system(tmp.c_str());
	
	//--------------------------
	return comp;
}
// ----------------------------
// by imzzy