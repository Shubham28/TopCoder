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

class GeometricProgressions {
public:
	int count(int, int, int, int, int, int);

	void addPrm(int N, set<int> &prms){
		if(N%2==0){
			while(N%2==0)
				N/=2;
			prms.insert(2);
		}

		int fct=3;
		while(N>1 && fct*fct<=N){
			if(N%fct==0){
				while(N%fct==0)
					N/=fct;
				prms.insert(fct);
			}
			fct+=2;
		}
		if(N!=1)
			prms.insert(N);

		return;
	}

	inline int calPwr(int num, int chk) {
		int cnt=0;
		while(num%chk==0)
			++cnt,num/=chk;

		return cnt;
	}
};

int GeometricProgressions::count(int b1, int r1, int pw1, int b2, int r2, int pw2) {
	if(b2==0 || r2<=1){
		swap(b1,b2),swap(r1,r2),swap(pw1,pw2);
	}

	if(b1==0 || r1<=1){
		set<LL>S;
		S.insert(b1);
		if(pw1>1)
			S.insert(b1*r1);

		LL cur=b2;
		FOR(all,0,pw2){
			S.insert(cur);
			cur*=r2;
			if(cur>500000000)
				return (pw2-all-1)+SZ(S);
		}
		return SZ(S);
	}

	set<int>fct;
	addPrm(b1,fct);		addPrm(r1,fct);
	addPrm(b2,fct);		addPrm(r2,fct);

	VI prFct[4];
	for(set<int>::iterator it=fct.begin();it!=fct.end();it++){
		PB(prFct[0],calPwr(b1,*it));		PB(prFct[1],calPwr(r1,*it));
		PB(prFct[2],calPwr(b2,*it));		PB(prFct[3],calPwr(r2,*it));
	}

	set< VI >ans;
	int L=SZ(fct);

	VI tmp=prFct[0];
	ans.insert(tmp);
	FOR(all,1,pw1){
		FOR(exp,0,L)
			tmp[exp]=prFct[0][exp]+prFct[1][exp]*all;
		ans.insert(tmp);
	}

	tmp=prFct[2];
	ans.insert(tmp);
	FOR(all,1,pw2){
		FOR(exp,0,L)
			tmp[exp]=prFct[2][exp]+prFct[3][exp]*all;
		ans.insert(tmp);
	}
	return SZ(ans);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	GeometricProgressions *obj;
	int answer;
	obj = new GeometricProgressions();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = 5;
	p3 = 6;
	p4 = 2;
	p5 = 5;
	p6 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 5;
	p3 = 2;
	p4 = 3;
	p5 = 5;
	p6 = 9;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 1;
	p2 = 1;
	p3 = 0;
	p4 = 0;
	p5 = 1;
	p6 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 4;
	p2 = 100500;
	p3 = 48;
	p4 = 1024;
	p5 = 1000;
	p6 = 100500;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 778;
	p1 = 27529;
	p2 = 9742;
	p3 = 8723;
	p4 = 12859;
	p5 = 20038;
	p6 = 29780;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
