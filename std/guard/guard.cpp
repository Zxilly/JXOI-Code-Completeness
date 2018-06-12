#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define PER(i,x,y) for(int i=x;i>=y;i--)
#define FOR(i,x,y) for(int i=x;i<y;i++)
using namespace std;

int dp[5005][5005],n,h[5005];

long long cross(int u,int v,int w){
	return 1LL*(v-u)*(h[w]-h[u])-1LL*(w-u)*(h[v]-h[u]);
}

int getdp(int l,int r){
	if(l>r) return 0;
	return dp[l][r];
}

int inf=1e9;

int ans=0;

int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);

	scanf("%d",&n); 
	REP(i,1,n) scanf("%d",h+i);
	REP(r,1,n){
		int pre=r,cur=1;
		dp[r][r]=1;
		PER(l,r-1,1){
			if(pre==r||cross(l,pre,r)>0){
				cur+=min((0+getdp(l+1,pre-1)),0+getdp(l+1,pre));
				pre=l;
			}
			dp[l][r]=cur+min((0+getdp(l,pre-1)),0+getdp(l,pre));
		}
		REP(l,1,r-1) ans^=dp[l][r];
	}
	if(n&1) ans^=1;
	printf("%d\n",ans);
	return 0;
}
