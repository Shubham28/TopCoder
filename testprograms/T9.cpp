#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <bitset>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

class T9 {
public:
	string message(vector <string>, vector <string>, vector <string>);
};

string T9::message(vector <string> part, vector <string> dict, vector <string> keystr) {
	string inp="";
	FOR(c,0,keystr.size())
		inp+=keystr[c];

	SORT(dict);
	VS conv;

	FOR(c,0,dict.size()){
		string tmp="";
		FOR(pos,0,dict[c].size()){
			FOR(s,0,part.size())
				if( find(part[s].begin(),part[s].end(),dict[c][pos])!=part[s].end() ){
					tmp+=char(49+s);
					break;
				}
		}
		PB(conv,tmp);
	}
	inp+="0";

	string wrd="",ret="";
	int cnt=0;
	FOR(pos,0,inp.size()){

		if(inp[pos]=='0'){
			if(wrd=="")
				ret+=" ";
			else {
				string tmp;
				for(int p=0,tim=0;p<conv.size() && tim<=cnt;p++)
					if(conv[p]==wrd)
						tmp=dict[p],++tim;

				ret+=(tmp+" "),cnt=0,wrd="";
			}
		} else if(inp[pos]=='#')
			++cnt;
		else if(inp[pos]=='*')
			cnt+=5;
		else 
			PB(wrd,inp[pos]);
	}
	ret.erase(ret.size()-1,1);
	return ret;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, bool hasAnswer, string p3) {
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
	cout << "}";
	cout << "]" << endl;
	T9 *obj;
	string answer;
	obj = new T9();
	clock_t startTime = clock();
	answer = obj->message(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	string p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"bad"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"2230223"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "bad bad";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"the","tie"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0843#000843#000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = " tie   tie   ";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"bad","ace","aad","aae","aaf","acf","acd","the","tie"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"223#02","23*#00843#0"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "aae bad  tie ";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"the","tie","bad","ace","aad","aae","aaf","acf","acd"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"84300223#02","23#*"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "the  aae bad";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"bad","ace","aad","aae","tie","aaf","acf","acd","the"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"223#02","23######"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "aae bad";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"","rq","lde","yoauz","cbfgn","tjkpx","wvs","ih","m"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"xktgmfmoqlmivm","hmthr","tpjgmnmaremiwm","tpjcmnmyrlmhvm","xkpnmgmzqdmhsm","wqopvvmiig","melbcbqeeg","jkxnmbmardmhwm","kpxnmcmyqlmism","wrztvsmhhf","srztssmiic","pxtgmfmyrdmhwm","vqoxswmiin","wryksvmihb","ptjfmbmoremhvm"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"00","7246779885##00000089682000007246779885##0000724677","9885#000089682000093355523350066659594239879###000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   ";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
