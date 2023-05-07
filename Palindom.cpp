#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    bool dp[n][n] = {};
    int start = 0, maxlen = 1;

   
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

   
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxlen = 2;
        }
    }

 
    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;

            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;

                if (k > maxlen) {
                    start = i;
                    maxlen = k;
                }
            }
        }
    }

    return s.substr(start, maxlen);
}

int main() {
    string s ;
    cout<<" podaj slowo ";
    cin>>s;
    string longest_palindrome = longestPalindrome(s);
    cout << "Najdluzszy palindrom w slowie " << s << " to " << longest_palindrome << endl;
    return 0;
}
