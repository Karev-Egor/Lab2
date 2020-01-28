#include "..\Lab2\DekartovList.h"
#include "stdio.h"

namespace Prog2 {


	DekartovList::DekartovList(double n) :p(0, 0) {
		if (n < 0)
			throw std::exception("invalid value");
		this->n = n;
	}


	DekartovList::DekartovList(const Point &p0, double n) :p(p0) {
		if (n < 0)
			throw std::exception("invalid value");
		this->n = n;
	}

	DekartovList::DekartovList(double x0, double y0, double n) :p(x0, y0) {
		if (n < 0)
			throw std::exception("invalid value");
		this->n = n;
	}


	DekartovList& DekartovList::setN(double n) {
		if (n < 0)
			throw std::exception("invalid value");
		this->n = n;

		return *this;
	}

	Point DekartovList::f(double x)  {
		double dx = x - p.x;
		if(((l(n) + dx) / (l(n) - 3 * dx)) < 0)
			throw std::exception("invalid argument x (too much)");
		Point res;
		dx = dx * sqrt((l(n) + dx) / (l(n) - 3 * dx));
		res.y = p.y - dx;
		res.x = p.y + dx;
		return res;
	}

	double DekartovList::polar(double alfa) {
		double ro;
		int a = alfa / 360;
		alfa = alfa - a * 360;
		ro = (l(n)*(sin(alfa)*sin(alfa) - cos(alfa)*cos(alfa))) / (3*sin(alfa)*sin(alfa)*sin(alfa)+ cos(alfa)*cos(alfa)*cos(alfa));
		return abs(ro);
	}

	char* DekartovList::frm() const {
		const char *s1 = "(x -  )^3 + (y -  )^3 = *x*y \n";
		int l = strlen(s1) + 1;
		size_t Size = 20;
		char num[20];
		sprintf_s(num, 20, "%.2f", p.x);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.y); 
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", n);
		l += strlen(num);

		char* s = new char[l];

		if (p.x == 0)
			sprintf_s(s, l, "x ^ 3");
		else
			sprintf_s(s, l, "(x - %.2f) ^ 3", p.x);
		int k = strlen(s);
		if (p.y == 0)
			sprintf_s(s + k, l - k, " + y ^ 3");
		else
			sprintf_s(s + k, l - k, " + (y - %.2f) ^ 3", p.y);
		k = strlen(s);

		sprintf_s(s + k, l - k, " = %.2f*x*y", n);
		return s;
	}


}