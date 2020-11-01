#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.length();
    vector<int> z(l);

    for (int i=1; i<l; i++)
        for (int j=i; j<l; j++)
        {
            if (s[j] != s[j-i])
                break;
            z[i]++;
        }

    for (int i=0; i<l; i++)
        cout<<z[i]<<' ';

    return 0;
}
