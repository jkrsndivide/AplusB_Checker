#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <sstream>
#include <functional>
#include <iterator>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll inf = 0x7fffffff;
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const double eps = 1e-8;

vector <int> g[1510];

int f[1510][2];

bool vis[1510];

void dfs(int u)
{
    vis[u] = 1;
    f[u][1] = 1;
    f[u][0] = 0;
    for (int i = 0;i < g[u].size(); ++ i)
    {
        int v = g[u][i];
        if (vis[v])
            continue;
        dfs(v);
        f[u][1] += min(f[v][0],f[v][1]);
        f[u][0] += f[v][1];
    }
}

int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        int root = -1;
        memset(g,0,sizeof (g));
        memset(vis,0,sizeof (vis));
        for (int i = 0;i < n; ++ i)
        {
            int x;
            scanf("%d",&x);
            if (!i)
                root = x;
            int m;
            scanf(":(%d)",&m);
            while (m --)
            {
                int y;
                scanf ("%d",&y);
                g[x].push_back(y);
            }
        }
        dfs(root);
        printf("%d\n",min(f[root][1],f[root][0]));
    }
    return 0;
}
