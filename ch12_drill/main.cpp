/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double){return 1;}
double squere(double x){return x*x;}


int main()
{
    using namespace Graph_lib;
    
    int xlength=1280;
    int ylength=720;
    int x_origo=xlength/2;
    int y_origo=ylength/2;

//1. része a drillnek
//1. "windpws"
   Point tl {100,100};
   Simple_window win {tl, xlength, ylength, "Cim"};
 
//2. része a drillnek
//2. kordinátarendszer
   Axis x {Axis::x, Point{20,y_origo}, xlength, 20, "x"};
   Axis y {Axis::y, Point{x_origo,ylength+20}, ylength, 20, "y"};

//3. fügvények
   Point origo {x_origo,y_origo};

   double rmax=10,rmin=-10;
   int n_points=400;
   double xscale=50,yscale=50;
   
   Function s {one, rmin, rmax, origo, n_points, xscale, yscale};
   Function sq {squere, rmin, rmax, origo, n_points, xscale, yscale};

//4. polygonok(háromszög, téglalap,...)
   Polygon poly;	
   poly.add(Point{300,200});
   poly.add(Point{350,100});
   poly.add(Point{400,200});
   poly.set_fill_color(Color::green);

   Rectangle r {Point{400,400},100,50};
//             {a bal felső pont kordinátája, szélleség, magasság}	
   r.set_fill_color(Color::red);
   r.set_style(Line_style(Line_style::dash, 4));
   //szagatott 4 pixel vastag vonal van a téglalapnak

 //5. szöveg
Text t {Point{150,150}, "Hello,graphical world!"};
t.set_font(Font::times_bold);
t.set_font_size(20);

Polygon poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});
poly_rect.add(Point{50,75});


//6. képek
Image ii{Point{400,20},"badge.jpg"};

//ii.move(100,200); ---->  error Segmentation fault (core dumped)??

//3. része a drillnek
poly_rect.set_style(Line_style(Line_style::dash, 10));
//ii.set_style(Line_style(Line_style::dash, 4));  //úgy tünik nem lehet ezzel	
r.set_fill_color(Color::blue);
poly.set_fill_color(Color::red);
poly.move(200,200);


	//sorrendbe fedik le egymást
   win.attach(ii);	
   win.attach(x);
   win.attach(y);
   win.attach(s);
   win.attach(sq);
   win.attach(poly);
   win.attach(r);
   win.attach(poly_rect);
   win.attach(t);

	win.set_label("Canvas");
   win.wait_for_button();

}
