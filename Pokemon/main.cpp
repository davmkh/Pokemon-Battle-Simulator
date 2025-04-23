#include "header.h"

using namespace sf; // allows for us to not use sf:: whenever calling for a function from SFML

enum class gameState {
    Menu,
    Play,
    Info,
    Settings, // will add settings later (after PA9 is due)
    GameOver
};

int main()
{
    gameState GAMESTATE = gameState::Menu;

    srand(time(nullptr));
    // linking all pokemon sprites

    // VENASAUR
    Texture Venasaur;
    if (!Venasaur.loadFromFile("sprites/venasaur-back.gif")) {
        cerr << "error loading in sprite" << endl;
    }

    // linking image to sprite
    Sprite VenasaurBack(Venasaur);
    VenasaurBack.setScale({ 10, 10 });


    // CHARIZARD
    Texture Charizard;

    // FONT
    Font font;
    if (!font.openFromFile("Pokemon Classic.ttf")) {
        cerr << "cannot use font" << endl;
    }

    // links font images
    Text fontText(font);
    fontText.setString("TESTING1"); // draws font on screen
    fontText.setFillColor(Color::Cyan); // sets color
    fontText.setPosition({ 500, 250 }); // sets position
    fontText.setCharacterSize(100);


    // MUSIC
    Music opening;
    if (!opening.openFromFile("music/menu.ogg")) {
        cerr << "cannot use song" << endl;
    }

    // plays music
    opening.play();

    RenderWindow window(VideoMode({ 1920, 1080 }), "PA9 Pokemon Battle Sim");
    window.setFramerateLimit(FPS); // sets framerate

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {

            // if X is used, close window
            if (event->is<Event::Closed>()) {
                window.close();
            }

            // if gamestate = main menu
            if (event->is<Event::MouseButtonPressed >() && GAMESTATE == gameState::Menu)
            {

                // 
                const auto& mouseEvent = event->getIf < Event::MouseButtonPressed >();

                // if left mouse button clicked
                if (mouseEvent->button == Mouse::Button::Left) {

                    // detecting mouse position
                    Vector2f mousePOS = window.mapPixelToCoords(Mouse::getPosition(window));

                    // prints mouse position for testing
                    cout << "x = " << mousePOS.x << endl;
                    cout << "y = " << mousePOS.y << endl;

                    // text hitbox
                    if (fontText.getGlobalBounds().contains(mousePOS)) {
                        GAMESTATE = gameState::Play;
                    }
                }
            }

            // must draw in between these functions
            window.clear();

            switch (GAMESTATE) {

                // Menu case
            case gameState::Menu:
                window.draw(VenasaurBack);
                window.draw(fontText);
                break;

                // Game case
            case gameState::Play:
                fontText.setString("Testing 2");
                fontText.setPosition({ 200, 800 });
                window.draw(fontText);
                break;


            }

            window.display();
        }
    }
}

