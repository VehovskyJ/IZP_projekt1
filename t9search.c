#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Checks if string is a number
int isNumber(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}

// TODO: If no contact found print "Not Found"
// TODO: If results then print "Kontakt(y) nalezen(y)" and list the matching contacts in format "JMENO, TELCISLO"
// TODO: (nepovinné, avšak může zlepšit hodnocení) Hledání přerušených posloupností znaků. Program najde i takové kontakty, u který mezi každými dvěma nalezenými znaky může být libovolná posloupnost jiných znaků. Důležité je, že nalezený řetězec (jména nebo telefonního čísla) musí obsahovat všechny znaky, které číslovky reprezentují, a ve stejném pořadí.
// TODO: (prémiové) Hledání podobných kontaktů. Pokud zadal uživatel špatný vyhledávací řetězec (spletl se v čísle), program mu nabídne podobné výsledky. Uvažujte následující chyby uživatele: chybná číslice, chybějící číslice, číslice zadaná navíc. Program by měl být konfigurován argumentem programu -l L, kde L reprezentuje maximální počet uvažovaných chyb uživatele (pozn. symbol L je inspirován z tzv. Levenshteinovy vzdálenosti dvou řetězců).
int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Too many arguments\n");
        return 0;
    } else if (argc < 2) {
        // TODO: Print all contacts
    }

    // Checks if the first argument is a number
    if(!isNumber(argv[1])) {
        fprintf(stderr, "Search query is not a valid number\n");
        return 0;
    }

    char name[101];
    char number[101];
    char c;
    int switcher = 0;
    int index = 0;
    while ((c = getchar()) != EOF) {
        if (index < 101) {
            if (switcher % 2 == 1) {
                name[index++] = c;
            } else {
                number[index++] = c;
            }
        } else {
            if (switcher % 2 == 1) {
                name[100] = '\n';
            } else {
                number[100] = '\n';
            }
        }

        if (c == '\n') {
            // TODO: if empty replace with [empty]
            printf("%s", name);
            printf("%s", number);
            index = 0;
            memset(name, 0, 101);
            memset(number, 0, 101);
            switcher++;
        }
    }

    return 0;
}
