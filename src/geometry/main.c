#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/calculator.h>
#include <libgeometry/error.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

#define NUM_OF_CIRCLES 2

int main()
{
    char ch;
    struct circle circles[NUM_OF_CIRCLES];
    int count = 0;
    while ((count < NUM_OF_CIRCLES)
           && printf("Enter a geometric figure (or press Q for exit):\n")
           && ((ch = getc(stdin)) != 'q')) {
        char enter[SIZE], figure[SIZE] = {};
        int num = 0;
        fgets(enter, SIZE, stdin);
        pick_up_first_char(enter, ch);
        for (int i = 0; i < strlen(enter); i++) {
            if (enter[i] == '(') {
                to_lower(figure, num);
                if (strcmp(figure, "circle") == 0) {
                    circles[count] = data_of_figure(enter, &num);
                    specifications_of_figure(&circles[count]);
                    show_figure(&circles[count++], figure);
                    break;
                } else {
                    show_error(ERROR_NAME, 0, NULL);
                    exit(EXIT_FAILURE);
                }
            } else if (enter[i] == ')' || enter[i] == ' ') {
                show_error(ERROR_BRACKET, num, &enter[i]);
                exit(EXIT_FAILURE);
            }
            figure[num] = enter[i];
            num++;
        }
    }
    if((count == NUM_OF_CIRCLES) && (intersect(&circles[0], &circles[1]))) {
        printf("These circles intersect\n");
    } else {
        printf("These circles don't intersect\n");
    }

    return 0;
}
