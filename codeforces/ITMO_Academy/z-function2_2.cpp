#include <iostream>
#include <string>
#include <vector>

using namespace std;

int backtrack(int x) {
    if (x % 2 == 1)
        return 0;
    if (x % 4 == 0)
        return 2 * backtrack(x / 2) + 1;
    return 1;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int k, j;
        cin >>k>>j;
        if (j == 0)
            cout << 0 <<endl;
        else
            cout << backtrack(j)<<endl;
    }
    return 0;
}
