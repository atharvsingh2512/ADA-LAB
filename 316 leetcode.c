#include <stdio.h>
#include <string.h>

#define MAX 256

char* removeDuplicateLetters(char* s) {

    int lastIndex[MAX];
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    int n = strlen(s);

    // store last occurrence
    for(int i = 0; i < n; i++) {
        lastIndex[(int)s[i]] = i;
    }

    for(int i = 0; i < n; i++) {

        char ch = s[i];

        if(visited[(int)ch])
            continue;

        while(top >= 0 &&
              ch < stack[top] &&
              lastIndex[stack[top]] > i) {

            visited[stack[top]] = 0;
            top--;
        }

        stack[++top] = ch;
        visited[(int)ch] = 1;
    }

    char* result = (char*)malloc(top + 2);

    for(int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }

    result[top + 1] = '\0';

    return result;
}