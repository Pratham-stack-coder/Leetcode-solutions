#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100
#define MAX_LEN 100

char* normalizeEmail(char* email) {
    static char result[MAX_LEN];
    int i = 0, j = 0;
    int ignore = 0;

    // Process local part
    while (email[i] && email[i] != '@') {
        if (email[i] == '+') {
            ignore = 1;  // Ignore rest of local part
        }
        if (!ignore && email[i] != '.') {
            result[j++] = email[i];
        }
        i++;
    }

    // Copy domain part (including '@')
    while (email[i]) {
        result[j++] = email[i++];
    }

    result[j] = '\0';
    return result;
}

int numUniqueEmails(char** emails, int emailsSize) {
    char* unique[MAX_EMAILS];
    int count = 0;

    for (int i = 0; i < emailsSize; i++) {
        char* norm = normalizeEmail(emails[i]);

        int found = 0;
        for (int k = 0; k < count; k++) {
            if (strcmp(unique[k], norm) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            unique[count] = strdup(norm);
            count++;
        }
    }

    return count;
}
