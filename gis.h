#ifndef GIS_H
#define GIS_H

typedef unsigned int uint;
class QPolygonF;
class QPointF;

struct Point {
	  public:
	//longitude
	double x;
	//latitude
	double y;
};

struct BBox {
	static constexpr double cos45  = 0.707106781187;
	static constexpr double dXrate = 1E-4 / 6.63;
	static constexpr double dYrate = 1E-4 / 1.112;
	Point                   tl, br;
	/**
	 * @brief build a Bounding box around a point, for a certain distance
	 * @param p
	 * @param distance
	 * @return
	 */
	static BBox fromP(Point p, double distance);
};

uint sphereArea(const QPolygonF& bordo, double& area, double& perimeter);
double getArea(const QPolygonF& bordo);
double distance(const QPointF& a, const QPointF& b);
double distance(const Point &a, const Point &b);
#endif // GIS_H
