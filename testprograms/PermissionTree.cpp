#include <vector>
#include <queue>
#include <map>
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

class PermissionTree {
public:
	vector <int> findHome(vector <string>, vector <string>);
};

vector <int> PermissionTree::findHome(vector <string> fol, vector <string> usr) {
	int N=SZ(fol);
	map< string,VI >accs;
	int prnt[51],dep[51];

	string tmp;
	FOR(all,0,N){
		replace(ALL(fol[all]),',',' ');
		stringstream sstr;
		sstr<<fol[all];

		sstr>>prnt[all];
		if(all==0)		prnt[0]=-1,dep[0]=0;

		set<string>nms;
		while(sstr>>tmp)	nms.insert(tmp);

		for(set<string>::iterator it=nms.begin();it!=nms.end();it++)	PB(accs[*it],all);
	}

	queue<int>levl;
	levl.push(0);

	while(!levl.empty()){
		int now=levl.front();
		levl.pop();

		FOR(chk,0,N)
			if(prnt[chk]==now){
				dep[chk]=dep[now]+1;
				levl.push(chk);
			}
	}

	VI ret(SZ(usr),-1);
	FOR(chk,0,SZ(usr)){
		string name=usr[chk];

		if(accs.find(name)==accs.end())
			continue;
		else {
			priority_queue< VI >brd;
			bool vist[N+1];
			MEM(vist,0);

			VI tmp(2);
			FOR(dn,0,SZ(accs[name])){
				tmp[0]=dep[accs[name][dn]],tmp[1]=accs[name][dn];
				brd.push(tmp);
				vist[accs[name][dn]]=1;
			}

			while(SZ(brd)>1){
				int now=brd.top()[1];
				brd.pop();

				if(prnt[now]!=-1 && !vist[prnt[now]]){
					tmp[0]=dep[prnt[now]],tmp[1]=prnt[now];
					brd.push(tmp);
					vist[prnt[now]]=1;
				}
			}
			ret[chk]=brd.top()[1];
		}
	}
	return ret;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, vector <int> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PermissionTree *obj;
	vector <int> answer;
	obj = new PermissionTree();
	clock_t startTime = clock();
	answer = obj->findHome(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p2[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	
	vector <string> p0;
	vector <string> p1;
	vector <int> p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"0 Admin","0 Joe,Phil","0 Joe"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Admin","Joe","Phil"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0 Admin"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Peter","Paul","Mary"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {-1,-1,-1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0 Admin","2 John","0 Peter,John","0 Tim","1 John"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"John"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0 Admin","0 Jeff","1 Mark,Tim","1 Tim,Jeff","0 Dan","4 Ed","4 Tom","4 Kyle,Ed","0 Ben","8 Rich","8 Sam","8 Tim"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Jeff","Ed","Tim","Steve"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,4,0,-1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"0 Admin","0 Bob,Joe,Bob","0 Joe"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Joe","Bob"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
