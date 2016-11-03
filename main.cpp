// Template

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
#include<unordered_set>
#include <cstdint>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define TESTING

#ifdef TESTING
#define DEBUG fprintf(stderr,"====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG 
#define VALUE(x)
#define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
	char x[100];
	sprintf(x, "%lld", a); string s = x;
	return s;
}

inline LL StringToInt(string a){
	char x[100]; LL res;
	strcpy(x, a.c_str()); sscanf(x, "%lld", &res);
	return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s", x); string s = x;
	return s;
}

inline string uppercase(string s){
	int n = SIZE(s);
	REP(i, n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s);
	REP(i, n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	return s;
}

inline void OPEN(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

// Template End

int a[1000000];
int b[1000000];
#define LEN 1000000
int threshold = 1;

int partition(int *a, int begin, int end)
{
	int rd = rand()%(end-begin);
	int x = a[begin+rd];
	a[begin+rd] = a[begin];
	int j = end - 1;
	int i = begin;
	while (i < j)
	{
		while (i < j && a[j] >= x)
			j--;
		a[i] = a[j];
		while (i < j && a[i] < x)
			i++;
		a[j] = a[i];
	}
	a[i] = x;
	return i;
}

void hybrid_sort(int *a, int begin, int end)
{
	if (end - begin > threshold)
	{
		int p = partition(a, begin, end);
		hybrid_sort(a, begin, p);
		hybrid_sort(a, p+1, end);
	}
}

void insert_sort(int *a, int begin, int end)
{
	for (int i = begin+1; i < end; ++i)
	{
		int x = a[i];
		int j = i - 1;
		bool f = false;
		while(j >= begin)
		{
			if (a[j] > x)
				a[j+1] = a[j];
			else
			{
				f = true;
				a[j+1] = x;
				break;
			}
			j--;
		}
		if (!f)
			a[0] = x;
	}
}

int small_test()
{
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl;
	insert_sort(a, 0, 10);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl;
}

void init_order()
{
	// Generate data in order
	for (int i = 0; i < LEN; ++i)
		a[i] = i+(rand()%4-2);
	memcpy(b, a, sizeof(int) * LEN);
}

void init_random()
{
	// Generate data randomly
	for (int i = 0; i < LEN; ++i)
		a[i] = rand()%123587;
	memcpy(b, a, sizeof(int) * LEN);
}

int main()
{
	clock_t start, end;

	for (int i = 50; i < LEN; i += 50)
	{

		init_order();

		threshold = i;
		cout << threshold << "\t";
		start = clock();
		hybrid_sort(a, 0, LEN);
		insert_sort(a, 0, LEN);
		end = clock();
		cout << (double)(end - start) / CLOCKS_PER_SEC << "\t";

		threshold = 1;
		start = clock();
		hybrid_sort(b, 0, LEN);
		end = clock();
		cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}
