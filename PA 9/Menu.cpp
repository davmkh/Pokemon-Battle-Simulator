#include "Menu.h"
#include <SFML/Graphics.hpp>

Menu::Menu() {
}

bool Menu::MainMenu() {
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML Animation");
    window.setFramerateLimit(60);

    sf::Texture background;
    if (!background.loadFromFile("bakcgroundnew.jpg")) {
        return false;
    }

    // Create sprite
    sf::Sprite backsprite(background);
    backsprite.setScale({ 4,4 });
    backsprite.setPosition({ 0, 0 });


    //////////////////////////////////////////////////////////


    //GreatBall
    sf::Texture texture;
    if (!texture.loadFromFile("great-pokeball.png")) {
        return false;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition({ 400, 450 });
    sprite.setScale({ 10,10 });
    //SportBall
    sf::Texture texture1;
    if (!texture1.loadFromFile("master-pokeball.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite1(texture1);
    sprite1.setPosition({ 800, 450 });
    sprite1.setScale({ 10,10 });

    //GigaBall
    sf::Texture texture2;
    if (!texture2.loadFromFile("sport-pokeball.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite2(texture2);
    sprite2.setPosition({ 1200, 450 });
    sprite2.setScale({ 10,10 });


    ////////////////////////text////////////////////
    // Text objects - ALWAYS VISIBLE
    sf::Font font("vertopal.com_8514oem.ttf");

    sf::Text titleText(font, "CHOOSE YOUR POKEBALL", 100);
    titleText.setPosition({ 350, 200 });

    sf::Text PlayText(font, "PLAY", 60);
    PlayText.setPosition({ 475, 420 });

    sf::Text LeaderText(font, "LEADERBOARD", 60);
    LeaderText.setPosition({ 750, 420 });

    sf::Text ExitText(font, "EXIT", 60);
    ExitText.setPosition({ 1275, 420 });

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);

        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePixelPos);

        if (sprite.getGlobalBounds().contains(mouseWorldPos)) { sprite.setPosition({ 400, 450 }); }
        else { sprite.setPosition({ 400, 460 }); }
        if (sprite1.getGlobalBounds().contains(mouseWorldPos)) { sprite1.setPosition({ 800, 450 }); }
        else { sprite1.setPosition({ 800, 460 }); }
        if (sprite2.getGlobalBounds().contains(mouseWorldPos)) { sprite2.setPosition({ 1200, 450 }); }
        else { sprite2.setPosition({ 1200, 460 }); }

        window.clear();
        window.draw(backsprite);
        window.draw(sprite);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(titleText);
        window.draw(PlayText);
        window.draw(LeaderText);
        window.draw(ExitText);
        window.display();
    }
}