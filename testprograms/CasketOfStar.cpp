#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define VI vector<int>

using namespace std;

class CasketOfStar {
public:
	int maxEnergy(vector <int>);
	VI W;
	int L;
	int opt[51][51];

	int calMx(int fr,int to) {
		if(fr+1==to)
			return 0;
		if(fr+2==to)
			return W[fr]*W[to];

		int &tmp=opt[fr][to];
		if(tmp!=-1)
			return tmp;

		tmp=0;
		EFOR(use,fr+1,to-1)
			tmp=max(tmp,calMx(fr,use)+calMx(use,to));
		tmp+=W[fr]*W[to];
		return tmp;
	}
};

int CasketOfStar::maxEnergy(vector <int> wt) {
	W=wt;
	L=SZ(W);
	MEM(opt,-1);

	return calMx(0,L-1);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	CasketOfStar *obj;
	int answer;
	obj = new CasketOfStar();
	clock_t startTime = clock();
	answer = obj->maxEnergy(p0);
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
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {100,2,1,3,100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10400;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2,2,7,6,90,5,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1818;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {477,744,474,777,447,747,777,474};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2937051;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {46,652,399,765,364,879,593,653,237,709,760,430,516,992,66,496,30,67,872,491,716,749,937,158,297,507,596,901,913,100,502,941,916,653,884,117,922,564,210,989,988,56,637,638,848,709,296,786};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 31412481;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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