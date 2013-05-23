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

class AlternatingLane {
public:
	double expectedBeauty(vector <int>, vector <int>);
	inline LL sumOver(LL st,LL end) {
		LL sb=st-1;
		return (LL)end*(LL)(end+1)/2-(LL)sb*(LL)(sb+1)/2;
	}
};

double AlternatingLane::expectedBeauty(vector <int> lo, vector <int> hi) {
	double ans=0;
	FOR(a,0,SZ(lo)-1){
		LL l=lo[a+1],r=hi[a+1];
		double val=0.0;
		EFOR(ht,lo[a],hi[a]){
			if(ht<=l)	val+=sumOver(l-ht,r-ht);
			else if(ht>=r)		val+=sumOver(ht-r,ht-l);
			else 	val+=sumOver(1,ht-l)+sumOver(1,r-ht);
		}
		val/=(LL)(r-l+1)*(LL)(hi[a]-lo[a]+1);
		ans+=val;
	}
	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	AlternatingLane *obj;
	double answer;
	obj = new AlternatingLane();
	clock_t startTime = clock();
	answer = obj->expectedBeauty(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	vector <int> p1;
	double p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,2,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,3,5,7,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,4,6,8,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 8.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {4,3,3,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,7,7,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6.171428571428572;
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
