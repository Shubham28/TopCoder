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

class LoveCalculator {
public:
	string findBoy(string, vector <string>);
};

string LoveCalculator::findBoy(string girl, vector <string> boys) {
	SORT(boys);
	string bst;

	PB(bst,'Z'+1);
	int val=-1;

	FOR(i,0,SZ(boys)){
		int L=count(ALL(boys[i]),'L');
		L+=count(ALL(girl),'L');
		int O=count(ALL(boys[i]),'O');
		O+=count(ALL(girl),'O');
		int V=count(ALL(boys[i]),'V');
		V+=count(ALL(girl),'V');
		int E=count(ALL(boys[i]),'E');
		E+=count(ALL(girl),'E');

		int chk=((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;

		if(chk>val)
			val=chk,bst=boys[i];
	}
	return bst;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	LoveCalculator *obj;
	string answer;
	obj = new LoveCalculator();
	clock_t startTime = clock();
	answer = obj->findBoy(p0, p1);
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
	
	string p0;
	vector <string> p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "LOVE";
	string t1[] = {"JACOB","FRANK","DANO"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "FRANK";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "JANE";
	string t1[] = {"THOMAS","MICHAEL","INDY","LIU"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "INDY";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "LILLY";
	string t1[] = {"PIERRE"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "PIERRE";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "MERYLOV";
	string t1[] = {"JOHN","DAVE","STEVE","JOHN","DAVE"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "DAVE";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "LLOL";
	string t1[] = {"BVERON","CVERON","AVERON","DVERON"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "AVERON";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "VELYLEOCEVE";
	string t1[] = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "VLOLUVCBLLQVESWHEEKC";
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
