#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
 
using namespace std;



int main()
{


    bool accetable = false;

    const float yValue = -0.5f;
    const float xValue = -0.5f;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
 

    // create a view with the rectangular area of the 2D world to show





    // Load a sprite to display
    const sf::Texture texture("Images/2dMap.png");
    sf::Sprite sprite(texture);
    sprite.setPosition({50.f, 150.f});

        // move the view at point (200, 200)

    // I got this part from Bing Ai
    
    sf::View view2;
    view2.setCenter({800.f, 475.f});
    view2.setSize({2000.f, 1000.f});

    window.setView(view2); // Apply the view to the window*/
    
    

    // move the view by an offset of (100, 100) (so its final position is (300, 300))

    sf::Vector2f position = sprite.getPosition();


    const sf::Texture texture2("Images/character.png");
    sf::Sprite sprite2(texture2);
    sprite2.setPosition({60.f, 150.5f});
    sprite2.setScale({.05f, .05f}); // absolute scale factor
    sf::Vector2f position2 = sprite2.getPosition();


    const sf::Texture texture3("Images/ledges.png");
    sf::Sprite sprite3(texture3);
    sprite3.setPosition({500.f, 80.5f});
    sprite3.setScale({.75f, .3f}); // absolute scale factor
    sf::Vector2f position3 = sprite3.getPosition();




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



            // Draw the sprite
            window.clear();

            window.draw(sprite);
            window.draw(sprite3);
            window.draw(sprite2);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    // right key is pressed: move our character
                    float xValue = 1.f;
                    sprite2.move({xValue, 0});
                                    // move the view at point (200, 200)
                    sf::Vector2f position2 = sprite2.getPosition();
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))

                {

                    float xValue = -1.f;
                    sprite2.move({xValue, 0});
                }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))

                {

                    float xValue = -1.f;
                    sprite2.move({0, xValue});

                }



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
                cout << position2.x << " \\ " << position2.y << endl;

                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (position2.y == 150.5f || (position2.x >= 502 && position2.x <= 692)) && (position2.y - 100.f) >= -50.f)

                {
                

                    if (position2.y > -50.f) {
                        
                        float yValue = -100.f;
                        sprite2.move({0, yValue});
                    }

                    sf::Vector2f position2 = sprite2.getPosition();


                        

                }
            

            

            if (position2.y < 150.5f && ((position2.x < 502.f) || (position2.x > 692.f))) {
                float yValue = .85f;
                sprite2.move({0, yValue});
                 
                sf::Vector2f position2 = sprite2.getPosition();
                if (position2.y > 150.5f)
                    sprite2.setPosition({position2.x, 150.5f});
            } else if (position2.y < 68.f) {
                float yValue = .85f;
                sprite2.move({0, yValue});
                 
                sf::Vector2f position2 = sprite2.getPosition();
                if (position2.y > 68.f)
                    sprite2.setPosition({position2.x, 68.f});

            }

                        


         




        

        // Draw the string
        window.draw(text);
 
        // Update the window
        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}
