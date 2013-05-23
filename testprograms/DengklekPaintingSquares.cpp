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

const int MOD=1000000007;

using namespace std;

class DengklekPaintingSquares {
public:
	int numSolutions(int, int);

	int R,C;

	/*	0: Above square not painted, no restriction
		1: Above square has even adjacent painted squares, don't paint current
		2: Above square has odd adjacent painted squares, paint current
	*/
	int comb[100][6570];

	int cntComb(int rw, int mask) {
		int now[8];
		for(int a=0,copy=mask;a<C;a++,copy/=3)
			now[a]=copy%3;

		if(rw==R){
			FOR(a,0,C)
				if(now[a]==2)
					return 0;
			return 1;
		}

		int &tmp=comb[rw][mask];
		if(tmp!=-1)
			return tmp;

		tmp=0;
		int nxt[8];
		FOR(chk,0,1<<C){
			bool use=1;
			FOR(c,0,C)
				if(( now[c]==1 && ((chk>>c)&1) ) || ( now[c]==2 && !((chk>>c)&1) )){
					use=0;
					break;
				}

			if(!use)
				continue;

			FOR(cl,0,C){
				if((chk>>cl)&1){
					int cnt=(now[cl]==2);
					cnt+=(cl>=1 && ( (chk>>(cl-1))&1 ));
					cnt+=(cl+1<C && ( (chk>>(cl+1))&1 ));

					nxt[cl]=(cnt&1)+1;
				} else
					nxt[cl]=0;
			}
			int fin=0;
			FOR(a,0,C)
				fin=fin*3+nxt[a];

			tmp+=cntComb(rw+1,fin);
			tmp%=MOD;
		}
		return tmp;
	}
};

int DengklekPaintingSquares::numSolutions(int N, int M) {
	R=N,C=M;
	MEM(comb,-1);

	return cntComb(0,0);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	DengklekPaintingSquares *obj;
	int answer;
	obj = new DengklekPaintingSquares();
	clock_t startTime = clock();
	answer = obj->numSolutions(p0, p1);
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
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	p2 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 3;
	p2 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 47;
	p1 = 7;
	p2 = 944149920;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
