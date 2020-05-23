#include<bits/stdc++.h>
#define rgi register int
#define ll long long
class fastin{
	private: int _ch,_f;
	public: inline fastin& operator>>(char&c) {c=getchar(); return *this;}
		template<typename _Tp> inline fastin& operator>>(_Tp&_x){
		_x=0; while(!isdigit(_ch)) _f|=(_ch==45),_ch=getchar();
		while(isdigit(_ch)) _x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
		_f&&(_x=-_x,_f=0); return *this;}
	fastin() {_ch=_f=0;}
}fin;
class fastout{
#define endl '\n'
	private: int _num[32],_head;
	public: inline fastout& operator<<(char c) {putchar(c); return *this;}
		template<typename _Tp> inline fastout& operator<<(_Tp _x){
		_Tp _k; if(_x==0) {putchar('0'); return *this;} if(_x<0) putchar('-'),_x=-_x;
		while(_x>0) _k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
		while(_head>0) putchar(_num[_head]),--_head; return *this;}
	fastout() {_head=0;}
}fout;
// ----------------------------
// #define int ll
// using namespace std;
const int maxn=200004;
const int mod=998244353,inf=1000000007;


std::string s;
int a,b,c;
signed main()
{
	int t; fin>>t;
	while(t--)
	{
		std::cin>>s;
		a=b=c=-1;
		int ans=inf;
		for(rgi i=0;i<=s.length();++i)
		{
			if(s[i]=='1') a=std::max(a,i);
			if(s[i]=='2') b=std::max(b,i);
			if(s[i]=='3') c=std::max(c,i);
			if(~a&&~b&&~c) ans=std::min(ans,i-std::min(a,std::min(b,c))+1);
		}
		if(ans<inf) fout<<ans<<endl;
		else fout<<0<<endl;
	}
	return 0;
}
// ----------------------------
// by imzzy
