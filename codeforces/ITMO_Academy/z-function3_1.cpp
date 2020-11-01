#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z(n);
    z[0] = 0;

    int l = 0, r = 0;

    for(int i=1; i<n; i++) {
        if (i < r) {
            z[i] = min(z[i-l], r - i);
        }
        while (z[i] + i < n && s[z[i]+i] == s[z[i]])
            z[i]++;
        if (i + z[i] >= r) {
            l = i;
            r = i + z[i];
        }
    }
    for(int i=0; i<n; i++)
        cout << z[i] << ' ';
    return 0;
}
