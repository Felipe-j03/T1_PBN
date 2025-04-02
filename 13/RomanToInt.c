#include <stdio.h>
#include <string.h>

int c2i(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
    }
}

int romanToInt(char* s) {
    if (!s)
        return 0;

    int result = 0;
    char* p = s;

    while (*p != '\0') {
        int currentValue = c2i(*p);
        int nextValue = 0;

        if (*(p + 1) != '\0') {
            nextValue = c2i(*(p + 1));
        }

        if (nextValue > currentValue) {
            result += nextValue - currentValue;
            p++;
        } else {
            result += currentValue;
        }
        p++;
    }

    return result;
}
