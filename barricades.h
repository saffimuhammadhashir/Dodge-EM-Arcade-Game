#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include <ostream>


using namespace std;

using namespace sf;


struct Score_record {
	std::string name;
	int score;
};
class barricades {
public:
	float location_for_x_expected = 0, location_for_y_expected = 0, location_for_x, location_for_y;
	virtual void barrier1(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier2(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier3(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier4(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier5(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier6(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier7(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier8(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier9(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
	virtual void barrier10(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") = 0;
};

class vehicle :public barricades {
public:
	int x, y;
	vehicle() {}
	Texture texture;
	Sprite sprite;
	float speed;
	int direction;
	int path = 1;
	virtual void move(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {}
	virtual void display(RenderWindow& display_sfml_window) = 0;



};
class Enemy :public vehicle {
public:


	int level;
	Enemy() {
		speed = 1.0;
		texture.loadFromFile("enemy.png");
		sprite.setTexture(texture);
		sprite.setScale(0.3f, 0.3f);

		direction = 1;
		x = 1650;
		y = 590;
	}


	void display(RenderWindow& display_sfml_window) {

		display_sfml_window.draw(sprite);
	}
	void barrier1(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		if (location_for_x < 50) {
			location_for_x = 50;
			direction = 3;
		}
		else if (location_for_x + sprite.getGlobalBounds().width > 1780) {
			location_for_x = 1780 - sprite.getGlobalBounds().width;
			direction = 1;
		}

		if (location_for_y < 130) {
			location_for_y = 130;
			direction = 4;
		}
		else if (location_for_y + sprite.getGlobalBounds().height > 990) {
			location_for_y = 990 - sprite.getGlobalBounds().height;
			direction = 2;
		}
	}
	void barrier2(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		// Adjust the position to keep the player within the window

	/////outer left
		if (y < 815 && y>530) {
			if (location_for_x > 120 && location_for_x < 150) {
				location_for_x = 120;
				direction = 3;
			}
			else if (location_for_x > 150 && location_for_x < 200)
			{
				location_for_x = 200;
				direction = 3;
			}
		}

		if (y < 440 && y>150) {
			if (location_for_x > 120 && location_for_x < 150) {
				location_for_x = 120;
				direction = 3;
			}
			else if (location_for_x > 150 && location_for_x < 200)
			{
				location_for_x = 200;
				direction = 3;
			}
		}
	}
	//next inner left.}
	void barrier3(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {

		if (y < 720 && y>530) {
			if (location_for_x > 250 && location_for_x < 280) {
				location_for_x = 250;
				direction = 3;
			}
			else if (location_for_x > 280 && location_for_x < 330)
			{
				location_for_x = 330;
				direction = 3;
			}
		}

		if (y < 440 && y>250) {
			if (location_for_x > 250 && location_for_x < 280) {
				location_for_x = 250;
				direction = 3;
			}
			else if (location_for_x > 280 && location_for_x < 330)
			{
				location_for_x = 330;
				direction = 3;
			}
		}
	}
	void barrier4(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {

		////outer right
		if (y < 815 && y>530) {
			if (location_for_x > 1500 && location_for_x < 1530) {
				location_for_x = 1500;
				direction = 1;
			}
			else if (location_for_x > 1530 && location_for_x < 1580)
			{
				location_for_x = 1580;
				direction = 1;
			}
		}

		if (y < 440 && y>150) {
			if (location_for_x > 1500 && location_for_x < 1530) {
				location_for_x = 1500;
				direction = 1;
			}
			else if (location_for_x > 1530 && location_for_x < 1580)
			{
				location_for_x = 1580;
				direction = 1;
			}
		}

	}
	void barrier5(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {

		//next inner right.
		if (y < 720 && y>530) {
			if (location_for_x > 1360 && location_for_x < 1390) {
				location_for_x = 1360;
				direction = 1;
			}
			else if (location_for_x > 1390 && location_for_x < 1440)
			{
				location_for_x = 1440;
				direction = 1;
			}
		}

		if (y < 440 && y>250) {
			if (location_for_x > 1360 && location_for_x < 1390) {
				location_for_x = 1360;
				direction = 1;
			}
			else if (location_for_x > 1390 && location_for_x < 1440)
			{
				direction = 1;
				location_for_x = 1440;
			}
		}
	}
	void barrier6(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		//////////////////////////////////////////////
	///lowest right
		if (location_for_x > 120 && location_for_x < 760) {

			if (location_for_y > 810 && location_for_y < 845) {
				location_for_y = 845;
				direction = 2;
			}
			else if (location_for_y > 760 && location_for_y < 790) {
				location_for_y = 760;
				direction = 2;
			}

		}
		///lowest left
		if (location_for_x > 960 && location_for_x < 1580) {

			if (location_for_y > 810 && location_for_y < 845) {
				location_for_y = 845;
				direction = 2;
			}
			else if (location_for_y > 760 && location_for_y < 790) {
				location_for_y = 760;
				direction = 2;
			}

		}
	}
	void barrier7(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {

		///upper lower right
		if (location_for_x > 270 && location_for_x < 760) {

			if (location_for_y > 710 && location_for_y < 745) {
				location_for_y = 745;
				direction = 2;
			}
			else if (location_for_y > 660 && location_for_y < 690) {
				location_for_y = 660;
				direction = 2;
			}

		}
		///upper lower left
		if (location_for_x > 960 && location_for_x < 1410) {

			if (location_for_y > 710 && location_for_y < 745) {
				location_for_y = 745;
				direction = 2;
			}
			else if (location_for_y > 660 && location_for_y < 690) {
				location_for_y = 660;
				direction = 2;
			}

		}
	}
	void barrier8(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		//////////////////////////////////////////////
   ///top left
		if (location_for_x > 120 && location_for_x < 760) {

			if (location_for_y > 210 && location_for_y < 230) {
				location_for_y = 230;
				direction = 4;
			}
			else if (location_for_y > 150 && location_for_y < 190) {
				location_for_y = 150;
				direction = 4;
			}

		}
		///top right
		if (location_for_x > 960 && location_for_x < 1580) {

			if (location_for_y > 210 && location_for_y < 230) {
				location_for_y = 230;
				direction = 4;
			}
			else if (location_for_y > 150 && location_for_y < 190) {
				location_for_y = 150;
				direction = 4;
			}

		}
	}
	void barrier9(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		///top left
		if (location_for_x > 960 && location_for_x < 1410) {

			if (location_for_y > 310 && location_for_y < 330) {
				location_for_y = 330;
				direction = 4;
			}
			else if (location_for_y > 250 && location_for_y < 290) {
				location_for_y = 250;
				direction = 4;
			}

		}
		///top right
		if (location_for_x > 270 && location_for_x < 760) {

			if (location_for_y > 310 && location_for_y < 330) {
				location_for_y = 330;
				direction = 4;
			}
			else if (location_for_y > 250 && location_for_y < 290) {
				location_for_y = 250;
				direction = 4;
			}

		}
	}
	void barrier10(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		/////den
		if (location_for_x > 610 && location_for_x < 1100) {

			if (location_for_y > 370 && location_for_y < 400) {
				location_for_y = 370;
			}
			else if (location_for_y > 580 && location_for_y < 620) {
				location_for_y = 620;
			}

		}
		if (location_for_y > 370 && location_for_y < 620) {

			if (location_for_x > 615 && location_for_x < 630) {
				location_for_x = 615;
			}
			else if (location_for_x > 1090 && location_for_x < 1100) {
				location_for_x = 1100;
			}

		}


	}

	void move(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") override {
		float location_for_x_expected = 0, location_for_y_expected = 0;




		if (direction == 1) {
			location_for_y_expected = -speed;
		}
		else if (direction == 3) {
			location_for_y_expected = speed;
		}
		else if (direction == 4) {
			location_for_x_expected = -speed;

		}
		else if (direction == 2) {
			location_for_x_expected = speed;
		}

		location_for_x = x + location_for_x_expected;
		location_for_y = y + location_for_y_expected;
		barrier1(display_sfml_window, new_predicted_direction);
		barrier2(display_sfml_window, new_predicted_direction);
		barrier3(display_sfml_window, new_predicted_direction);
		barrier4(display_sfml_window, new_predicted_direction);
		barrier5(display_sfml_window, new_predicted_direction);
		barrier6(display_sfml_window, new_predicted_direction);
		barrier7(display_sfml_window, new_predicted_direction);
		barrier8(display_sfml_window, new_predicted_direction);
		barrier9(display_sfml_window, new_predicted_direction);
		barrier10(display_sfml_window, new_predicted_direction);

		// Update player position
		x = location_for_x;
		y = location_for_y;
		sprite.setPosition(Vector2f(x, y));
		random(level);
		display(display_sfml_window);
		// Optionally, implement dodge em specific logic here
	}
	void random(int level) {
		if (level >= 2 && x == 800) {
			int a = rand() % 3;

			if (y < 400) {
				y = (a == 0) ? 150 : (a == 1) ? 230 : 320;
			}
			else if (y > 640) {
				y = (a == 0) ? 845 : (a == 1) ? 760 : 630;
			}

			if (level >= 3) {
				speed = 1.5;
			}
		}
	}



};


class Player : public vehicle {
public:


	Player() {
		speed = 1.0;
		texture.loadFromFile("car.png");
		sprite.setTexture(texture);
		sprite.setScale(0.3f, 0.3f);
		resetPosition(); // Set initial position
		direction = 1;

	}

	void resetPosition() {
		x = 100;
		y = 790;
		sprite.setPosition(Vector2f(x, y));
	}

	void display(RenderWindow& display_sfml_window) {

		display_sfml_window.draw(sprite);
	}
	void keyboardinput(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {

		location_for_x_expected = 0;
		location_for_y_expected = 0;

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			location_for_y_expected = -speed;

		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			location_for_y_expected = speed;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			location_for_x_expected = -speed;

		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			location_for_x_expected = speed;
		}
		else {



			if (direction == 1) {
				location_for_y_expected = -speed;
			}
			else if (direction == 3) {
				location_for_y_expected = speed;
			}
			else if (direction == 2) {
				location_for_x_expected = speed;

			}
			else if (direction == 4) {
				location_for_x_expected = -speed;
			}


		}


	}
	void barrier1(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		// Adjust the position to keep the player within the window
		if (location_for_x < 50) {
			location_for_x = 50;
			direction = 1;
		}
		else if (location_for_x + sprite.getGlobalBounds().width > 1780) {
			location_for_x = 1780 - sprite.getGlobalBounds().width;
			direction = 3;
		}

		if (location_for_y < 130) {
			location_for_y = 130;
			direction = 2;
		}
		else if (location_for_y + sprite.getGlobalBounds().height > 990) {
			location_for_y = 990 - sprite.getGlobalBounds().height;
			direction = 4;
		}
	}
	void barrier2(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {		/////outer left
		if (y < 815 && y>530) {
			if (location_for_x > 120 && location_for_x < 150) {
				location_for_x = 120;
				direction = 1;
			}
			else if (location_for_x > 150 && location_for_x < 200)
			{
				location_for_x = 200;
				direction = 1;
			}
		}

		if (y < 440 && y>150) {
			if (location_for_x > 120 && location_for_x < 150) {
				location_for_x = 120;
				direction = 1;
			}
			else if (location_for_x > 150 && location_for_x < 200)
			{
				location_for_x = 200;
				direction = 1;
			}
		}
	}
	void barrier3(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		//next inner left.
		if (y < 720 && y>530) {
			if (location_for_x > 250 && location_for_x < 280) {
				location_for_x = 250;
				direction = 1;
			}
			else if (location_for_x > 280 && location_for_x < 330)
			{
				location_for_x = 330;
				direction = 1;
			}
		}

		if (y < 440 && y>250) {
			if (location_for_x > 250 && location_for_x < 280) {
				location_for_x = 250;
				direction = 1;
			}
			else if (location_for_x > 280 && location_for_x < 330)
			{
				location_for_x = 330;
				direction = 1;
			}
		}
	}
	void barrier4(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {		////outer right
		if (y < 815 && y>530) {
			if (location_for_x > 1500 && location_for_x < 1530) {
				location_for_x = 1500;
				direction = 3;
			}
			else if (location_for_x > 1530 && location_for_x < 1580)
			{
				location_for_x = 1580;
				direction = 3;
			}
		}

		if (y < 440 && y>150) {
			if (location_for_x > 1500 && location_for_x < 1530) {
				location_for_x = 1500;
				direction = 3;
			}
			else if (location_for_x > 1530 && location_for_x < 1580)
			{
				location_for_x = 1580;
				direction = 3;
			}
		}

	}
	void barrier5(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {		//next inner right.
		if (y < 720 && y>530) {
			if (location_for_x > 1360 && location_for_x < 1390) {
				location_for_x = 1360;
				direction = 3;
			}
			else if (location_for_x > 1390 && location_for_x < 1440)
			{
				location_for_x = 1440;
				direction = 3;
			}
		}

		if (y < 440 && y>250) {
			if (location_for_x > 1360 && location_for_x < 1390) {
				location_for_x = 1360;
				direction = 3;
			}
			else if (location_for_x > 1390 && location_for_x < 1440)
			{
				direction = 3;
				location_for_x = 1440;
			}
		}
	}
	void barrier6(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		//////////////////////////////////////////////
		///lowest right
		if (location_for_x > 120 && location_for_x < 760) {

			if (location_for_y > 810 && location_for_y < 845) {
				location_for_y = 845;
				direction = 4;
			}
			else if (location_for_y > 760 && location_for_y < 790) {
				location_for_y = 760;
				direction = 4;
			}

		}
		///lowest left
		if (location_for_x > 960 && location_for_x < 1580) {

			if (location_for_y > 810 && location_for_y < 845) {
				location_for_y = 845;
				direction = 4;
			}
			else if (location_for_y > 760 && location_for_y < 790) {
				location_for_y = 760;
				direction = 4;
			}

		}
	}
	void barrier7(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {		///upper lower right
		if (location_for_x > 270 && location_for_x < 760) {

			if (location_for_y > 710 && location_for_y < 745) {
				location_for_y = 745;
				direction = 4;
			}
			else if (location_for_y > 660 && location_for_y < 690) {
				location_for_y = 660;
				direction = 4;
			}

		}
		///upper lower left
		if (location_for_x > 960 && location_for_x < 1410) {

			if (location_for_y > 710 && location_for_y < 745) {
				location_for_y = 745;
				direction = 4;
			}
			else if (location_for_y > 660 && location_for_y < 690) {
				location_for_y = 660;
				direction = 4;
			}

		}
	}
	void barrier8(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {
		//////////////////////////////////////////////
	   ///top left
		if (location_for_x > 120 && location_for_x < 760) {

			if (location_for_y > 210 && location_for_y < 230) {
				location_for_y = 230;
				direction = 2;
			}
			else if (location_for_y > 150 && location_for_y < 190) {
				location_for_y = 150;
				direction = 2;
			}

		}
		///top right
		if (location_for_x > 960 && location_for_x < 1580) {

			if (location_for_y > 210 && location_for_y < 230) {
				location_for_y = 230;
				direction = 2;
			}
			else if (location_for_y > 150 && location_for_y < 190) {
				location_for_y = 150;
				direction = 2;
			}

		}
	}
	void barrier9(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {		///top left
		if (location_for_x > 960 && location_for_x < 1410) {

			if (location_for_y > 310 && location_for_y < 330) {
				location_for_y = 330;
				direction = 2;
			}
			else if (location_for_y > 250 && location_for_y < 290) {
				location_for_y = 250;
				direction = 2;
			}

		}
		///top right
		if (location_for_x > 270 && location_for_x < 760) {

			if (location_for_y > 310 && location_for_y < 330) {
				location_for_y = 330;
				direction = 2;
			}
			else if (location_for_y > 250 && location_for_y < 290) {
				location_for_y = 250;
				direction = 2;
			}

		}
	}
	void barrier10(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") {		/////den
		if (location_for_x > 610 && location_for_x < 1100) {

			if (location_for_y > 370 && location_for_y < 400) {
				location_for_y = 370;
			}
			else if (location_for_y > 580 && location_for_y < 620) {
				location_for_y = 620;
			}

		}
		if (location_for_y > 370 && location_for_y < 620) {

			if (location_for_x > 615 && location_for_x < 630) {
				location_for_x = 615;
			}
			else if (location_for_x > 1090 && location_for_x < 1100) {
				location_for_x = 1100;
			}

		}
	}
	void move(RenderWindow& display_sfml_window, std::string new_predicted_direction = "abc") override {


		keyboardinput(display_sfml_window, new_predicted_direction);
		location_for_x = x + location_for_x_expected;
		location_for_y = y + location_for_y_expected;
		barrier1(display_sfml_window, new_predicted_direction);
		barrier2(display_sfml_window, new_predicted_direction);
		barrier3(display_sfml_window, new_predicted_direction);
		barrier4(display_sfml_window, new_predicted_direction);
		barrier5(display_sfml_window, new_predicted_direction);
		barrier6(display_sfml_window, new_predicted_direction);
		barrier7(display_sfml_window, new_predicted_direction);
		barrier8(display_sfml_window, new_predicted_direction);
		barrier9(display_sfml_window, new_predicted_direction);
		barrier10(display_sfml_window, new_predicted_direction);
		x = location_for_x;
		y = location_for_y;
		sprite.setPosition(Vector2f(x, y));
		display(display_sfml_window);

	}
};
