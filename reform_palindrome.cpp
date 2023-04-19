/*
amadm
  1`    
*/ 
#include <iostream>
#include <unordered_map>
using namespace std;

string palindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    int num_odd = 0;
    for (auto it : freq) {
        if (it.second % 2 != 0) {
            num_odd++;
        }
    }
    if (num_odd > 1) {
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    string s;
    cin>>s;
    cout << palindrome(s) << endl;  
    return 0;
}
