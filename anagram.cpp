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



void print_permutations(const char** arr, int arr_size){
    char new_arr[arr_size] = {};
    int i=0;
    for(int j=0; j<arr_size; j++){
        new_arr[j] = (*arr)[j];
    }
    sort(new_arr, new_arr+arr_size);
    do{
        for(int k=0; k<arr_size; k++){
            cout << new_arr[k];
        }
        i++;
        cout << endl;
    } while(next_permutation(new_arr, new_arr+arr_size));
    
}

int main(){
    int num;
    string num_string, str;
    vector<string> input_vector;
    const char* my_arr;
    cin >> num_string;
    num = stoi(num_string);
    while(num--){
        cin >> str;
        input_vector.push_back(str);
    }

    for(auto& x: input_vector){
        my_arr = x.c_str();
        print_permutations(&my_arr, x.length());
    }
}


