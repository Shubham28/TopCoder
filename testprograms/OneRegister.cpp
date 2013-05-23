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

class OneRegister {
public:
	string getProgram(int, int);
};

string OneRegister::getProgram(int s, int t) {
	if(s==t)
		return "";
	else if(t==1)
		return "/";

	queue<int>que;
	map<int,char>par;

	que.push(s);
	par[s]='3';

	if(par.find(1)==par.end()){
		que.push(1);
		par[1]='2';
	}
	if(par.find(s+s)==par.end() && s+s<=t){
		que.push(s+s);
		par[s+s]='1';
	}
	if(par.find(s*s)==par.end() && s*s<=t){
		que.push(s*s);
		par[s*s]='0';
	}

	while(!que.empty()){
		LL tp=que.front();
		que.pop();
		if(tp==t)
			break;

		if(par.find(tp*tp)==par.end() && tp*tp<=t){
			que.push(tp*tp);
			par[tp*tp]='0';
		}
		if(par.find(tp+tp)==par.end() && tp+tp<=t){
			que.push(tp+tp);
			par[tp+tp]='1';
		}
	}
	if(par.find(t)==par.end())
		return ":-(";

	int pres=t,len=0;
	char ans[200];

	while(par[pres]!='2' && par[pres]!='3'){
		if(par[pres]=='0')
			ans[len++]='*',pres=int(sqrt(pres)+1e-7);
		else if(par[pres]=='1')
			ans[len++]='+',pres/=2;
	}

	if(par[pres]=='2')
		ans[len++]='/';

	reverse(ans,ans+len);
	ans[len]=0;
	string ret(ans);
	return ret;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	OneRegister *obj;
	string answer;
	obj = new OneRegister();
	clock_t startTime = clock();
	answer = obj->getProgram(p0, p1);
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
	int p1;
	string p2;

	{
	// ----- test 0 -----
	p0 = 7;
	p1 = 392;
	p2 = "+*+";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 7;
	p1 = 256;
	p2 = "/+***";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 256;
	p2 = "**";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	p1 = 7;
	p2 = "";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 7;
	p1 = 9;
	p2 = ":-(";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 10;
	p1 = 1;
	p2 = "/";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = 434;
	p1 = 134217728;
	p2 = "/+*+**+*+";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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