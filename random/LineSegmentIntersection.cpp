/*
 *	NOME: Line Segment Intersection
 *	LINK: https://open.kattis.com/problems/segmentintersection
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point{
	ll x, y;
	
	 bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

int sing(ll num){
	if(num < 0) return -1;
	else if(num == 0) return 0;
	else return 1;
}

ll collinear(Point p1, Point p2, Point p3){
	return sing((p1.y-p2.y)*(p3.x-p1.x) - (p1.x-p2.x)*(p3.y-p1.y));
}

bool quick_check(Point p1, Point p2, Point p3, Point p4){
	ll x1 = min(p1.x, p2.x), x2 = max(p1.x, p2.x);
	ll y1 = min(p1.y, p2.y), y2 = max(p1.y, p2.y);
	ll x3 = min(p3.x, p4.x), x4 = max(p3.x, p4.x);
	ll y3 = min(p3.y, p4.y), y4 = max(p3.y, p4.y);
	return x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1;
}

bool check(Point p1, Point p2, Point p3, Point p4){
	if(collinear(p1, p2, p3)*collinear(p1, p2, p4) > 0) return false;
	if(collinear(p3, p4, p1)*collinear(p3, p4, p2) > 0) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(2);
    
    int t; cin >> t;
    while(t--){
    	Point p1, p2, p3, p4; cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    	if(quick_check(p1, p2, p3, p4)) cout << "none\n";
    	else if(check(p1, p2, p3, p4)){
    		ll A1 = p2.y - p1.y;
            ll B1 = p1.x - p2.x;
            ll C1 = A1 * p1.x + B1 * p1.y;

            ll A2 = p4.y - p3.y;
            ll B2 = p3.x - p4.x;
            ll C2 = A2 * p3.x + B2 * p3.y;

            ll det = A1 * B2 - A2 * B1;
            if (det != 0) {
                double inter_x = (double)(C1 * B2 - C2 * B1) / det;
                double inter_y = (double)(A1 * C2 - A2 * C1) / det;
                cout << inter_x << " " << inter_y << "\n";
           	}else{
           		if (p2 < p1) swap(p1, p2);
                if (p4 < p3) swap(p3, p4);
                
                Point startInter = max(p1, p3);
                Point endInter = min(p2, p4);
                
                if (startInter == endInter) {
                    cout << (double)startInter.x << " " << (double)startInter.y << "\n";
                } else {
                    cout << (double)startInter.x << " " << (double)startInter.y << " "
                         << (double)endInter.x << " " << (double)endInter.y << "\n";
                }
           	}
            
    	}else cout << "none\n";
    }
	return 0;
}
