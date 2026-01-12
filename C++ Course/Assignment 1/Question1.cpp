#include <iostream>

using namespace std;

string concatenate(string s1, string s2)
{
    return s1 + s2;
}

int strlength(string s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}

string strToUpper(string s)
{
    int len = strlength(s);
    for(int i = 0 ; i < len; i++)
    {
        if(s[i] >= 'a')
            s[i] -= 'a' - 'A';
    }
    return s;
}

bool findSubstring(string sub, string s)
{
    int counter = 0;
    bool equal = false;
    return s.find(sub);
}

int main()
{
    string s1 = "Jana";
    string s2 = "Wael";
    cout << concatenate(s1,s2) << endl;
    cout << "Length of " << s1 << " = " << strlength(s1) << endl;
    cout << "Length of " << s2 << " = " << strlength(s2) << endl;
    cout << "Uppercase String of " << s1 << " is " << strToUpper(s1) << endl;
    cout << "Bool value of find the \"ana\" substring in Jana: " << s1.find("ana"); 
}