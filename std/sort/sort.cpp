#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define cmp(T,x,y) [&](T x,T y)->int
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 300005;
const	int P = 998244353;
const	int inf = 1e9;
const	LL Inf = 1e18;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int cnt1,cnt2,cnt3,cnt4;
int n,m,l,r,a[N],ans,las,b[N],tot,top;
int fac[11000000],inv[11000000];
void Main(){
	scanf("%d%d%d%d",&n,&m,&l,&r);
	ans=fac[n+m];
	REP(i,1,n) scanf("%d",a+i);
	sort(a+1,a+n+1);
	las=1e9; top=0; tot=0;
	REP(i,1,n){
		if(l<=a[i]&&a[i]<=r){
			if(a[i]==las){
				b[top]++;
			}else{
				b[++top]=1;
				las=a[i];
			}
		}else{
			if(a[i]==las){
				++tot;
			}else{
				//printf("%d\n",tot);
				ans=(LL)ans*inv[tot]%P;
				tot=1;
				las=a[i];
			}
		}
	}
	//printf("%d\n",tot);
	ans=(LL)ans*inv[tot]%P;
	sort(b+1,b+top+1);
	if(!m){
		REP(i,1,top) ans=(LL)ans*inv[b[i]]%P;
		printf("%d\n",ans);
		++cnt4;
		return;
	}
	int cur=0,cursz=(r-l+1-top);
	if(!top){
		int cld=m/cursz;
		int rst=m%cursz;
		cur+=cld;
		ans=(LL)ans*Pow(inv[cur],cursz,P)%P;
		ans=(LL)ans*Pow(Pow(cur+1,P-2,P),rst,P)%P;				
		printf("%d\n",ans);
		++cnt3;
		return;		
	}
	REP(i,1,top){
		LL need=1LL*(b[i]-cur)*cursz;
		if(need<=m){
			m-=need;
			cursz++;
			cur=b[i];
			if(i==top){
				int cld=m/cursz;
				int rst=m%cursz;
				cur+=cld;
				ans=(LL)ans*Pow(inv[cur],cursz,P)%P;
				ans=(LL)ans*Pow(Pow(cur+1,P-2,P),rst,P)%P;		
				++cnt2;		
			}
		}else{
			int cld=m/cursz;
			int rst=m%cursz;
			cur+=cld;
			ans=(LL)ans*Pow(inv[cur],cursz,P)%P;
			ans=(LL)ans*Pow(Pow(cur+1,P-2,P),rst,P)%P;
			REP(x,i,top) ans=(LL)ans*inv[b[x]]%P;
			m=0;
			++cnt1;
			break;
		}
	}
	printf("%d\n",ans);
}

int main(){
#ifdef LOCAL
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);

	int T; scanf("%d",&T);
	*fac=*inv=1;
	REP(i,1,1e7+2e5+1) fac[i]=(LL)fac[i-1]*i%P;
	inv[int(1e7+2e5+1)]=Pow(fac[int(1e7+2e5+1)],P-2,P);
	PER(i,1e7+2e5,0) inv[i]=(LL)inv[i+1]*(i+1)%P;
	while(T--) Main();
	

	return 0;
}
