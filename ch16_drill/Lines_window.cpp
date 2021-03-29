#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},

color_menu({x_max()-150,40}, 150, 40, Menu::vertical, "Colors"),
select_color({x_max()-150,40}, 150, 40, "Select_Color", [](Address, Address pw){
    reference_to<Lines_window>(pw).select_color_pressed();}),

style_menu({x_max()-300,40}, 150, 40, Menu::vertical, "Styles"),
select_linestyle({x_max()-300,40}, 150, 40, "Line_style", [](Address, Address pw){
    reference_to<Lines_window>(pw).select_linestyle_pressed();})
{
    //konstruktor definicioja
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    color_menu.attach(new Button({0,0}, 0, 0, "Red",[](Address, Address pw){
    reference_to<Lines_window>(pw).red_pressed();
    })); 
    //a color_menu-höz viszonyít ezért van csak 0
    //callback fügvény lambdaval: bekér 2 db adress csak 1 et használunk de így kéri a buttonak konstruktora, amelyiket használjuk a szülű ablakra mutat és meghivjuk a redd_pressed
    color_menu.attach(new Button({0,0}, 0, 0, "Blue",[](Address, Address pw){
    reference_to<Lines_window>(pw).blue_pressed();
    }));
    color_menu.attach(new Button({0,0}, 0, 0, "Black",[](Address, Address pw){
    reference_to<Lines_window>(pw).black_pressed();
    }));
    attach(color_menu);
    color_menu.hide();
    attach(select_color);

    style_menu.attach(new Button({0,0}, 0, 0, "Solidline", [](Address, Address pw){
    reference_to<Lines_window>(pw).solidline_pressed();
    }));
    style_menu.attach(new Button({0,0}, 0, 0, "Dotline", [](Address, Address pw){
    reference_to<Lines_window>(pw).dotline_pressed();
    }));
    attach(style_menu);
    style_menu.hide();
    attach(select_linestyle);

}

//COLOR

void Lines_window::change_color(Color c)
{    
    lines.set_color(c);
}

void Lines_window::red_pressed(){
    change_color(Color::red);
    list_color_pressed();
    redraw();//hogy egyből látszódjon ha megnyomjuk a gombot
}

void Lines_window::blue_pressed(){
    change_color(Color::blue);
    list_color_pressed();
    redraw();
}

void Lines_window::black_pressed(){
    change_color(Color::black);
    list_color_pressed();
    redraw();
}

void Lines_window::select_color_pressed(){
    select_color.hide();//ha megnyomjuk tüntesse el önmagát 
    color_menu.show();//és jelenitse meg color_menut
}

void Lines_window::list_color_pressed(){//őt color_menu tagjai hivják meg
    color_menu.hide();
    select_color.show();

}


//STYLE

void Lines_window::change_style(Line_style ls){
    lines.set_style(ls);
}

void Lines_window::solidline_pressed(){
        change_style(Line_style::solid);
        list_linestyle_pressed();
        redraw();
    }

void Lines_window::dotline_pressed(){
        change_style(Line_style::dot);
        list_linestyle_pressed();
        redraw();
    }

void Lines_window::select_linestyle_pressed(){ 
    select_linestyle.hide();
    style_menu.show();
}

void Lines_window::list_linestyle_pressed(){
    style_menu.hide();
    select_linestyle.show();
 }



void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
