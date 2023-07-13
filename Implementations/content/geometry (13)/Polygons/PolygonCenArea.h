/**
 * Description: centroid (center of mass) of a polygon with 
 	* constant mass per unit area and SIGNED area
 * Time: O(N)
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: kattis polygonarea, VT HSPC 2018 Holiday Stars
 */

#include "../Primitives/Point.h"

pair<P,T> cenArea(const vP& v) { assert(sz(v) >= 3);
	P cen{}; T area{}; 
	F0R(i,sz(v)) {
		int j = (i+1)%sz(v); T a = cross(v[i],v[j]);
		cen += a*(v[i]+v[j]); area += a; }
	return {cen/area/(T)3,area/2}; // area is SIGNED
}