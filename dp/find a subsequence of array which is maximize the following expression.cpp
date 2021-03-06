//find a subsequence of an array which is maximize the following expression
//1*a1+2*a2+3*a3...... where array size<=1000
#include<bits/stdc++.h>
using namespace std;

#define XOX (-D XOX
typedef long long ll;
//debug for single line start from here
template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl //debug for single line ending here

//debug for multiple line start from here
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

#define M 1010
int dp[M][M];
int ar[M];
int INF=-1e9;

int f(int i,int cnt,int n)
{
    if(i==n) return 0;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    int r1=f(i+1,cnt,n);
//    debug(i,cnt,r1);
    int r2=f(i+1,cnt+1,n)+(ar[i]*cnt);
//    debug(i,cnt,r2);
    dp[i][cnt]=max(r1,r2);
    return dp[i][cnt];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    memset(dp,-1,sizeof dp);

    int r1=f(0,1,n);
    cout<<r1<<endl;
//    debug(r1);
    //int r2=f(0,1,1,n);
    //debug(r2);

}
