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

class InternetSecurity {
public:
	vector <string> determineWebsite(vector <string>, vector <string>, vector <string>, int);
};

vector <string> InternetSecurity::determineWebsite(vector <string> adr, vector <string> key, vector <string> danger, int th) {
	int N=SZ(adr);

	set<string>dan;
	dan.insert(ALL(danger));
	VB done(N,false);
	VS ret;

	vector< VS >words(N);
	FOR(brk,0,N){
		stringstream tmp;
		string wrd;
		tmp<<(key[brk]+" ");
		while(tmp>>wrd)
			PB(words[brk],wrd);
	}

	FOR(tim,0,2*N)
		FOR(chk,0,N){

			if(done[chk]==false){
				int cnt=0;

				FOR(tot,0,SZ(words[chk]))
					if(find(ALL(dan),words[chk][tot])!=dan.end())
						++cnt;
				if(cnt>=th){
					done[chk]=true;
					dan.insert(ALL(words[chk]));
				}
			}
		}

	FOR(r,0,N)
		if(done[r])
			PB(ret,adr[r]);

	return ret;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, int p3, bool hasAnswer, vector <string> p4) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}" << "," << p3;
	cout << "]" << endl;
	InternetSecurity *obj;
	vector <string> answer;
	obj = new InternetSecurity();
	clock_t startTime = clock();
	answer = obj->determineWebsite(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p4.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p4[i] << "\"";
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
		if (answer.size() != p4.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p4[i]) {
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
	vector <string> p2;
	int p3;
	vector <string> p4;
	
	{
	// ----- test 0 -----
	string t0[] = {"www.topcoder.com","www.sindicate_of_evil.com","www.happy_citizens.com"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"hack encryption decryption internet algorithm","signal interference evil snake poison algorithm","flower baloon topcoder blue sky sea"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"hack","encryption","decryption","interference","signal","internet"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 3;
	string t4[] = {"www.topcoder.com","www.sindicate_of_evil.com"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"brokenlink","flowerpower.net","purchasedomain.com"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"broken","rose tulips","cheap free domain biggest greatest"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"biggest","enemy","hideout"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	p4.clear();
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"a..a.ab.","...aa.b"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"a bc def","def ghij klmno"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"a","b","c","d","e"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	string t4[] = {"a..a.ab.","...aa.b"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"www.tsa.gov"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"information assurance signal intelligence research"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"signal","assurance","penguin"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	string t4[] = {"www.tsa.gov"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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
