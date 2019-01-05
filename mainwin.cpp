#include "mainwin.h"
#include "java.h"
#include "donut.h"
#include <ostream>
#include <iostream>

Mainwin::Mainwin() : _store{Store{"JADE"}} {


	///////////////////////////
	/////////G U I/////////////
	///////////////////////////


	set_default_size(1000, 400);

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

	//Menu
	//adding a menubar on the top
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//FILE 
	// File menu and appened it into menu bar
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//QUIT
	//apend QUIT to the File menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
	filemenu->append(*menuitem_quit);


	//VIEW 
	// VIEW menu and appened it into menu bar
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

	//All Products
	//append all products to VIEW menu
	Gtk::MenuItem *menuitem_all_products = Gtk::manage(new Gtk::MenuItem("_All Products", true));
	menuitem_view->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
	viewmenu->append(*menuitem_all_products);

	//CREATE
	//CREATE menu and appened it into menu bar
	Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
	menubar->append(*menuitem_create);
	Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
	menuitem_create->set_submenu(*createmenu);

	//append coffee to create menu
	Gtk::MenuItem *menuitem_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
	menuitem_view->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
	createmenu->append(*menuitem_coffee);

	//Append donut to create menu
	Gtk::MenuItem *menuitem_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
	menuitem_view->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
	createmenu->append(*menuitem_donut);

	vbox->show_all();
}

Mainwin::~Mainwin() { }

	////////////////////////////////////
	/////////C A L L B A C K S//////////
	///////////////////////////////////

void Mainwin::on_quit_click() {
	close();
}

void Mainwin::on_view_all_click() {
	std::ostringstream oss;
	oss << _store << std::endl;
	Gtk::MessageDialog d{*this, oss.str()};
	int result = d.run();
	}

void Mainwin::on_create_coffee_click() {
	int darkness = rand() % DARK_LEVELS;
	double price = 5.00;
	double cost = 2.50;

	Java* c = new Java{"Coffee", price, cost, darkness};
	int shot_clock = rand() % 4;
	while (shot_clock--) {
		Shot shot = (Shot)((rand() % 5));
		c->add_shot(shot);
	}
	_store.add_product(c);
}

void Mainwin::on_create_donut_click() {

	Frosting frosting = (Frosting) (rand() % 4);
	Filling filling = (Filling)(rand() % 4);

	Donut* d = new Donut{"Donut", 0.75, 0.25, frosting, true, filling};
	_store.add_product(d);

}

