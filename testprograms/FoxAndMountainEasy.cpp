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
#define LL long long

using namespace std;

class FoxAndMountainEasy {
public:
	string possible(int, int, int, string);

	string hist;
	int U,D;

	bool posb(int ini) {
		FOR(i,0,SZ(hist)){
			if(hist[i]=='U')	++ini;
			else				--ini;

			if(ini<0)
				return 0;
		}
		return 1;
	}
};

string FoxAndMountainEasy::possible(int n, int h0, int hn, string hist_) {
	hist=hist_;
	int dif=hn-h0;
	U=count(ALL(hist),'U');
	D=count(ALL(hist),'D');

	EFOR(up,0,n){
		int dwn=n-up;
		if(up-dwn==dif){
			if(U<=up && D<=dwn && posb(h0+up-U))
				return "YES";
		}
	}
	return "NO";
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, string p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << "\"" << p3 << "\"";
	cout << "]" << endl;
	FoxAndMountainEasy *obj;
	string answer;
	obj = new FoxAndMountainEasy();
	clock_t startTime = clock();
	answer = obj->possible(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	string p3;
	string p4;
	
	{
	// ----- test 0 -----
	p0 = 4;
	p1 = 0;
	p2 = 4;
	p3 = "UU";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 0;
	p2 = 4;
	p3 = "D";
	p4 = "NO";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 100000;
	p2 = 100000;
	p3 = "DDU";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4;
	p1 = 0;
	p2 = 0;
	p3 = "DDU";
	p4 = "NO";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20;
	p1 = 20;
	p2 = 20;
	p3 = "UDUDUDUDUD";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 20;
	p1 = 0;
	p2 = 0;
	p3 = "UUUUUUUUUU";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 20;
	p1 = 0;
	p2 = 0;
	p3 = "UUUUUUUUUUU";
	p4 = "NO";
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) && all_right;
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
