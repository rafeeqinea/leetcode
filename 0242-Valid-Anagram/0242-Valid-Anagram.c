#include <stdbool.h>  // for bool, true, false

bool isAnagram(char* s, char* t) {
    // Step 1: Count how many letters are in each string
    int count[26] = {0};  // 26 letters a-z, all set to 0

    // Step 2: Traverse the first string `s` and increment letter counts
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';  // get index 0–25
        count[index]++;          // count this character
    }

    // Step 3: Traverse second string `t` and decrement letter counts
    for (int i = 0; t[i] != '\0'; i++) {
        int index = t[i] - 'a';  // get index 0–25
        count[index]--;          // remove one letter

        // If count goes below 0 → t has more of a letter than s → not an anagram
        if (count[index] < 0) {
            return false;
        }
    }

    // Step 4: Check if both strings were same length
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;  // some letter count didn't match
        }
    }

    return true;  // everything matched → it's an anagram
}

