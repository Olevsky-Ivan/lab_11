#include <stdio.h>

#define MAX_LEN 200

int main() {
    char str[MAX_LEN];
    int word_num;

    printf("Введіть речення: ");
    if (!fgets(str, MAX_LEN, stdin)) {
        printf("Помилка вводу.\n");
        return 1;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    printf("Введіть номер слова для заміни: ");
    if (scanf("%d", &word_num) != 1 || word_num <= 0) {
        printf("Некоректний номер слова.\n");
        return 1;
    }

    int current_word = 0;
    int start = -1, end = -1;
    int in_word = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && in_word == 0) {
            in_word = 1;
            current_word++;
            if (current_word == word_num) {
                start = i;
            }
        } else if ((str[i] == ' ' || str[i+1] == '\0') && in_word == 1) {
            in_word = 0;
            if (current_word == word_num) {
                end = (str[i] == ' ') ? i - 1 : i;
                break;
            }
        }
    }

    if (start == -1) {
        printf("Слова з таким номером немає у реченні.\n");
    } else {
        char *p;
        for (p = str + start; p <= str + end; p++) {
            *p = '#';
        }
        printf("Результат: %s\n", str);
    }

    return 0;
}
