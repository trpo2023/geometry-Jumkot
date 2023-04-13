#include <stdlib.h>
#include <string.h>

#include <libgeometry/calculator.h>
#include <libgeometry/error.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

#define SIZE 100

int main()
{
    char enter[SIZE], figure[SIZE];
    int num = 0;
    printf("Enter a geometric figure (or press Enter for exit):\n");
    fgets(enter, SIZE, stdin);
    for (int i = 0; i < strlen(enter); i++) {
        if (enter[i] == '(') {
            to_lower(figure, num);
            if (strcmp(figure, "circle") == 0) {
                struct circle Circle = data_of_figure(enter, &num);
                specifications_of_figure(&Circle);
                show_figure(&Circle, figure);
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

    return 0;
}