#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;

class RepaintTheChessboard {
public:
	int minimumChanges(vector <string>);
};

int RepaintTheChessboard::minimumChanges(vector <string> board) {

	int count=board.size()*board.size();
	
	for(int r=0;r<=(board.size()-8);r++)
		for(int c=0;c<=(board[r].size()-8);c++){
			
			int black=0,white=0;
			for(int row=0;row<8;row++)
				for(int col=0;col<8;col++){
				
					if( (row+col)%2==0 && board[row+r][col+c] == 'B' )
						++white;
					if( (row+col)%2==0 && board[row+r][col+c] == 'W' )
						++black;

					if( (row+col)%2==1 && board[row+r][c+col] == 'W' )
						++white;
					if( (row+col)%2==1 && board[row+r][col+c] == 'B' )
						++black;
				}

			int minim=min(black,white);
			count=min(count,minim);
		}

	return count;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	RepaintTheChessboard *obj;
	int answer;
	obj = new RepaintTheChessboard();
	clock_t startTime = clock();
	answer = obj->minimumChanges(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBBBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBB","BBBBBBBBBBBBBBBBBBBBBBW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 31;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"BBBBBBBBBB","BBWBWBWBWB","BWBWBWBWBB","BBWBWBWBWB","BWBWBWBWBB","BBWBWBWBWB","BWBWBWBWBB","BBWBWBWBWB","BWBWBWBWBB","BBBBBBBBBB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBBBWBW","WBWBWBWB","BWBWBWBW","WBWBWWWB","BWBWBWBW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"BWWBWWBWWBWW","BWWBWBBWWBWW","WBWWBWBBWWBW","BWWBWBBWWBWW","WBWWBWBBWWBW","BWWBWBBWWBWW","WBWWBWBBWWBW","BWWBWBWWWBWW","WBWWBWBBWWBW","BWWBWBBWWBWW","WBWWBWBBWWBW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15;
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
//Powered by [KawigiEdit] 2.0!