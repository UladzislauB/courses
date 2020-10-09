#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        string s;
        cin >> s;
        int l = s.length();
        int max = 1;
        for (int k=1; k<=l; k++) {
            bool flag = false;
            for(int j=0; j< k/2; j++)
                if (s[j] != s[k-1-j]) {
                    flag = true;
                    break;
                }
            if (flag)
                continue;
            max = k;
        }
        cout << max << endl;
    }
    return 0;
}
