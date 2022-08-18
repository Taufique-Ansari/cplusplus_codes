#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // string s = "qwertyuiop";

    // transform(s.begin(), s.end(), s.begin(), ::toupper);

    // cout<<s<<endl;

    // string str = "753951";
    // sort(str.begin(), str.end(), greater<int>());

    // cout<<str<<endl;

    //FINDING GRESTEST NUMBER FROM THE STRING

    string s = "fjidkbihdjbhcbnqp";

    int freq[26];

    for(int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    char ans = 'a';
    int maxF = 0;

    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i + 'a';
        }
    }

    cout<<maxF<<" "<<ans<<endl;
}
