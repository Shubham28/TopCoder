#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())

using namespace std;

class TheSimpleGame {
public:
	int count(int, vector <int>, vector <int>);
};

int TheSimpleGame::count(int n, vector <int> x, vector <int> y) {
	int L=SZ(x);

	int tot=0;
	FOR(i,0,L)
		tot+=((x[i]+y[i]-2)<?((x[i]+n-1-y[i])<?((y[i]+n-1-x[i])<?(2*n-x[i]-y[i]))));

	return tot;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheSimpleGame *obj;
	int answer;
	obj = new TheSimpleGame();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <int> p1;
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 4;
	int t1[] = {2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	int t1[] = {2,2,1,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,2,3,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 7;
	int t1[] = {7,1,7,7,1,7,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {7,1,1,1,1,7,7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
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