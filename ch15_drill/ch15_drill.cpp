/*
    g++ ch15_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch15_drill `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double x){
	return 1;
}

double slope(double x){
	return x/2;
}

double square(double x){
	return x*x;
}



int main()
{


	using namespace Graph_lib;
	
	constexpr int xlength=600;
	constexpr int ylength=600;

	constexpr int x_origo=xlength/2;
	constexpr int y_origo=ylength/2;
	Point origo{x_origo,y_origo};

	constexpr int range_min=-20;
	constexpr int range_max=20;

	constexpr int n_points = 400;

	constexpr int x_scale = 30;
    constexpr int y_scale = 30;


	Point tl{100,100};
	Simple_window win {tl, xlength, ylength, "Function graphs"};

	Axis x {Axis::x, Point{10,y_origo}, 400, 20, "x"};
	Axis y {Axis::y, Point{x_origo,ylength-20}, 400, 20, "y"};

	x.set_color(Color::red);
	y.set_color(Color::red);

Function s1 {one, range_min, range_max, origo, n_points, x_scale, y_scale};
Function s2 {slope, range_min, range_max, origo, n_points, x_scale, y_scale};
Function s3 {square, range_min, range_max, origo, n_points, x_scale, y_scale};


win.attach(s1);
win.attach(s2);
win.attach(s3);

win.attach(x);
win.attach(y);


win.wait_for_button();
}