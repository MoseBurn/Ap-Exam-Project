#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
 
using namespace std;



int main()
{
    const float yValue = -0.5f;
    const float xValue = -0.5f;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
 

    sf::View view1;
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    


    // Load a sprite to display
    const sf::Texture texture("Images/checknew.png");
    sf::Sprite sprite(texture);
    sprite.setPosition({50.f, 150.f});
    sf::Vector2f position = sprite.getPosition();

    // Load a sprite to display
    const sf::Texture texture3("Images/rotation.png");
    sf::Sprite sprite3(texture3);
    sprite3.setPosition({50.f, 150.f});
    sf::Vector2f position3 = sprite3.getPosition();


    const sf::Texture texture2("Images/character.png");
    sf::Sprite sprite2(texture2);
    sprite2.setPosition({60.f, 431.5f});
    sprite2.setScale({.05f, .05f}); // absolute scale factor
    sf::Vector2f position2 = sprite2.getPosition();

    const sf::Texture texture1("Images/sideView.png");
    sf::Sprite sprite1(texture1);
    sprite1.setPosition({331.560f, 431.f});
    sprite1.setScale({.05f, .05f}); // absolute scale factor
    sf::Vector2f position1 = sprite1.getPosition();




    // Create a graphical text to display
    const sf::Font font("Images/files/arial.ttf");
    sf::Text text(font, "Hello SFML", 50);




    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }
 
        // Clear screen
 
        sf::Vector2f position2 = sprite2.getPosition();


        if (position2.y > 331.5f)  {
            // Draw the sprite
            window.clear();

            window.draw(sprite);
            window.draw(sprite2);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    // right key is pressed: move our character
                    float xValue = 0.5f;
                    sprite2.move({xValue, 0});
                                    // move the view at point (200, 200)
                    sf::Vector2f position2 = sprite2.getPosition();
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))

                {

                    float xValue = -0.5f;
                    sprite2.move({xValue, 0});
                }

            if (position2.y > 331.5f)
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))

                    {
                        // right key is pressed: move our character
                        float xValue = -0.5f;
                        sprite2.move({0, yValue});
                                        // move the view at point (200, 200)
                        sf::Vector2f position2 = sprite2.getPosition();


                        // move the view by an offset of (100, 100) (so its final position is (300, 300))
                    }
            if ((position2.y < 431.5f) & (position2.y > 331.5f))
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))

                    {

                        float yValue = 0.5f;
                        sprite2.move({0, yValue});
                        }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))

                {

                    float yValue = -10.f;
                    sprite2.move({0, yValue});
                    }


         }
         else {
            // Clear screen
            window.clear();

            window.draw(sprite3);
            window.draw(sprite1);

            sf::Vector2f position1 = sprite1.getPosition();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    float xValue = -0.5f;
                    sprite1.move({xValue, 0});
                    sf::Vector2f position1 = sprite1.getPosition();
                }
        
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    // right key is pressed: move our character
                    float xValue = 0.5f;
                    sprite1.move({xValue, 0});
                                    // move the view at point (200, 200)
                    sf::Vector2f position1 = sprite1.getPosition();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                {
                    float yValue = 0.5f;
                    sprite1.move({0, yValue});
                    sf::Vector2f position1 = sprite1.getPosition();
                }
        
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                    {
                        // right key is pressed: move our character
                        float xValue = -0.5f;
                        sprite1.move({0, yValue});
                                        // move the view at point (200, 200)
                        sf::Vector2f position1 = sprite1.getPosition();
                    }
            
                if (position1.x > 331.560f){
                    sprite2.setPosition({60.f, 332.f});
                    sprite1.setPosition({331.560f, 431.f});
                    

                }

            



            
         }

        // Draw the string
        window.draw(text);
 
        // Update the window
        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}
