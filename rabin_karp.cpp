#include <iostream>
#include <string>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern, int q)
{
    int n = text.length();
    int m = pattern.length();
    
    int p = 0; // hash value of pattern
    int t = 0; // hash value of text window
    int h = 1;

    // calculate h = pow(d, m-1) % q
    for(int i = 0; i < m-1; i++)
        h = (h * d) % q;

    // calculate initial hash values
    for(int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // slide pattern over text
    for(int i = 0; i <= n-m; i++)
    {
        // check hash match
        if(p == t)
        {
            bool match = true;
            for(int j = 0; j < m; j++)
            {
                if(text[i+j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            
            if(match)
                cout << "Pattern found at index " << i << endl;
        }

        // calculate next window hash
        if(i < n-m)
        {
            t = (d * (t - text[i] * h) + text[i+m]) % q;

            if(t < 0)
                t = t + q;
        }
    }
}

int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    
    rabinKarp(text, pattern, 101);
    
    return 0;
}
