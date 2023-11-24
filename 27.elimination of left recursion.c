#include <stdio.h>
#include <string.h>
void eliminateLeftRecursion(char production[]);
int main() {
    char production[100];
    printf("Enter a production: ");
    fgets(production, sizeof(production), stdin);
    production[strcspn(production, "\n")] = '\0';  
    eliminateLeftRecursion(production);
    return 0;
}
void eliminateLeftRecursion(char production[]) {
    int i, j, n = 0;
    char f, b[100], c[100];
    f = production[0];
    if (production[0] == production[3]) {
        for (i = 4; production[i] != '\0'; i++) {
            for (j = 0; production[i] != '/' && production[i] != '\0'; i++) {
                b[j] = production[i];
                j++;
            }
            b[j] = '\0';  
            if (production[i] == '/')
                i++;
            for (j = 0; production[i] != '\0'; j++) {
                c[j] = production[i];
                i++;
                n++;
            }
        }
        printf("%c->%c'%c'\n", f, f, c[0]);
        printf("%c'->", f);
        for (i = 0; i <= n; i++) {
            printf("%c", b[i]);
        }
        printf("%c'/ $\n", f);
    } else {
        printf("Not a left recursion\n");
    }
}
