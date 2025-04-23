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
        cerr << "error loading in venasaur" << endl;
    }

    // linking image to sprite
    Sprite VenasaurBack(Venasaur);
    VenasaurBack.setScale({ 10, 10 });

    Texture background;
    if (!background.loadFromFile("sprites/menu background.png")) {
        cerr << "error loading background" << endl;
    }

    Sprite menuBackground(background);
    menuBackground.setScale({ 1.1, 1.1 });

    // CHARIZARD
    Texture Charizard;

    // FONT
    Font font;
    if (!font.openFromFile("fonts/pixelFont.ttf")) {
        cerr << "cannot use font" << endl;
    }

    // links font images
    Text playText(font);
    playText.setString("Play"); // draws font on screen

    playText.setFillColor(Color::Black); // sets color
    playText.setOutlineColor(Color::White);
    playText.setOutlineThickness(5);
    playText.setPosition({ 300, 250 }); // sets position
    playText.setCharacterSize(150);


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
                    //cout << "x = " << mousePOS.x << endl;
                    //cout << "y = " << mousePOS.y << endl;

                    // text hitbox
                    if (playText.getGlobalBounds().contains(mousePOS)) {
                        GAMESTATE = gameState::Play;
                    }
                }
            }

            // must draw in between these functions
            window.clear();

            switch (GAMESTATE) {

                // Menu case
            case gameState::Menu:


                window.draw(menuBackground);
                window.draw(playText);              




                break;

                // Game case
            case gameState::Play:

                playText.setCharacterSize(100);
                playText.setString("CHOOSE YOUR TEAM");
                playText.setPosition({430, 100});
                window.draw(playText);

                

                break;

            case gameState::Info:


            }



            window.display();
        }
    }
}

