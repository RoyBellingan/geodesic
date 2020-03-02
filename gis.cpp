#include "gis.h"
#include "geodesic.h"
#include <QPointF>
#include <QPolygonF>
#include <math.h>
/**
 * @brief sphereArea è la superfice, fixata, e testata dopo aver perso 5 ore fra codici stupidi, scelte inopportune, o funzioni implementate male e basta
 * ma purtroppo non tutto è possibile rifarselo in casa, come funziona intermante è un mistero.
 * Sarei quasi tentato di rifarla partendo dall'area del poligono e calcolando le distanze con haversine, ma facciamocela bastare!
 * @param bordo
 * @param area
 * @param perimeter
 * @return how many point where used
 */
uint sphereArea(const QPolygonF& bordo, double& area, double& perimeter) {
	const double a = 6378137, f = 1 / 298.257223563; /* WGS84 */

	geod_geodesic g;
	geod_polygon  p;
	geod_init(&g, a, f);
	geod_polygon_init(&p, 0);
	for (auto&& punto : bordo) {
		geod_polygon_addpoint(&g, &p, punto.y(), punto.x());
		geod_polygon_compute(&g, &p, 0, 1, &area, &perimeter);
	}
	return geod_polygon_compute(&g, &p, 0, 1, &area, &perimeter);
	//printf("vertex:%d Perimeter: %.8f Area: %.3f\n", n, P, A);
}

double getArea(const QPolygonF& bordo) {
	double area = 0, perim = 0;
	sphereArea(bordo, area, perim);
	return area;
}

// This function converts decimal degrees to radians
double deg2rad(double deg) {
	return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
	return (rad * 180 / M_PI);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distance(const QPointF& a, const QPointF& b) {
	const double earthRadiusKm = 6371.0;
	double       lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(a.y());
	lon1r = deg2rad(a.x());
	lat2r = deg2rad(b.y());
	lon2r = deg2rad(b.x());
	u     = sin((lat2r - lat1r) / 2);
	v     = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}
