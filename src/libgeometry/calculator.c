#include <math.h>
#include <stdio.h>

#include <libgeometry/calculator.h>
#include <libgeometry/parser.h>

double perimeter_count(struct circle* Circle)
{
    return (M_PI * 2 * Circle->radius);
}

double area_count(struct circle* Circle)
{
    return (M_PI * Circle->radius * Circle->radius);
}

struct circle specifications_of_figure(struct circle* Circle)
{
    Circle->perimeter = perimeter_count(Circle);
    Circle->area = area_count(Circle);

    return *Circle;
}

bool intersect(struct circle* first, struct circle* second)
{
    double distance = sqrt(pow(second->center.x - first->center.x, 2) + pow(second->center.y - first->center.y, 2));
    if (distance < first->radius + second->radius) {
        return true;
    }
    return false;
}