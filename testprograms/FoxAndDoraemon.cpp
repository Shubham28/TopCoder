#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define LL long long

using namespace std;

const int INF=10000000;

class FoxAndDoraemon {
public:
	int minTime(vector <int>, int);
	VI cst;
	int add,L;
	int opt[51][51];

	int calOpt(int foxes,int done) {
		if(done==L)
			return 0;
		if(foxes>L)
			return INF;

		int &tmp=opt[foxes][done];
		if(tmp!=-1)
			return tmp;

		if(foxes==L)
			return cst[done];

		tmp=cst[done]+calOpt(foxes,done+1);

	}
};

int FoxAndDoraemon::minTime(vector <int> workCost, int splitCost) {
	cst=workCost,add=splitCost;
	L=SZ(cst);
	SORT(cst);		reverse(ALL(cst));
	MEM(opt,-1);

	return calOpt(1,0);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	FoxAndDoraemon *obj;
	int answer;
	obj = new FoxAndDoraemon();
	clock_t startTime = clock();
	answer = obj->minTime(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000;
	p2 = 1002;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {3,6,9,12};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000;
	p2 = 2012;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1000,100,10,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 1001;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1712,1911,1703,1610,1697,1612};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 2012;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3000;
	p2 = 15000;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {58};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3600;
	p2 = 58;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {3041,3467,3334,3000,3169,3224,3478,3358,3462,3464,3205,3145,3281,3327,3461,3491,3495,3442,3327,3436,3391,3104,3402,3153,3292,3382,3421,3216,3218,3395,3447,3226,3271,3038,3369,3412,3167,3299,3035,3394,3203,3311,3322,3333,3173,3164,3141,3211,3253};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2789;
	all_right = KawigiEdit_RunTest(6, p0, p1, false, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
// Author: Shubham Gupta
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
