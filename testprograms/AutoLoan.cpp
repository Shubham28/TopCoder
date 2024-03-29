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
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

class AutoLoan {
public:
	double interestRate(double, double, int);

	int calIntr(double pr,double pay,int term,double perc) {

		EFOR(tim,1,term){
			pr*=(1+(perc/100.0));
			pr-=pay;
		}
		if(pr<0)
			return -1;
		else if(pr>0)
			return 1;
		else
			return 0;
	}
};

double AutoLoan::interestRate(double pr, double pay, int term) {
	double low=0.0,high=100.0;

	while((high-low)>1e-11){
		double md=low+(high-low)/2.0;
		int giv=calIntr(pr,pay,term,md/12.0);

		switch(giv){
			case -1:
				low=md;
				break;
			case 1:
				high=md;
				break;
			case 0:
				return md;
		}
	}
	return high;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, double p0, double p1, int p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	AutoLoan *obj;
	double answer;
	obj = new AutoLoan();
	clock_t startTime = clock();
	answer = obj->interestRate(p0, p1, p2);
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
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	
	double p0;
	double p1;
	int p2;
	double p3;
	
	{
	// ----- test 0 -----
	p0 = 6800;
	p1 = 100;
	p2 = 68;
	p3 = 1.3322616182218813E-13;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2000;
	p1 = 510;
	p2 = 4;
	p3 = 9.56205462458368;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 15000;
	p1 = 364;
	p2 = 48;
	p3 = 7.687856394581649;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
