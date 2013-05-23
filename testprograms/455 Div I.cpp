#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdio>
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

int main()
{
	VS grid(7);	//	grid[0]="00.000",grid[1]="00.000",grid[2]="0.00.0",grid[3]="000.00";
	grid[0]="0000000",grid[1]="0.....0",grid[2]="0.00000",grid[3]="0.0..00";
	grid[4]="0.00000",grid[5]="0.....0",grid[6]="0000000";	//	grid[0]="000",grid[1]="0.0",grid[2]="000";*/
	int maxim=0;

	RFOR(csize,grid.size(),3){
		RFOR(rsize,grid[csize-1].size(),3){
			
			EFOR(rpos,0,grid.size()-csize){
				EFOR(cpos,0,grid[rpos].size()-rsize){
					int ret=0;
//				cout<<" order "<<csize<<"x"<<rsize<<" "<<rpos<<","<<cpos<<"\n";
					bool ch=true;
					FOR(r,rpos,rpos+csize){	 //cout<<r<<","<<cpos<<"  ";
						if(grid[r][cpos]=='.'){
							ch=false;
							break;
						}		}	//	cout<<"\n";
					FOR(r,rpos,rpos+csize){	//cout<<r<<","<<cpos+rsize-1<<"  ";
						if(grid[r][cpos+rsize-1]=='.'){
							ch=false;
							break;
						}		}	//	cout<<"\n";		
					FOR(c,cpos,cpos+rsize){	//cout<<rpos<<","<<c<<"  ";
						if(grid[rpos][c]=='.'){
							ch=false;
							break;
						}		}	//	cout<<"\n";		
					FOR(c,cpos,cpos+rsize){	//cout<<rpos+csize-1<<","<<c<<"  ";
						if(grid[rpos+csize-1][c]=='.'){
							ch=false;
							break;
						}		}	//	cout<<"\n";		

					if(ch){		cout<<" csize rsize cpos rpos "<<csize<<"x"<<rsize<<" "<<cpos<<","<<rpos<<"\n";
						++ret;		}
				}
			}
		}
	}


	system("pause");
	return 0;
}
