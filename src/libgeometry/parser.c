#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/error.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

void to_lower(char* arr, int num)
{
    for (int i = 0; i < num; i++) {
        arr[i] = tolower(arr[i]);
    }
}

void skip_space(char* arr, int* num, char ch)
{
    while (arr[*num] != ch) {
        if (arr[*num] == ' ') {
            *num += 1;
        } else if (
                (ch == '0')
                && (isdigit(arr[*num]) || arr[*num] == '-'
                    || arr[*num] == '.')) {
            break;
        } else if (ch == ',') {
            show_error(ERROR_EXPECT_COMMA, *num, NULL);
            exit(EXIT_FAILURE);
        } else if (ch == ')') {
            show_error(ERROR_BRACKET, *num, &arr[*num]);
            exit(EXIT_FAILURE);
        } else if (ch == '\n') {
            show_error(ERROR_UNEXPECT_TOKEN, *num, NULL);
            exit(EXIT_FAILURE);
        } else {
            show_error(ERROR_UNEXPECT_TOKEN, *num, NULL);
            exit(EXIT_FAILURE);
        }
    }
}

void show_figure(struct circle* Circle, char* figure)
{
    printf("\n%s(%.2f %.2f, %.2f)\nPerimeter: %.2f\nArea: %.2f\n",
           figure,
           Circle->center.x,
           Circle->center.y,
           Circle->radius,
           Circle->perimeter,
           Circle->area);
}
