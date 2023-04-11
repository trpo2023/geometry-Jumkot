#include <stdlib.h>
#include <ctype.h>

#include <libgeometry/parser.h>
#include <libgeometry/lexer.h>
#include <libgeometry/error.h>

double number_search(char* arr, int* num)
{
    char* exp = malloc(20 * sizeof(char));
    int i = 0;
    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        if (arr[*num] == '.' && arr[*(num + 1)] == '.') {
            show_error(ERROR_NUMBER, *num, NULL);
            exit(EXIT_FAILURE);
        }
        exp[i] = arr[*num];
        i++;
        *num += 1;
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
    Circle.center.x = number_search(arr, num);

    skip_space(arr, num, '0');
    Circle.center.y = number_search(arr, num);
    skip_space(arr, num, ',');
    *num += 1;

    skip_space(arr, num, '0');
    Circle.radius = number_search(arr, num);
    skip_space(arr, num, ')');
    *num += 1;
    skip_space(arr, num, '\n');

    return Circle;
}