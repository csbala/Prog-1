#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	Menu color_menu;

	void change_color(Color c);
	void red_pressed();//calback metódus: valaki lenyomta a gombot és váltosztassuk meg
	void blue_pressed();
	void black_pressed();

	Button select_color;
	void select_color_pressed();
	void list_color_pressed();

	Menu style_menu;
	void change_style(Line_style ls);
	void solidline_pressed();
	void dotline_pressed();

	Button select_linestyle;
	void select_linestyle_pressed();
	void list_linestyle_pressed();

	void next();
	void quit();

};