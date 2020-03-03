#ifndef GIS_H
#define GIS_H

typedef unsigned int uint;
class QPolygonF;
class QPointF;

#include <QString>

struct Point {
	  public:
	QString precision;
	//longitude
	double y;
	//latitude
	double x;
	double getX() const;
	void   setX(double value);
	double getY() const;
	void   setY(double value);
	double getLat() const;
	void   setLat(double value);
	double getLon() const;
	void   setLon(double value);
};

struct BBox {
	//static constexpr double cos45  = 0.707106781187;
	static constexpr double dXrate = (1E-5 / 6.63) / 2;
	static constexpr double dYrate = (1E-5 / 1.112) / 2;
	Point                   tl, br;
	/**
	 * @brief build a Bounding box around a point, for a certain distance
	 * @param p
	 * @param distance
	 * @return
	 */
	static BBox fromP(Point p, double distance);
};

uint   sphereArea(const QPolygonF& bordo, double& area, double& perimeter);
double getArea(const QPolygonF& bordo);
double distance(const QPointF& a, const QPointF& b);
double distance(const Point& a, const Point& b);
#endif // GIS_H
