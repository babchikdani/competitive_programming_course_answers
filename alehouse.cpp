#include <algorithm>  
#include <bitset> 
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <map>  
#include <queue>  
#include <set>  
#include <stack>  
#include <string> 
#include <vector>  
#include <numeric>

using namespace std;  
typedef long long ll;
typedef unsigned long long ull;  
typedef vector<int> vi;  
typedef pair<int, int> pii;
using namespace std;  


int main(){
    int n, k, ai, bi;
    cin >> n >> k;
    vi vec_a;
    vi vec_b;

    while(n--){
        cin >> ai >> bi;
        vec_a.push_back(ai);
        vec_b.push_back(bi);
    }
    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.begin(), vec_b.end());
    // stuck here, the official solution is unclear




}