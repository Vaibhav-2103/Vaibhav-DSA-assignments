#include <iostream>
using namespace std;

bool isVowel(char c) {
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
        c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;
    return false;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;   // takes input without spaces

    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            s.erase(i,1); // remove vowel
            i--; // step back because string size reduced
        }
    }

    cout << "String without vowels: " << s << endl;
    return 0;
}
