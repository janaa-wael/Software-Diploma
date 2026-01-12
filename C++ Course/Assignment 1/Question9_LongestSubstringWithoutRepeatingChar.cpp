#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int arr[24] = {};
    string s = "aabbccddeeff";
    for(int i = 0 ; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    
    int start = 0;
    int max = 0;
    int curr_count = 0;
    int len = 0;
    while(start != s.length())
    {
        if(arr[s[curr_count] - 'a'] != 0)
        {
            max = max > len? max : len;
            start++;
            curr_count = start;
            len = 0;
            memset(arr,0,24*4);
        }
        arr[s[curr_count]-'a']++;
        curr_count++;
        len++;
    }
    cout << max << endl;
}