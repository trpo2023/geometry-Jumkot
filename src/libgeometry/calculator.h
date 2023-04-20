#pragma once

#include <stdbool.h>

struct circle;
double perimeter_count(struct circle* Circle);
double area_count(struct circle* Circle);
struct circle specifications_of_figure(struct circle* Circle);
bool intersect(struct circle* first, struct circle* second);
