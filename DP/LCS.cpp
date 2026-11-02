#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<vector<char>> b;

void LCS_len(const string &X, const string &Y){
    int m = X.length();
    int n = Y.length();
    c.assign(m + 1, vector<int>(n + 1, 0));
    b.assign(m + 1, vector<char>(n + 1, ' '));

    for(int i = 1; i<=m ; i++){
        for(int j = 1; j<=n ; j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'D';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }
}

string PRINT_LCS(const string& X, int i, int j) {
    if (i == 0 || j == 0) return "";
    if (b[i][j] == 'D') return PRINT_LCS(X, i - 1, j - 1) + X[i - 1];   // recurse first, then print
    if (b[i][j] == 'U') return PRINT_LCS(X, i - 1, j);
    return PRINT_LCS(X, i, j - 1);
}

int main() {
    string X, Y;
    cout << "Enter two strings:\n";
    getline(cin, X);
    getline(cin, Y);
    int m = X.size(), n = Y.size();
    LCS_len(X, Y);
    
    cout << "c table (arrows D/U/L):\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            string cell = to_string(c[i][j]);
            if (i && j) cell += b[i][j];
            cout << setw(4) << cell;
        }
        cout << "\n";
    }
    cout << "LCS length = " << c[m][n] << ", PRINT-LCS gives " << PRINT_LCS(X, m, n) << " (ties go up)\n";
    LCS_len(X, Y);
    cout << "with ties going left: " << PRINT_LCS(X, m, n) << "\n";
    
    
    return 0;
}
