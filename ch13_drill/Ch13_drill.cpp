/*
    g++ Ch13_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch13_drill `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"



int main()
{
	using namespace Graph_lib;
	
	const int xlength=1280;
	const int ylength=720;


	Point tl{100,100};
	Simple_window win {tl, xlength, ylength, "ch13_drill"};


	


//true=üressel kezd, false=pirossal kezd
bool colored=false;
//túl kicsi a képernyőm :(  de át lehet állítani 8-ra és 800x800-ra
const int board_x=700;
const int board_y=700; 
const int board_rate=7;
const int rect_legth=board_x/board_rate;
const int rect_width=board_y/board_rate;

for(int i=0;i<board_rate*rect_legth;i=i+rect_legth){
	for(int j=0;j<board_rate*rect_width;j=j+rect_width){
	
	Rectangle *board= new Rectangle{Point{i,j},rect_legth,rect_width};
//szinezés
	if(colored){colored=false;board->set_fill_color(Color::white);}else{colored=true;board->set_fill_color(Color::red); }

	if(j+rect_width==board_rate*rect_width && j/100%2==1 ){if(colored){colored=false;}else{colored=true;}}
	//teknikailag csak a főátló mentén kellet kiszinezni, de végülis megtettem :D(kicsit se lett túlbonyolítva)
/*páros mátrix esetén nem elég 0101 szinezési módszer így kivételt raktam hogy ilyen legyen:
rossz páros mátrix:0 1 0 1     jó páros mátrix:0 1 0 1
                   0 1 0 1                     1 0 1 0
                   0 1 0 1                     0 1 0 1 
                   0 1 0 1                     1 0 1 0
*/
	win.attach(*board);
	
	}  
}


Image i1{Point{0,300},"pic.jpg"};
Image i2{Point{0,400},"pic.jpg"};
Image i3{Point{0,500},"pic.jpg"};


win.attach(i1);
win.attach(i2);
win.attach(i3);

	
for(int i=0;i<board_rate*rect_legth;i=i+rect_legth){
	for(int j=0;j<board_rate*rect_width;j=j+rect_width){
	
	Image ii{Point{j,i},"pic2.jpg"};
	win.attach(ii);

win.wait_for_button();

	}
}



	win.wait_for_button();


	return 0;

}
