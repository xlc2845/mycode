#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxn 200010
#define INF 0x7fffffff
#define inf 10000000
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
using namespace std;

int n, m, maxv[maxn*2], a[maxn], p, v, ql, qr;

void build(int id, int L, int R)
{
    if(L == R) maxv[id] = a[L];
    else
    {
        int M = L + (R-L)/2;
        build(id*2, L, M);
        build(id*2+1, M+1, R);
        maxv[id] = maxv[id] + maxv[id*2] + maxv[id*2+1];
    }
}

void update(int id, int L, int R)
{
    if(L == R) maxv[id] += v;
    else
    {
        int M = L + (R-L)/2;
        if(p <= M) update(id*2, L, M);
        else update(id*2+1, M+1, R);
        maxv[id] += v;
    }
}

int query(int id, int L, int R)
{
    int M = L + (R-L)/2, ans = 0;
    if(ql <= L && qr >= R) return maxv[id];
    if(ql <= M) ans += query(id*2, L, M);
    if(qr > M) ans += query(id*2+1, M+1, R);
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int t, ca = 0;
    scanf("%d", &t);
    while(t --)
    {
        printf("Case %d:\n", ++ ca);
        scanf("%d", &n);
        memset(maxv, 0, sizeof(maxv));
        for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
        build(1, 1, n);
        char c[10];
        while(true)
        {
            scanf("%s", c);
            if(c[0] == 'Q')
            {
                scanf("%d%d", &ql, &qr);
                printf("%d\n", query(1, 1, n));
            }
            else if(c[0] == 'A')
            {
                scanf("%d%d", &p, &v);
                update(1, 1, n);
            }
            else if(c[0] == 'S')
            {
                scanf("%d%d", &p, &v);
                v = -v;
                update(1, 1, n);
            }
            else break;
        }
    }
    return 0;
}
