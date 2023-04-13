#include <stdio.h>

#include <libgeometry/calculator.h>
#include <libgeometry/parser.h>

double perimeter_count(struct circle* Circle)
{
    return (PI * 2 * Circle->radius);
}

double area_count(struct circle* Circle)
{
    return (PI * Circle->radius * Circle->radius);
}

struct circle specifications_of_figure(struct circle* Circle)
{
    Circle->perimeter = perimeter_count(Circle);
    Circle->area = area_count(Circle);

    return *Circle;
}