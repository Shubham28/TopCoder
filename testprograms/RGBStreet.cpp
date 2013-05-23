#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <bitset>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

class RGBStreet {
public:
	int estimateCost(vector <string>);
};

int RGBStreet::estimateCost(vector <string> hous) {

	vector< VI >costs(3,VI(hous.size()+1,0));

	FOR(r,0,hous.size()){
		int R,G,B;
		string conv="";
		stringstream num;
		num<<(hous[r]+" ");
		num>>R;
		num>>G;
		num>>B;

		costs[0][r+1]=R+min(costs[1][r],costs[2][r]);
		costs[1][r+1]=G+min(costs[0][r],costs[2][r]);
		costs[2][r+1]=B+min(costs[0][r],costs[1][r]);
	}

	int ret=9999999;
	FOR(r,0,3)
		ret=min(ret,costs[r][hous.size()]);
	return ret;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
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
	RGBStreet *obj;
	int answer;
	obj = new RGBStreet();
	clock_t startTime = clock();
	answer = obj->estimateCost(p0);
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
	string t0[] = {"1 100 100","100 1 100","100 100 1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"1 100 100","100 100 100","1 100 100"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 102;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"26 40 83","49 60 57","13 89 99"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 96;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"30 19 5","64 77 64","15 19 97","4 71 57","90 86 84","93 32 91"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 208;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"71 39 44","32 83 55","51 37 63","89 29 100","83 58 11","65 13 15","47 25 29","60 66 19"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 253;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
