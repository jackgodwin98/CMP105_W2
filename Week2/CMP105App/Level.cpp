#include "Level.h"
#include <string>
#include <iostream>
using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	deltax = 0;
	deltay = 0;
	x = 1;
	c = 0;
	MousePosition.x = 0;
	MousePosition.y = 0;
	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "ERROR ERROR ERROR NO FONT ERROR ERROR" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(24);
	text.setPosition(0, 0);
	text.setFillColor(sf::Color::Red);
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setPosition(500, 0);
	text2.setFillColor(sf::Color::Green);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "The W key was pressed \n";
	}
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J); //&& (sf::Keyboard::K) && (sf::Keyboard::L)); //NOT NEEDED TO SET THE OTHERS UP BECAUSE IT ONLY OUTPUTS TEXT IF ALL ARE DOWN
		std::cout << "JKL was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	if (input->isMouseLDown())
	{
		/*if 
		std::cout << input->getMouseX << endl;
		x + 1;*/
		//get mouse position
		
		//compare to previous mouse position

		/*deltax = input->getMouseX() - MousePosition.x;
		deltay = input->getMouseY() - MousePosition.y;*/
		
		//set delta to the previous mouse position - mouse position
		if (x == 1)
		{
			MousePosition.x = input->getMouseX();
			MousePosition.y = input->getMouseY();
			
		}
		(x + 1);
		(c = 1);

	}
	if (!input->isMouseLDown())
	{
		if (c == 1)
		{
			deltax = input->getMouseX() - MousePosition.x;
			deltay = input->getMouseY() - MousePosition.y;
			text2.setString(to_string(deltax) + "," + (to_string(deltay)));
			c += 1;
		}
		
		(x = 0);
	}

}

// Update game objects
void Level::update()
{
	text.setString(to_string(input->getMouseX()) + "," + (to_string(input->getMouseY())));
	//text2.setString(to_string(deltax) + "," + (to_string(deltay)));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	window->draw(text2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}