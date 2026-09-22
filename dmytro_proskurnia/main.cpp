#include <iostream>
#include "fenwick.hpp"

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> A(n);
	for(auto &el:A) cin >> el;
	int q; cin >> q;
	Fenwick f(A);
	while(q--){
		int a; cin >> a;
		if(a == 1){
			int i, v; cin >> i >> v;
			f.update(i, v);
		} else {
			int i, j; cin >> i >> j;
			cout << f.sum(i, j) << "\n";
		}
	}

	return 0;
}

