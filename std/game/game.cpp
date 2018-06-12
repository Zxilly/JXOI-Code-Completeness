#include <bits/stdc++.h>
using namespace std;
const int N=10000005;
const int P=1e9+7;
#define REP(i,x,y) for(int i=x;i<=y;i++)
typedef long long LL;

int Pow(int x,int y,int p){
	int an=1;
	for(;y;y>>=1,x=(LL)x*x%P)if(y&1) an=(LL)an*x%P;
	return an;
}

int l,r,fac[N],minp[N],vis[N],pr[N],ptot;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	scanf("%d%d",&l,&r);
	*fac=1;
	REP(i,1,r+1) fac[i]=(LL)fac[i-1]*i%P;
	int num=1,tot=r-l+1;
	if(l>1){
		num=0;
		REP(i,2,r){
			if(!vis[i]) minp[pr[++ptot]=i]=i;
			for(int j=1;j<=ptot&&1ll*i*pr[j]<=r;j++){
				vis[i*pr[j]]=1;
				minp[i*pr[j]]=pr[j];
				if(i%pr[j]==0) break;
			}
		}
		REP(i,l,r) if(i/minp[i]<l) num++;
	}
	int N1=fac[tot+1];
	printf("%lld\n",(N1-(LL)N1*Pow(num+1,P-2,P)%P+P)%P);
	return 0;
}
