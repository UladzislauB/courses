#include <iostream>
#include <string>

using namespace std;

/*ifstream in("input.txt");
ofstream out("output.txt");*/

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        string s;
        int ans = 0;
        cin >> s;
        int l = s.length();
        for (int k=1; k<=l; k++) {
            for(int p=0; p<=l-k; p++) {
                bool f1 = true, f2 = true;
                for (int j=0; j< k; j++)
                    if (s[j] != s[p+j]) {
                        f1 = false;
                        break;
                    }
                for (int j=0; j<k; j++)
                    if (s[l-k+j] != s[p+j]) {
                        f2 = false;
                        break;
                    }
                if (f1^f2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
