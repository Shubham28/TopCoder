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

class MirrorPath {
public:
	vector <string> path(vector <string>);
	int R,C;
	int open[2][2];
	VS orig,ans;

	void trav(int psr,int psc,int dr,int dc) {
		char prs=orig[psr][psc];
		int nwr=psr+dr,nwc=psc+dc;

		if(prs=='.'){
			if(ans[psr][psc]=='|' || ans[psr][psc]=='-')
				ans[psr][psc]='+';
			else
				ans[psr][psc]=(abs(dr)==1)?'|':'-';

			if(nwr<0 || nwr==R || nwc<0 || nwc==C)		return;
			trav(nwr,nwc,dr,dc);
		} else if(prs=='/'){
			ans[psr][psc]='/';

			if(dc==1)	dr=-1,dc=0;
			else if(dc==-1)		dr=1,dc=0;
			else if(dr==1)		dr=0,dc=-1;
			else		dr=0,dc=1;

			nwr=psr+dr,nwc=psc+dc;
			trav(nwr,nwc,dr,dc);
		} else if(prs=='`'){
			ans[psr][psc]='`';

			if(dc==1)	dr=1,dc=0;
			else if(dc==-1)		dr=-1,dc=0;
			else if(dr==1)		dr=0,dc=1;
			else		dr=0,dc=-1;

			nwr=psr+dr,nwc=psc+dc;
			trav(nwr,nwc,dr,dc);
		}
		return;
	}
};

vector <string> MirrorPath::path(vector <string> grd) {
	R=SZ(grd),C=SZ(grd[0]);
	ans=orig=grd;
	bool fir=0;

	FOR(rw,0,R)		FOR(cl,0,C)
		if(grd[rw][cl]=='.' && (rw==0 || rw==R-1 || cl==0 || cl==C-1))
			open[fir][0]=rw,open[fir][1]=cl,fir=!fir;

	int dr,dc;
	if(open[0][0]==0)	dr=1,dc=0;
	else if(open[0][0]==R-1)	dr=-1,dc=0;
	else if(open[0][1]==0)		dr=0,dc=1;
	else if(open[0][1]==C-1)	dr=0,dc=-1;

	trav(open[0][0],open[0][1],dr,dc);

	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	MirrorPath *obj;
	vector <string> answer;
	obj = new MirrorPath();
	clock_t startTime = clock();
	answer = obj->path(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
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
	
	{
	// ----- test 0 -----
	string t0[] = {"#.#","#.#","#.#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"#|#","#|#","#|#"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"############","#######/....","######//####","#####//#####","####//######","..../#######","############"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"############","#######/----","######//####","#####//#####","####//######","----/#######","############"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"#######","##/..`#","##.##.#","##.##.#","...../#","##.####","##.####"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"#######","##/--`#","##|##|#","##|##|#","--+--/#","##|####","##|####"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"###########.#","#/........./.","#.#########.#","#`........./#","#############"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"###########|#","#/---------/-","#|#########|#","#`---------/#","#############"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"########.##","#./......`#","#../.`....#","#.`...../.#","#....`.../#","###.#######"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"########|##","#./-----+`#","#.|/-`..||#","#.`+-+--/|#","#..|.`---/#","###|#######"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"##.########","#.........#","..`.`.....#","#..`......#","#.`.`.`...#","#....`....#","#...`.`.`.#","#.........#","#.....`./.#","#.........#","###########"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"##|########","#.|.......#","--`-`.....#","#.|`|.....#","#.`-`-`...#","#...|`|...#","#...`-`-`.#","#.....|.|.#","#.....`-/.#","#.........#","###########"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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