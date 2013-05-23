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

class BoxUnion {
public:
	int area(vector <string>);
};

int BoxUnion::area(vector <string> rect) {
	int dimen[5][4];
	int N=SZ(rect);

	FOR(all,0,N)
		sscanf(rect[all].c_str(),"%d %d %d %d",&dimen[all][0],&dimen[all][2],&dimen[all][1],&dimen[all][3]);

	int ans=0;
	FOR(all,1,1<<N){
		int sign=-1;
		int ln1=-1,ln2=30000,br1=-1,br2=30000;

		FOR(mask,0,N)
			if(all&(1<<mask)){
				sign*=-1;
				ln1>?=dimen[mask][0];
				ln2<?=dimen[mask][1];
				br1>?=dimen[mask][2];
				br2<?=dimen[mask][3];
			}

		if(ln1<=ln2 && br1<=br2)	ans+=sign*(ln2-ln1)*(br2-br1);
	}
	return ans;
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
	BoxUnion *obj;
	int answer;
	obj = new BoxUnion();
	clock_t startTime = clock();
	answer = obj->area(p0);
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
	string t0[] = {"200 300 203 304"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0 0 10 10","20 20 30 30"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 200;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0 500 20000 501","500 0 501 20000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 39999;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"4 6 18 24","7 2 12 19","0 0 100 100"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10000;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"1 3 5 6","3 1 7 5","4 4 9 7"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 35;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"0 0 20000 20000","0 0 20000 20000","0 0 20000 20000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 400000000;
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