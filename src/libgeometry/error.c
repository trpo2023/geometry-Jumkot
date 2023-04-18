#include <stdio.h>
#include <stdlib.h>

#include <libgeometry/error.h>

void show_error(int ERROR, int num, char* ch)
{
    for (int i = 0; i < num; i++) {
        putchar(' ');
    }
    printf("^\n");

    switch (ERROR) {
    case ERROR_NAME:
        printf("Error at column %d: expected %s'circle'%s\n", num, BLUE, CLOSE);
        break;
    case ERROR_BRACKET:
        if (*ch == ')') {
            printf("Error at column %d: expected %s'('%s\n", num, BLUE, CLOSE);
            break;
        } else if (*ch == '(') {
            printf("Error at column %d: expected %s')'%s\n", num, BLUE, CLOSE);
            break;
        } else if (*ch == ' ' && num < 10) {
            printf("Error at column %d: expected %s'('%s\n", num, BLUE, CLOSE);
            break;
        } else {
            printf("Error at column %d: expected %s')'%s\n", num, BLUE, CLOSE);
            break;
        }
    case ERROR_NUMBER:
        printf("Error at column %d: expected %s'<double>'%s\n",
               num,
               BLUE,
               CLOSE);
        break;
    case ERROR_UNEXPECT_TOKEN:
        printf("Error at column %d: unexpected token\n", num);
        break;
    case ERROR_EXPECT_COMMA:
        printf("Error at column %d: expected %s','%s\n", num, BLUE, CLOSE);
        break;
    case ERROR_EXPECT_DOT:
        printf("Error at column %d: expected %s'.'%s\n", num, BLUE, CLOSE);
        break;
    }
}
