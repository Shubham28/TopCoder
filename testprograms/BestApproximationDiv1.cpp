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

class BestApproximationDiv1 {
public:
	string findFraction(int, string);
};

string BestApproximationDiv1::findFraction(int maxDen, string number) {
	int cost=-1,bstnum,bstden;
	number+="*";

	EFOR(den,1,maxDen)
		FOR(num,0,den){
			double val=(num+0.)/(den+0.);
			val*=1000000;
			val=int(val+1e-9);
			val/=1000000;

			char tmp[25];
			sprintf(tmp,"%.6f",val);
			string mat(tmp);

			int pos=0;
			EFOR(chk,3,9)
				if(number.substr(0,chk)!=mat.substr(0,chk)){
					pos=chk-2;
					break;
				}

			if(pos>cost)
				cost=pos,bstnum=num,bstden=den;
		}

	char fin[25];
	sprintf(fin,"%d/%d has %d exact digits",bstnum,bstden,cost);

	string ans(fin);
	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	BestApproximationDiv1 *obj;
	string answer;
	obj = new BestApproximationDiv1();
	clock_t startTime = clock();
	answer = obj->findFraction(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	string p1;
	string p2;

	{
	// ----- test 0 -----
	p0 = 42;
	p1 = "0.141592";
	p2 = "1/7 has 3 exact digits";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = "0.133700";
	p2 = "0/1 has 1 exact digits";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 1000;
	p1 = "0.123456";
	p2 = "10/81 has 7 exact digits";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1000;
	p1 = "0.420000";
	p2 = "21/50 has 7 exact digits";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100;
	p1 = "0.909999";
	p2 = "10/11 has 4 exact digits";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 115;
	p1 = "0.141592";
	p2 = "16/113 has 7 exact digits";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
