#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string t, p;
        vector <int> ans;
        cin >> t >> p;
        int l_t = t.length(), l_p = p.length();
        for(int k=0; k<l_t-l_p+1; k++){
            bool flag = false;
            for (int j=0; j<l_p; j++)
                if (p[j] != '?' && p[j] != t[k + j]) {
                    flag = true;
                    break;
                }
            if (flag)
                continue;
            ans.push_back(k);
        }
        cout << ans.size() << endl;
        for (int i=0; i<ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
