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
    int W, N;
    int sum=0;
    int wi, li;
    cin >> W;
    cin >> N;
    while(N--){
        cin >> wi >> li;
        sum += li*wi;
    }
    cout << sum/W;
}