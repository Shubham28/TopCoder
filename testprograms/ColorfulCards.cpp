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

#define N 1050
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

unsigned int prime[N / 64];

void sieve() {
    memset(prime,-1,sizeof(prime));

   	unsigned int i;
    unsigned int sqrtN=(unsigned int)sqrt((double)N)+1;
   	for(i=3;i<sqrtN;i+=2) if(gP(i))
    {
        unsigned int i2=i+i;
   	    for(unsigned int j=i*i;j<N;j+=i2) rP(j);
    }
}

using namespace std;

class ColorfulCards {
public:
	vector <int> theCards(int, string);
	string col;
	int L,ln;

	void fillNm(VI &seq,int inc) {
		int st=(inc==1)?0:ln-1;
		int end=(inc==1)?ln:-1;

		int ptr=(inc==1)?1:L;

		for(;st!=end;st+=inc){
			bool prm=(col[st]=='R');

			for(;;ptr+=inc){
				bool chk=( (ptr==2) || (ptr!=1 && (ptr&1) && gP(ptr)) );

				if((chk && prm) || (!chk && !prm)){
					seq[st]=ptr;
					ptr+=inc;
					break;
				}
			}
		}
		return;
	}
};

vector <int> ColorfulCards::theCards(int L_, string colors) {
	col=colors,L=L_;
	ln=SZ(col);
	VI inc(ln),decr(ln);
	sieve();

	fillNm(inc,1);
	fillNm(decr,-1);

	VI ans(ln);
	FOR(a,0,ln)
		ans[a]=(inc[a]==decr[a])?inc[a]:-1;

	return ans;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, string p1, bool hasAnswer, vector <int> p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	ColorfulCards *obj;
	vector <int> answer;
	obj = new ColorfulCards();
	clock_t startTime = clock();
	answer = obj->theCards(p0, p1);
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
	
	int p0;
	string p1;
	vector <int> p2;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = "RRR";
	int t2[] = {2,3,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 7;
	p1 = "BBB";
	int t2[] = {1,4,6};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = "RBR";
	int t2[] = {-1,4,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 58;
	p1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
	int t2[] = {-1,-1,-1,-1,-1,-1,-1,-1,17,18,19,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,47,53};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 495;
	p1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
	int t2[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
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