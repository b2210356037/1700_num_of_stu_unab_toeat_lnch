#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0;
        int one = 0;

        for(auto& i: students){
            if(i == 0) zero++;
            else one++;
        }

        for(auto& sandwich: sandwiches){
            if(sandwich == 0 && zero == 0) return one;
            else if(sandwich == 0 && zero > 0) zero--;
            else{
                if(one == 0) return zero;
                one--;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> students{1,1,1,0,0,1};
    vector<int> sandwiches{1,0,0,0,1,1};
    cout << s.countStudents(students, sandwiches);

    return 0;
}
