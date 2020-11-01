#include <iostream>
#include <vector>

using namespace std;

char getNewCharacter(int x) {
    if (x > 51)
        return '!';
    if (x>25)
        return (char)((int)'A' + x - 26);
    return (char)((int)'a'+x);
}

int main(){
    int k=0;
    cin>>k;
    for(int t=0; t<k; t++) {
        int n;
        cin >> n;
        vector<char> s(n,'*');
        s[0] = 'a';
        int newCharacter = 1;
        vector<int> z(n);
        for (int i=0; i<n; i++)
            cin>>z[i];
        if (z[0] != 0) {
            cout<<'!'<<endl;
            continue;
        }
        bool f = false;
        for(int i=1; i<n; i++) {
            if (z[i] == 0 && s[i] == '*') {
                char c = getNewCharacter(newCharacter++);
                if (c == '!') {
                    f = true;
                    break;
                } else s[i] = c;
            } else {
                if (z[i] > n - i) {
                    f = true;
                    break;
                }
                for(int j=0; j<z[i]; j++)
                    if (s[i+j] == '*')
                        s[i+j] = s[j];
                    else if(s[i+j] != s[j]) {
                        f = true;
                        break;
                    }
            }
        }

        if (!f) {
            for(int i=1; i<n; i++) {
                int j=0;
                while (i + j < n && s[i+j] == s[j])
                    j++;
                if (z[i] != j) {
                    f = true;
                    break;
                }
            }
        }

        if (f)
            cout<<'!';
        else
            for(int j=0; j<n; j++)
                cout<<s[j];
        cout<<endl;
    }
    return 0;
}
