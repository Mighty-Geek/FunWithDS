#include <bits/stdc++.h>
using namespace std;

/* function to check whether two strings are anagram of
each other */
bool isAnagram(string str1, string str2)
{
    // Get lengths of both strings
    int length1 = str1.length();
    int length2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (length1 != length2)
        return false;

    // Sort both the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < length1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

// Driver code
int main()
{
    string str1;
    string str2;
    int t;

    cout << "                  ANAGRAM-CHECKER";
    cout << endl;
    cout << "                 ******************";
    cout << endl <<endl;

    cout << "Enter no. of test cases:  ";
    cin >> t;
    cout << endl;

    while(t > 0) {
        cout << "Enter string 1 to check:  ";
        cin >> str1;
        cout << endl;

        cout << "Enter string 2 to check:  ";
        cin >> str2;

        cout << endl;
        // Function Call
        if (isAnagram(str1, str2)) {
            cout << "The two strings you entered are anagram of each other" ;
            cout << endl;
        }
        else {
            cout << "The two strings are not anagram of each "
                    "other";
            cout << endl;
        }
        cout << endl;
    t--;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define NO_CHARS 256

bool isAnagram(char* str1, char* str2)
{
    // Create an array named count

    int count[NO_CHARS] = { 0 };
    int i;

    // For each character in input string increase count

    for (i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    // If both the strings are of different length[this condition would
    // lead to program failure for strings like “apple” and “aple”]

    if (str1[i] || str2[i])
        return false;

    // Then we will look into our count array for any non zero values

    for (i = 0; i < NO_CHARS; i++)
        if (count[i])
            return false;
    return true;
}

// Driver code
int main()
{
    char str1[100];
    char str2[100];

    cout << "ANAGRAM-CHECKER";

    cout << endl;

    cout << "---------------------------------------------";

    cout << endl << endl;

    cout << "Enter your string 1:";
    cin >> str1;

    cout << endl << endl;

    cout << "Enter your string 2:";
    cin >> str2;

    cout << endl << endl;

    cout << "---------------------------------------------";

    cout << endl << endl;

    // Function call
    if (isAnagram(str1, str2))
        cout << "The two strings you have entered are anagrams of each other";
    else
        cout << "The two strings are not anagrams of each "
                "other";

    return 0;
}
*/
