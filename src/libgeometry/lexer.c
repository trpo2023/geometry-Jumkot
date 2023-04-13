#include <ctype.h>
#include <stdlib.h>

#include <libgeometry/error.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

double number_search(char* arr, int* num, char ch)
{
    char* exp = malloc(20 * sizeof(char));
    int i = 0;
    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        if (arr[*num] == '.' && arr[*num + 1] == '.') {
            show_error(ERROR_NUMBER, *num + 1, NULL);
            exit(EXIT_FAILURE);
        }
        exp[i] = arr[*num];
        i++;
        *num += 1;
    }
    if (arr[*num] != ' ' && arr[*num] != ch && isdigit(arr[*num - 1])
        && isdigit(arr[*num + 1])) {
        show_error(ERROR_EXPECT_DOT, *num, NULL);
        exit(EXIT_FAILURE);
    }
    char* trash;
    double Number = strtod(exp, &trash);
    free(exp);
    return Number;
}

struct circle data_of_figure(char* arr, int* num)
{
    struct circle Circle;

    *num += 1;
    skip_space(arr, num, '0');
    Circle.center.x = number_search(arr, num, ' ');

    skip_space(arr, num, '0');
    Circle.center.y = number_search(arr, num, ',');
    skip_space(arr, num, ',');
    *num += 1;

    skip_space(arr, num, '0');
    Circle.radius = number_search(arr, num, ')');
    skip_space(arr, num, ')');
    *num += 1;
    skip_space(arr, num, '\n');

    return Circle;
}