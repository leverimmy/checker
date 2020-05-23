#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n;
char s[maxn];
int cnt[3];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		scanf("%s",s);
		n=strlen(s);
		memset(cnt,0,sizeof(cnt));
		int ans=n+1,cur=0;
		cnt[s[0]-'1']=1;
		for(int i=1;i<n;i++){
			cnt[s[i]-'1']++;
			while(cur<=i&&cnt[s[cur]-'1']>1&&cnt[0]&&cnt[1]&&cnt[2]) cnt[s[cur++]-'1']--;
			if(cnt[0]&&cnt[1]&&cnt[2]) ans=min(ans,i-cur+1);
		}
		printf("%d\n",ans<=n?ans:0);
	}
	return 0;
}
