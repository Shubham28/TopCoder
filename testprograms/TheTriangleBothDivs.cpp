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

class TheTriangleBothDivs {
public:
	string fix(string);
		
	long manip(string &word) {
	
		long tim=0;
		tim=tim+ ((int)word[0]-48)*600;
		tim=tim+ ((int)word[1]-48)*60;
		
		tim=tim+ ((int)word[3]-48)*10;
		tim=tim+ ((int)word[4]-48);
		
		if(word[9]=='-')
			tim=tim+ ((int)word[10]-48)*60;
		
		if(word[9]=='+')
			tim=tim- ((int)word[10]-48)*60;
			
		if(tim>=24*60)
			tim-=24*60;
		else if(tim<0)
			tim+=24*60;

		return tim;
	}
		
	void calc(string &ti,long &tim) {
	
		if(ti[0]=='?'){
			EFOR(i,0,2){
				string dup=ti;
				dup[0]=(char)(i+48);
				calc(dup,tim);
			}
		}
		
		if(ti[1]=='?'){
			EFOR(i,0,9){
				string dup=ti;
				dup[1]=(char)(i+48);
				calc(dup,tim);
			}
		}
		
		if(ti[9]=='?'){	
			string dup=ti;
			dup[9]='-';
			calc(dup,tim);
			dup[9]='+';
			calc(dup,tim);
		}
		
		if(ti[10]=='?'){
			EFOR(i,0,9){
				string dup=ti;
				dup[10]=(char)(i+48);
				calc(dup,tim);
			}
		}
		FOR(c,0,ti.size())
			if(ti[c]=='?')
				return;

		if( (ti[0]=='2' && (int)ti[1]>=52) || (ti[9]=='-' && ti[10]=='0') )
			return;
		else
			tim=min(tim,manip(ti));
			
		return;
	}

};

string TheTriangleBothDivs::fix(string ti) {

	if(ti[3]=='?')
		ti[3]='0';
	if(ti[4]=='?')
		ti[4]='0';

	long tim=99999;
	calc(ti,tim);
		
	int h=tim/60;
	char buff[10];
	sprintf(buff,"%d",h);
	string hr(buff);
	if(hr.size()==1)
		hr="0"+hr;

	int m=(tim-60*h);
	sprintf(buff,"%d",m);
	string min(buff);
	if(min.size()==1)
		min="0"+min;
	
	return hr+":"+min;
}

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!;
