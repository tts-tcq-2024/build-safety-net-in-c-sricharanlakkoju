#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define SOUNDEX_LENGTH 4

char getSoundexCode(char c) {
    c = toupper((unsigned char)c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int generateSoundex(const char *name, char *soundex, size_t soundexSize) {
    if (name == NULL || soundex == NULL || soundexSize < SOUNDEX_LENGTH + 1) {
        return -1;
    }

    int nameLen = strlen(name);
    if (nameLen == 0) {
        return -2;
    }

    int i = 0;
    int sIndex = 0;

    while (i < nameLen && !isAlpha(name[i])) {
        i++;
    }

    if (i == nameLen) {
        return -3;
    }

    soundex[sIndex++] = toupper((unsigned char)name[i++]);
    char lastCode = '0';

    while (i < nameLen && sIndex < SOUNDEX_LENGTH) {
        if (isAlpha(name[i])) {
            char code = getSoundexCode(name[i]);
            if (code != '0' && code != lastCode) {
                soundex[sIndex++] = code;
                lastCode = code;
            }
        }
        i++;
    }

    while (sIndex < SOUNDEX_LENGTH) {
        soundex[sIndex++] = '0';
    }

    soundex[SOUNDEX_LENGTH] = '\0';
    return 0;
}

#endif
