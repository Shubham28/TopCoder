#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int MOD=1000000009;

class FoxStones {
public:
	int getCount(int, int, vector <int>, vector <int>);

	int R,C,T;
	VI mR,mC;

	inline bool FND(int x,int y) {
		FOR(a,0,T)
			if(mR[a]==x && mC[a]==y)
				return 1;
		return 0;
	}
};

int FoxStones::getCount(int N, int M, vector <int> sx, vector <int> sy) {
	C=N,R=M,mR=sy,mC=sx,T=SZ(mR);
	LL fact[40005];

	fact[0]=fact[1]=1;
	EFOR(c,2,40000)		fact[c]=(c*fact[c-1])%MOD;

	map< VI,int >conc;

	EFOR(rw,1,R)		EFOR(cl,1,C){
		if(FND(rw,cl))		continue;

		VI tmp(T);
		FOR(m,0,SZ(mR))
			tmp[m]=abs(mR[m]-rw)>?abs(mC[m]-cl);

		++conc[tmp];
	}

	LL ans=1;
	for(map< VI,int >::iterator it=conc.begin();it!=conc.end();it++){
		ans*=fact[(*it).second];
		ans%=MOD;
	}

	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	FoxStones *obj;
	int answer;
	obj = new FoxStones();
	clock_t startTime = clock();
	answer = obj->getCount(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	
	int p0;
	int p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 6;
	p1 = 1;
	int t2[] = {3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	int t2[] = {2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 3;
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,2,3};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 8;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 12;
	p1 = 34;
	int t2[] = {5,6,7,8,9,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {11,12,13,14,15,16};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 410850247;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 200;
	p1 = 200;
	int t2[] = {1	};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 92677741;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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