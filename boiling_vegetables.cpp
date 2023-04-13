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



#define INIT_CUT_INTO 1

/// @brief compare function that compares the weight of the two given pieces
/// @param pair_a 
/// @param pair_b 
/// @return if pair_b is bigger than pair_a
bool comparePairIsBigger(const pair<double, int> pair_a, const pair<double, int> pair_b){
    return pair_a.first/pair_a.second < pair_b.first/pair_b.second;
}

int main(){
    int N, tmp_input;
    double ratio_T, current_ratio;               //! set precision to 2 digits after the floating point.
    vector<pair<double, int>> pieces;
    pair<double, int> intput_pair;          // pair is <piece original weight, num of cuts>
    int total_cuts = 0;

    // input
    cin >> ratio_T >> N;
    while(N--){
        cin >> tmp_input;
        intput_pair = make_pair((double)tmp_input, INIT_CUT_INTO); 
        pieces.push_back(intput_pair);
    }

    auto max_it = max_element(pieces.begin(), pieces.end(), comparePairIsBigger);
    auto min_it = min_element(pieces.begin(), pieces.end(), comparePairIsBigger);
    double max_val = max_it->first/max_it->second;      // get a chopped pieces weight
    double min_val = min_it->first/min_it->second;
    //int max_val_index = max_it - pieces.begin();        // the max_element index in the vector
    current_ratio = min_val/max_val;                    //! add an if for the first check maybe?
    while(current_ratio < ratio_T){
        max_it->second++;                               // add a cut to the biggest piece
        total_cuts++;
        max_it = max_element(pieces.begin(), pieces.end(), comparePairIsBigger);
        min_it = min_element(pieces.begin(), pieces.end(), comparePairIsBigger);
        max_val = max_it->first/max_it->second;      
        min_val = min_it->first/min_it->second;
        current_ratio = min_val/max_val;
    }
    cout << total_cuts << endl;
}