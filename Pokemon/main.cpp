#include <SFML/Graphics.hpp>
using namespace sf; // allows for us to not use sf:: whenever calling for a function from SFML

int main()
{
    RenderWindow window(sf::VideoMode({ 1920, 1080 }), "PA9 Pokemon Battle Sim");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}