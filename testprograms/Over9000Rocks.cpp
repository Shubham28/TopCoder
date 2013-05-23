#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <list>
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

class Over9000Rocks {
public:
	int countPossibilities(vector <int>, vector <int>);
	set< PII >rang;

	int sumRang() {
		set< PII >::iterator it,nxt;

		while(true){
			int ret=0;
			bool cnt=0;

			for(it=rang.begin();it!=rang.end();it++){
				nxt=it;		++nxt;

				if(nxt!=rang.end() && (*nxt).first<=(*it).second){
					PII add((*it).first,(*nxt).second);
					rang.erase(it);		rang.erase(nxt);
					rang.insert(add);

					cnt=1;
					break;
				} else
					ret+=(1+(*it).second-(*it).first);
			}

			if(!cnt)
				return ret;
		}
	}
};

int Over9000Rocks::countPossibilities(vector <int> lb, vector <int> ub) {
	int L=SZ(lb);

	FOR(a,1,(1<<L)){
		int lo=0,dif=0;
		FOR(msk,0,L)
			if((a>>msk)&1){
				lo+=lb[msk];
				dif+=(ub[msk]-lb[msk]);
			}

		int hi=lo+dif;
		if(hi>=9001){
			lo>?=9001;
			rang.insert(PII(lo,hi));
		}
	}
	return sumRang();

}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	Over9000Rocks *obj;
	int answer;
	obj = new Over9000Rocks();
	clock_t startTime = clock();
	answer = obj->countPossibilities(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {9000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9001};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {9000,1,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9000,2,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 15;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1001,2001,3001,3001};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1003,2003,3003,3003};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 9;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {9000,90000,1,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9000,90000,3,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 38;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {3,4,5,6,7,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {8990,1,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {8990,2,9};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {42,6335,1170,2479,8963,5706,5282,962,2996,4828,5392,3903,293,8422,1719};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {509,6835,1894,2837,9427,5851,6109,1453,3938,5264,5996,4056,675,9138,2614};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 57596;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	int t0[] = {9000,6666,3333,7876,7657,9000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9001,9000,9000,9000,9000,9000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 44004;
	all_right = KawigiEdit_RunTest(7, p0, p1, true, p2) && all_right;
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