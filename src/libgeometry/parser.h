#pragma once

#define NUM_OF_CIRCLES 2
#define SIZE 100

struct point {
    double x;
    double y;
};

struct circle {
    struct point center;
    double radius;
    double perimeter;
    double area;
};

void to_lower(char* arr, int num);
void pick_up_first_char(char* arr, char ch);
void skip_space(char* arr, int* num, char ch);
void show_figure(struct circle* Circle, char* figure);
void show_intersect(struct circle circles[NUM_OF_CIRCLES], int count);