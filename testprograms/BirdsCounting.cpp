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

class BirdsCounting {
public:
	double computeProbability(int, int, int, int);
};

double BirdsCounting::computeProbability(int birds, int caught, int days, int marked) {
	double Pasc[21][21];
	memset(Pasc,0,sizeof(Pasc));

	Pasc[0][0]=1;
	EFOR(pos,1,20){
		Pasc[pos][0]=1;
		EFOR(fill,1,pos)
			Pasc[pos][fill]=Pasc[pos-1][fill]+Pasc[pos-1][fill-1];
	}

	vector< VD >prob(days+1,VD(birds+caught+1,0.0));
	prob[0][0]=1.0;

	FOR(pass,0,days)
		EFOR(prev,0,birds)
			EFOR(tod,0,caught)
				prob[pass+1][prev+tod]+=prob[pass][prev]*(Pasc[birds-prev][tod]*Pasc[prev][caught-tod]/Pasc[birds][caught]);

		return prob[days][marked];
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	BirdsCounting *obj;
	double answer;
	obj = new BirdsCounting();
	clock_t startTime = clock();
	answer = obj->computeProbability(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
	int p3;
	double p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 1;
	p2 = 2;
	p3 = 2;
	p4 = 0.6666666666666666;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 1;
	p2 = 5;
	p3 = 1;
	p4 = 0.012345679012345678;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 8;
	p1 = 3;
	p2 = 3;
	p3 = 7;
	p4 = 0.2582908163265306;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 3;
	p2 = 2;
	p3 = 4;
	p4 = 0.6;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20;
	p1 = 6;
	p2 = 5;
	p3 = 17;
	p4 = 0.30035494805367574;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
