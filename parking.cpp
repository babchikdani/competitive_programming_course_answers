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
    int test_cases, num_to_visit, leftmost, rightmost, tmp;
    
    cin >> test_cases;
    while(test_cases--){
        cin >> num_to_visit;
        set<int> stores; 
        while(num_to_visit--){
            cin >> tmp;
            stores.insert(tmp);
            
        }
        leftmost = *stores.begin();
        rightmost = *stores.rbegin(); 
        cout << 2*(rightmost - leftmost) << endl;
        stores.clear();
    }
}