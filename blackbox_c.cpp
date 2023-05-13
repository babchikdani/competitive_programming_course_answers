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


// find the i'th minimum. based on the the select problem in 234218 lectures.
int find_ith_minimum(int i, vector<int>& vec){
    if(vec.size()==1) return vec[0];    // edge case
    int tmp;
    /* choose a random pivot element: */
    int max = vec.size()-1;
    int min = 0;
    int range = max - min + 1;
    int q = min + (rand() % static_cast<int>(max - min + 1));
    //int q = rand() % range + min;   // random index in range 0-vector.size-1
    int pivot = vec[q];
    // 
    /* partition:
        Split the vector into two.
        The elements smaller than the pivot element go to the left side of the pivot.
        The elements bigger or equal than the pivot go to the right side of the pivot.
        The pivot stays.
     */

    vi smaller_than_pivot;
    vi bigger_equal_than_pivot;
    int j=0;
    for (; j < vec.size(); j++){ // skip the pivot element! 
        if(j==q) continue;
        if(vec[j] < pivot){
            smaller_than_pivot.push_back(vec[j]);
        } else {
            bigger_equal_than_pivot.push_back(vec[j]);
        }
    }
    /* build the new vector, kinda sorted (relatively to the pivot) */
    vec.clear();
    int num_of_lower_than_pivot = smaller_than_pivot.size();
    int num_of_greater_equal_than_pivot = bigger_equal_than_pivot.size();   // DOES NOT COUNT THE PIVOT!
    j=0;
    for(; j < num_of_lower_than_pivot; j++){
        vec.push_back(smaller_than_pivot[j]);
    }
    q=j+1;
    vec.push_back(pivot);
    for(j=0; j<num_of_greater_equal_than_pivot; j++){
        vec.push_back(bigger_equal_than_pivot[j]);
    }

    /* now we face the same given problem with a slight knowledge of our vector -> recursion! */
    if(q==i) return pivot;
    if(q>i) {
        vector<int> subvector = {vec.begin(), vec.end()-num_of_greater_equal_than_pivot-1};
        return find_ith_minimum(i, subvector);
    }
    else{   // q < i
        vector<int> subvector = {vec.begin()+num_of_lower_than_pivot+1, vec.end()};
        return find_ith_minimum(i-q ,subvector);
    }   
}

int main(){
    
    int M;                          // number of ADD(x) transactions. AKA total numbers in the given dataset. 
    int N;                          // number of GET transactions
    string blank_line;              // 
    vi num_vector;                  // the dataset
    vi request_with;                //! no idea how to descrie this one. 
    int tmp;      
    int i=1;                          // for keeping the "i-th minimum"
    cin >> M >> N;    
    //filling the database:
    while(M--){
        cin >> tmp;
        num_vector.push_back(tmp);
    }
    // number of elements in the database before insertion
    while (N--){
        cin >> tmp;
        request_with.push_back(tmp);
    }

    for(const auto& x: request_with){
        // maybe return the vector already (kinda) sorted?
        int exlude_last_n_elements = num_vector.size()-x;
        vector<int> subvector = vector<int>(num_vector.begin(), num_vector.end()-exlude_last_n_elements);

        int i_th_min = find_ith_minimum(i, subvector);
        cout << i_th_min << endl;
        ++i;
    }
    return 0;
}