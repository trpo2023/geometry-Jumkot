#include <ctype.h>
#include <stdio.h>

struct point {
    double x;
    double y;
};

struct circle {
    struct point center;
    double radius;
};

void to_lower(char* arr, int num);
void skip_space(char* arr, int* num, char ch);
void show_figure(struct circle* Circle, char* figure);