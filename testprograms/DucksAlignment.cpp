#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SZ(A) int(A.size())
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define LL long long

using namespace std;

class DucksAlignment {
public:
	int minimumTime(vector <string>);

	int mnDist(int ar[], int L) {
		int ini=find(ar,ar+L,true)-ar;

		int val=2501;
		FOR(fx,ini,L){
			int tmp=0,pos=fx;

			FOR(a,0,L)
				if(ar[a])
					tmp+=abs(a-pos++);

			val<?=tmp;
		}
		return val;
	}
};

int DucksAlignment::minimumTime(vector <string> gr) {
	int R=SZ(gr),C=SZ(gr[0]);

	int rwD[50][50],clD[50][50];
	int dk=0;

	FOR(rw,0,R)		FOR(cl,0,C)
		if(gr[rw][cl]=='o'){
			FOR(ec,0,R)		rwD[dk][ec]=abs(ec-rw);
			FOR(ec,0,C)		clD[dk][ec]=abs(ec-cl);
			++dk;
		}

	int ret=2501;
	int X=-1,Y=-1;

	FOR(rw,0,R){
		int sum=0;
		FOR(a,0,dk)		sum+=rwD[a][rw];
		if(ret>sum)
			ret=sum,X=rw;
	}

	FOR(cl,0,C){
		int sum=0;
		FOR(a,0,dk)		sum+=clD[a][cl];
		if(ret>sum)
			ret=sum,Y=cl,X=-1;
	}

	int ar[51];
	MEM(ar,0);

	if(X!=-1){
		FOR(a,0,C){
			FOR(rw,0,R)
				ar[a]|=(gr[rw][a]=='o');
		}

		return (ret+mnDist(ar,C));
	} else {
		FOR(a,0,R)
			ar[a]=(find(ALL(gr[a]),'o')!=gr[a].end());

		return (ret+mnDist(ar,R));
	}
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	DucksAlignment *obj;
	int answer;
	obj = new DucksAlignment();
	clock_t startTime = clock();
	answer = obj->minimumTime(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {".o","o."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {".o...","..o..","....o"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"o..........","..o........",".......o...","...........","...........","...........","........o..","..........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 16;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".........","....o....","........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"...o..........................","............................o.",".o............................","............o.................",".................o............","......................o.......","......o.......................","....o.........................","...............o..............",".......................o......","...........................o..",".......o......................"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 99;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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