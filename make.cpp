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
using namespace std;
inline long long random() {return (ll)rand()*(rand()+1LL);}
inline long long random(ll a,ll b) {if(a>b) std::swap(a,b); return random()%(b-a+1)+a;}

signed main()
{
	ifstream ifile("random_seed.txt");
	unsigned int tmp; ifile>>tmp;
	ifile.close();
	srand(tmp+time(NULL));
	//--------------------------
	
	int n=200000;
	fout<<1<<endl;
	for(rgi i=1;i<=n;++i)
	{
		int cnt=random(i,n),val=random(1,3);
		for(rgi j=i;j<=cnt;++j) fout<<val;
		i=cnt;
	}
	
	//--------------------------
	ofstream ofile("random_seed.txt");
	ofile<<rand();
	ofile.close();
	return 0;
}
// ----------------------------
// by imzzy