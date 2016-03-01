#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "ADN generation", sf::Style::Close | sf::Style::Titlebar);
	window.setKeyRepeatEnabled(false);

	sf::Font font;
	if(!font.loadFromFile("fonts/arial.ttf")) {
		return 1;
	}

	int genNb = 0;
	string genText = "Génération n° " + std::to_string(genNb);
	wstring wGenText = L"Génération n° " + std::to_wstring(genNb);

	sf::Text text;
	text.setFont(font);
	text.setString(wGenText);
	text.setColor(sf::Color::Black);
	text.setCharacterSize(12);
	text.setPosition(10, 10);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch(event.type) {
			case sf::Event::KeyPressed:
				switch(event.key.code) {
				case sf::Keyboard::Key::N:
					genNb ++;
					genText = "Génération n° "+to_string(genNb);
					wGenText = L"Génération n° " + std::to_wstring(genNb);
					cout << genText << endl;
					text.setString(wGenText);
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
		window.draw(text);

        // end the current frame
        window.display();
    }

    return 0;
}
