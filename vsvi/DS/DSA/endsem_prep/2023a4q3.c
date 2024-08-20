#include <stdio.h>
#include <stdlib.h>

// Function to calculate the length of a string
int strLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Struct to represent a string with its length
typedef struct {
    int length;
    char* str;
} String;

// Function to compare two strings
int cmp(const void* a, const void* b) {
    const String* str1 = (const String*)a;
    const String* str2 = (const String*)b;
    
    int len1 = str1->length;
    int len2 = str2->length;
    int minLen = len1 < len2 ? len1 : len2; // Minimum length for comparison
    
    // Iterate through characters
    for (int i = 0; i < minLen; i++) {
        // Odd position
        if (i % 2 == 0) {
            if (str1->str[i] > str2->str[i]) return 1;
            else if (str1->str[i] < str2->str[i]) return -1;
        }
        // Even position
        else {
            if (str1->str[i] < str2->str[i]) return 1;
            else if (str1->str[i] > str2->str[i]) return -1;
        }
    }
    
    // Compare lengths for prefix checking
    if (len1 % 2 != len2 % 2) {
        // A is a prefix of B and A has an odd length
        if (len1 % 2 != 0) return -1;
        // B is a prefix of A and B has an odd length
        else return 1;
    }
    
    // Lexicographically sort by default
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int testCase = 0; testCase < t; testCase++) {
        int n;
        scanf("%d", &n);

        // Dynamically allocate memory for array of Strings
        String* strings = malloc(n * sizeof(String));
        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            strings[i].length = m;
            strings[i].str = malloc((m + 1) * sizeof(char)); // +1 for null terminator
            scanf("%s", strings[i].str);
        }

        // Sort the array of Strings
        qsort(strings, n, sizeof(String), cmp);

        // Print the sorted strings
        for (int i = 0; i < n; i++) {
            printf("%s\n", strings[i].str);
            free(strings[i].str); // Free memory for each string
        }
        
        // Free memory for the array of Strings
        free(strings);
    }

    return 0;
}
