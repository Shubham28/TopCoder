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

bool dbg=0;

class MakeSquare {
public:
	int minChanges(string);
	int N,cost[55][55];
	string S,fir,sec;

	int convOpt() {
		int N1=SZ(fir),N2=SZ(sec);
		EFOR(r,0,N1+1)	EFOR(c,0,N2+1)	cost[r][c]=100;

		EFOR(p1,0,N1)	cost[p1][0]=p1;
		EFOR(p2,0,N2)	cost[0][p2]=p2;

		EFOR(p1,1,N1)	EFOR(p2,1,N2){
			int &tmp=cost[p1][p2];
			if(fir[p1-1]==sec[p2-1])
				tmp<?=cost[p1-1][p2-1];
			else {
				tmp<?=1+cost[p1][p2-1];
				tmp<?=1+cost[p1-1][p2];
				tmp<?=1+cost[p1-1][p2-1];
			}
		}
		return cost[N1][N2];
	}
};

int MakeSquare::minChanges(string S_) {
	S=S_;
	N=SZ(S);

	int ans=100;
	EFOR(i,1,N){
		fir=S.substr(0,i),sec=S.substr(i,N-i);
		int tmp=convOpt();
		ans<?=tmp;
	}
	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	MakeSquare *obj;
	int answer;
	obj = new MakeSquare();
	clock_t startTime = clock();
	answer = obj->minChanges(p0);
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
	
	string p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "abcdabgcd";
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "abcdeabce";
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "abcdeabxde";
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "aabcaabc";
	p1 = 0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "aaaaabaaaaabaaaaa";
	p1 = 2;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "qqqqqqqqqqqqqqqqqqqqqqqqwwwwwwweeeeeewwwwwwweeeeee";
	p1 = 24;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
