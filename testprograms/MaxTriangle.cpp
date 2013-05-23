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
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define PII pair<int,int>

using namespace std;

class MaxTriangle {
public:
	double calculateArea(int, int);

	void calPosb(int lim, vector< PII > &ret) {
		for(int x=0;x*x<=lim;x++){
			int y=int(sqrt(lim-x*x)+1e-12);
	
			if(x*x+y*y==lim)
				PB(ret,PII(x,y));
		}
	}
};

double MaxTriangle::calculateArea(int A, int B) {
	vector< PII >psb[2];
	calPosb(A,psb[0]);
	calPosb(B,psb[1]);

	double ans=0;
	FOR(c1,0,SZ(psb[0]))
		FOR(c2,0,SZ(psb[1])){
			PII pt1=psb[0][c1],pt2=psb[1][c2];
			int x1=pt1.first,y1=pt1.second;
			int x2=pt2.first,y2=pt2.second;

			double area=.5*abs(x1*y2-x2*y1);
			area>?=.5*abs(x1*-y2-x2*y1);
			area=.5*abs(x1*y2+x2*y1);
			ans>?=area;
		}

	return (ans>1e-9)?ans:-1;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	MaxTriangle *obj;
	double answer;
	obj = new MaxTriangle();
	clock_t startTime = clock();
	answer = obj->calculateArea(p0, p1);
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
	
	int p0;
	int p1;
	double p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	p2 = 0.5;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 7;
	p2 = -1.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 41;
	p1 = 85;
	p2 = 29.5;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2000000000;
	p1 = 1;
	p2 = 22240.0 ;
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