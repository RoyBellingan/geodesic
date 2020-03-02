#ifndef GIS_H
#define GIS_H

typedef unsigned int uint;
class QPolygonF;
class QPointF;

uint sphereArea(const QPolygonF& bordo, double& area, double& perimeter);
double getArea(const QPolygonF& bordo);
double distance(const QPointF& a, const QPointF& b);

#endif // GIS_H
