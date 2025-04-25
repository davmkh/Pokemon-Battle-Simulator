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


    // 8-BIT SPRITES FOR SELECT SCREEN -------------------------------------------------------------

    // Abomasnow 8-bit
    Texture abomasnow_8bit;
    if (!abomasnow_8bit.loadFromFile("sprites/abomasnow-icon.png"))
    {
        cerr << "cannot use abomasnow-icon\n" << endl;
    }

    Sprite abomasnowIcon(abomasnow_8bit);
    abomasnowIcon.setScale({ 1, 1 });

    // Blastoise 8-bit
    Texture blastoise_8bit;
    if (!blastoise_8bit.loadFromFile("sprites/blastoise-icon.png"))
    {
        cerr << "cannot use blastoise-icon\n" << endl;
    }

    Sprite blastoiseIcon(blastoise_8bit);
    blastoiseIcon.setScale({ 1, 1 });

    // Charizard 8-bit
    Texture charizard_8bit;
    if (!charizard_8bit.loadFromFile("sprites/charizard-icon.png"))
    {
        cerr << "cannot use charizard-icon\n" << endl;
    }

    Sprite charizardIcon(charizard_8bit);
    charizardIcon.setScale({ 1, 1 });

    // Darkrai 8-bit
    Texture darkrai_8bit;
    if (!darkrai_8bit.loadFromFile("sprites/darkrai-icon.png"))
    {
        cerr << "cannot use darkrai-icon\n" << endl;
    }

    Sprite darkraiIcon(darkrai_8bit);
    darkraiIcon.setScale({ 1, 1 });

    // Gengar 8-bit
    Texture gengar_8bit;
    if (!gengar_8bit.loadFromFile("sprites/gengar-icon.png"))
    {
        cerr << "cannot use gengar-icon\n" << endl;
    }

    Sprite gengarIcon(gengar_8bit);
    gengarIcon.setScale({ 1, 1 });

    // Lucario
    Texture lucario_8bit;
    if (!lucario_8bit.loadFromFile("sprites/lucario-icon.png"))
    {
        cerr << "cannot use lucario-icon\n" << endl;
    }

    Sprite lucarioIcon(lucario_8bit);
    lucarioIcon.setScale({ 1, 1 });

    // Metagross 8-bit
    Texture metagross_8bit;
    if (!metagross_8bit.loadFromFile("sprites/metagross-icon.png"))
    {
        cerr << "cannot use metagross-icon\n" << endl;
    }

    Sprite metagrossIcon(metagross_8bit);
    metagrossIcon.setScale({ 1, 1 });

    // Mewtwo 8-bit
    Texture mewtwo_8bit;
    if (!mewtwo_8bit.loadFromFile("sprites/mewtwo-icon.png"))
    {
        cerr << "cannot use mewtwo-icon\n" << endl;
    }

    Sprite mewtwoIcon(mewtwo_8bit);
    mewtwoIcon.setScale({ 1, 1 });


    // Pikachu 8-bit
    Texture pikachu_8bit;
    if (!pikachu_8bit.loadFromFile("sprites/pikachu-icon.png"))
    {
        cerr << "cannot use pikachu-icon\n" << endl;
    }

    Sprite pikachuIcon(pikachu_8bit);
    pikachuIcon.setScale({ 1, 1 });

    // Venasaur 8-bit
    Texture venasaur_8bit;
    if (!venasaur_8bit.loadFromFile("sprites/venasaur-icon.png"))
    {
        cerr << "cannot use venasaur-icon\n" << endl;
    }

    Sprite venasaurIcon(venasaur_8bit);
    venasaurIcon.setScale({ 1, 1 });

    // Pokeball 8-bit (CLOSED)
    Texture closedPokeball_8bit;
    if (!closedPokeball_8bit.loadFromFile("sprites/openPokeball-icon.png"))
    {
        cerr << "cannot use pokeball-icon\n" << endl;
    }

    Sprite closedPokeballIcon(closedPokeball_8bit);
    closedPokeballIcon.setScale({ 1, 1 });

    // Pokeball 8-bit (OPEN)
    Texture openPokeball_8bit;
    if (!openPokeball_8bit.loadFromFile("sprites/closedPokeball-icon.png"))
    {
        cerr << "cannot use pokeball-icon\n" << endl;
    }

    Sprite openPokeballIcon(openPokeball_8bit);
    openPokeballIcon.setScale({ 1, 1 });


    // ----------------------------------------------------------------------------------------------





    //// VENASAUR
    //Texture Venasaur;
    //if (!Venasaur.loadFromFile("sprites/venasaur-back.gif")) {
    //    cerr << "error loading in venasaur" << endl;
    //}

    //// linking image to sprite
    //Sprite VenasaurBack(Venasaur);
    //VenasaurBack.setScale({ 10, 10 });

    Texture background;
    if (!background.loadFromFile("sprites/menu background.png")) {
        cerr << "error loading background" << endl;
    }

    Sprite menuBackground(background);
    menuBackground.setScale({ 1.1, 1.1 });

    //// CHARIZARD
    //Texture Charizard;

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

            // if gamestate = main menu & mouse button is pressed
            if (event->is<Event::MouseButtonPressed >() && GAMESTATE == gameState::Menu) {

            }

            // 
            if (const auto* mouseEvent = event->getIf<Event::MouseButtonPressed>()) {
                if (mouseEvent->button == Mouse::Button::Left) {
                    Vector2f mousePOS = window.mapPixelToCoords(Mouse::getPosition(window));
                    if (playText.getGlobalBounds().contains(mousePOS)) {
                        GAMESTATE = gameState::Play;
                    }
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
            playText.setPosition({ 430, 100 });
            window.draw(playText);
            closedPokeballIcon.setPosition({ 200, 800 });
            window.draw(closedPokeballIcon);


            // drawing the pokeballs
            //pokeballIcon.setPosition({ 200, 800 });
            //window.draw(pokeballIcon);
            


            break;

        case gameState::Info:

            break;
        }



        window.display();
    }


}