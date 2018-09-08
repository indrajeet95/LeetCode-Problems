// Program to print all permutations of a string in sorted order.
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
 
// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil (string str, char first, int l, int h)
{
    // initialize index of ceiling element
    int ceilIndex = l;
 
    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    string temp = str.substr(l,h);
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++)
        if(temp[i] > first)
        {
            ceilIndex = i;
            break;
        }
        else
            continue;
    return ceilIndex;

//    for (int i = l+1; i <= h; i++)
//      if (str[i] > first && str[i] < str[ceilIndex])
//            ceilIndex =   i;
 
//    return ceilIndex;
}
 
// Print all permutations of str in sorted order
void sortedPermutations ( string str )
{
    // Get size of string
    int size = str.size();
 
    // Sort the string in increasing order

    sort(str.begin(), str.end());
 
    // Print permutations one by one
    bool isFinished = false;
    while ( ! isFinished )
    {
        cout << str << endl; 
        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for ( i = size - 2; i >= 0; --i )
           if (str[i] < str[i+1])
              break;
 
        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if ( i == -1 )
            isFinished = true;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceilIndex = findCeil( str, str[i], i + 1, size - 1 );
 
            // Swap first and second characters
            swap(str[i],str[ceilIndex]);
 
            // Sort the string on right of 'first char'
            sort(str.begin()+i+1,str.end());
        }
    }
}
 
// Driver program to test above function
int main()
{
    string str = "ABCD";
    sortedPermutations( str );
    return 0;
}
