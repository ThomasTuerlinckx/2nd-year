#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lowering(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower((unsigned char)s[i]);
    }
}

int count_occurrences(const char *sub, const char *str) {
    int count = 0;
    const char *p = str;

    while ((p = strstr(p, sub)) != NULL) {
        count++;
        p++; 
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        
        to_lowering(argv[1]);
        printf("Lowercase: %s\n", argv[1]);
    } 
    else if (argc == 3) {
        // Case 2: Two strings → check occurrences
        to_lowering(argv[1]);
        to_lowering(argv[2]);

        int count = count_occurrences(argv[1], argv[2]);

        if (count > 0) {
            printf("The string \"%s\" occurs in \"%s\" %d time(s).\n", argv[1], argv[2], count);
        } else {
            printf("The string \"%s\" does NOT occur in \"%s\".\n", argv[1], argv[2]);
        }
    } 
    else {
        printf("Usage:\n");
        printf("  %s <string>\n", argv[0]);
        printf("  %s <substring> <string>\n", argv[0]);
    }

    return 0;
}

