#define LSOne(S) ((S) & -(S))

#include <vector>

using namespace std;

class Fenwick{
private:
	vector<int> f;

public:
	Fenwick(vector<int>& A){
		f.assign(A.size()+1, 0);
		for(int i = 0; i < A.size(); i++){
			update(i+1, A[i]);
		}
	}

	void update(int i, int v){
		for(; i < f.size(); i += LSOne(i)){
			f[i] += v;
		}
	}

	long long sum(int i){
		long long sum = 0;
		for(; i; i -= LSOne(i)){
			sum += f[i];
		}
		return sum;
	}

	long long sum(int i, int j){
		return sum(j) - sum(i-1);
	}
};


