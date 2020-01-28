#ifndef _VERSIERA_H_
#define _VERSIERA_H_
#pragma once
#define PI 3.141592653589793238462643383279502884L

#include <iostream>
#include <cmath>

namespace Prog2 {

	struct Point
	{
		double x;
		double y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};

	class DekartovList {
	private:
		double n;
		Point p;
	public:
		DekartovList (double num = 1);
		DekartovList(const Point &p, double num = 1);
		DekartovList(double x0, double y0, double num = 1);

		DekartovList& setN(double n);
		DekartovList& setP(const Point &p0) { p = p0; return *this; }
		
		double getN() const { return n; }
		Point getP() const { return p; }

		Point f(double x) ;
		double polar(double alfa);
		double square() { return l(n); };
		double l(double n) { return (n / sqrt(2)); }
		double area() { return (l(n)/3)*(l(n)/3); };
		double RA() { return l(n)/8 ; };
		double RO() { return l(n) / sqrt(2); };
		double poperechnik() { return sqrt(2*sqrt(3) - 3) * l(n) * 2/3 ; };
		double distance() { return l(n) * sqrt(3) / 3 ; };
		char* frm() const;
	};

}
#endif

