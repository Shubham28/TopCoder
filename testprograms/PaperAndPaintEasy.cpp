#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PaperAndPaintEasy {
public:
	long long computeArea(int, int, int, int, int, int, int, int);
};

long long PaperAndPaintEasy::computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2) {
	long long int cropx,cropy,area,sub;

	if( xfold<=(width/2) )
		cropx= (width-xfold);
	else{
		cropx=xfold;
		xfold=(width-xfold);
	}		
	cropy= (height/cnt+1);
							cout<<cropx<<"\t"<<cropy<<endl;
	area=(x2-x1)*(y2-y1);		
	cout<<"area 1"<<area<<endl;
	if( (xfold-x2)<=0 )
		sub=(xfold-x1)*(y2-y1);
	else if( (xfold-x2)>0 )
		sub=(x2-x1)*(y2-y1);
							cout<<"sub"<<sub<<endl;
	area=area+sub;		cout<<"tot area "<<area<<endl;
	long long int total;
	total=(height/cnt+1);
	total=total*width;		cout<<"total "<<total;
	return (  (total-area)*(cnt+1) );
}


//Powered by [KawigiEdit] 2.0!
