#include <stdbool.h>  // for bool, true, false
#include <string.h>   // for strlen

bool isAnagram(char *s, char *t)
{
    // Step 1: Check if lengths are same
    int i = 0;
    while (s[i] != '\0')
        i++;
    int len_s = i;

    i = 0;
    while (t[i] != '\0')
        i++;
    int len_t = i;

    if (len_s != len_t)
        return false;

    // Step 2: Create count array of size 26 (a to z)
    int count[26];
    i = 0;
    while (i < 26)
    {
        count[i] = 0;
        i++;
    }

    // Step 3: Count each char from s and t
    i = 0;
    while (s[i] != '\0')
    {
        count[s[i] - 'a']++;  // add 1 for s
        count[t[i] - 'a']--;  // subtract 1 for t
        i++;
    }

    // Step 4: Check if all counts are 0
    i = 0;
    while (i < 26)
    {
        if (count[i] != 0)
            return false;
        i++;
    }

    return true;
}

