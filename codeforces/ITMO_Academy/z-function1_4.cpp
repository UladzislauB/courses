#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s, t;
        cin >> s >> t;
        int l_s = s.length(), l_t = t.length();
        int long ans = 0;
        int temp = 1;
        while (l_s-temp+1>0 && temp<l_t){
            ans += l_s-temp+1;
            temp++;
        }
        vector <int> v;

        for (int k=0; k < l_s-l_t+1; k++){
            bool flag = false;
            for(int j=0; j<l_t; j++)
                if (t[j]!=s[k+j]) {
                    flag = true;
                    break;
                }
            if (flag)
                continue;
            v.push_back(k);
        }
        for(int k=0; k<int(v.size())-1; k++) {
            if (v[k]+l_t<l_s) {
                int l = v[k]+1, r = v[k+1]+l_t-1;
                for (int p=l_t; p<=r-l; p++)
                    ans += r-l-p+1;
            }
        }
        if (v.size()>0) {
            int last = v[v.size()-1];
            if (last + l_t<l_s) {
                int l = last+1, r = l_s;
                for (int p=l_t; p<=r-l; p++)
                        ans += r-l-p+1;
            }
            int first = v[0];
            if (first != 0) {
                int l = 0, r = first + l_t - 1;
                for (int p=l_t; p<=r-l; p++)
                        ans += r-l-p+1;
            }
        } else {
            int l = 0, r = l_s;
            for (int p=l_t; p<=r-l; p++)
                ans += r-l-p+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
