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

class RoadOrFlightHard {
public:
	long long minTime(int, int, int, int, int, int, int, int, int, int);
};

long long RoadOrFlightHard::minTime(int N, int rFr, int rPr, int rAd, int rMD, int fFr, int fPr, int fAd, int fMD, int K) {
	LL rdT[400001],flT[400001];
	LL opt[2][41][2];

	rdT[0]=rFr%rMD,flT[0]=fFr%fMD;

	FOR(gn,1,N)		rdT[gn]=((rdT[gn-1]*rPr)%rMD+rAd)%rMD;
	FOR(gn,1,N)		flT[gn]=((flT[gn-1]*fPr)%fMD+fAd)%fMD;

	MEM(opt[N&1],0);

	RFOR(city,N-1,0)		EFOR(fl,0,K)
		EFOR(air,0,1){
			LL &tmp=opt[city&1][fl][air];
			tmp=rdT[city]+opt[(city+1)&1][fl][0];

			if(air)
				tmp<?=flT[city]+opt[(city+1)&1][fl][1];
			else if(fl)
				tmp<?=flT[city]+opt[(city+1)&1][fl-1][1];
		}

	return opt[0][K][0];
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, bool hasAnswer, long long p10) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5 << "," << p6 << "," << p7 << "," << p8 << "," << p9;
	cout << "]" << endl;
	RoadOrFlightHard *obj;
	long long answer;
	obj = new RoadOrFlightHard();
	clock_t startTime = clock();
	answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p10 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p10;
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
	int p4;
	int p5;
	int p6;
	int p7;
	int p8;
	int p9;
	long long p10;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 14;
	p2 = 1;
	p3 = 2;
	p4 = 10;
	p5 = 18;
	p6 = 1;
	p7 = 10;
	p8 = 17;
	p9 = 1;
	p10 = 14ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 4;
	p2 = 1;
	p3 = 2;
	p4 = 10;
	p5 = 1;
	p6 = 1;
	p7 = 10;
	p8 = 17;
	p9 = 2;
	p10 = 11ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 4;
	p2 = 1;
	p3 = 2;
	p4 = 10;
	p5 = 1;
	p6 = 1;
	p7 = 6;
	p8 = 9;
	p9 = 1;
	p10 = 12ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 85739;
	p2 = 94847;
	p3 = 93893;
	p4 = 98392;
	p5 = 92840;
	p6 = 93802;
	p7 = 93830;
	p8 = 92790;
	p9 = 3;
	p10 = 122365ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 343997;
	p1 = 91758;
	p2 = 80747;
	p3 = 71460;
	p4 = 54597;
	p5 = 68741;
	p6 = 85914;
	p7 = 76851;
	p8 = 22543;
	p9 = 0;
	p10 = 9416678862ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 331999;
	p1 = 65645;
	p2 = 48613;
	p3 = 81333;
	p4 = 82122;
	p5 = 2374;
	p6 = 18997;
	p7 = 3468;
	p8 = 97383;
	p9 = 10;
	p10 = 13625973966ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 349373;
	p1 = 68003;
	p2 = 71076;
	p3 = 4870;
	p4 = 26479;
	p5 = 22019;
	p6 = 78832;
	p7 = 7988;
	p8 = 81972;
	p9 = 40;
	p10 = 4623064763ll;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
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
