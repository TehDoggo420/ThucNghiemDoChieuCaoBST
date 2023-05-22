#include<bits/stdc++.h>
using namespace std;
#define fu(a,b,c) for(long long a=b;a<=c;a++)
#define fd(a,b,c) for(long long a=b;a>=c;a--)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;
typedef long long ll;
ofstream fo ("DataSet9.OUT");
double A[1000010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fo<<1000000<<"\n";
    fu(i,1,1000000)
    {
        ll a=(mt()%1000000)+1;
        fo<<a<<" ";
    }
}
