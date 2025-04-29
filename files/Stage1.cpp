#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
 
using namespace std;


// Need to add more Stages
    // 

// State where llyone place his code,                

//low priority
    // need to add a timer
    // need to add second player


const string Path = "files/";

float total = 800.f;

void ChangeCamera(float now);
sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

sf::View view2;

void Stage1();

int main()
{
    Stage1();
    return 0;

}

void Stage1() {

    view2.setCenter({800.f, 475.f});
    view2.setSize({2000.f, 1000.f});
    window.setView(view2); 
    

    // Stage 1
    const sf::Texture texture(Path +"2dMap.png");
    sf::Sprite sprite(texture);
    sprite.setPosition({50.f, 150.f});
    sf::Vector2f position = sprite.getPosition();

    const sf::Texture texture5(Path +"2dMap.png");
    sf::Sprite sprite5(texture5);
    sprite5.setPosition({1690.f, 150.f});
    sf::Vector2f position5 = sprite5.getPosition();

    const sf::Texture texture2(Path + "character.png");
    sf::Sprite sprite2(texture2);
    sprite2.setPosition({60.f, 150.5f});
    sprite2.setScale({.05f, .05f}); // absolute scale factor
    sf::Vector2f position2 = sprite2.getPosition();


    const sf::Texture texture3(Path +"ledges.png");
    sf::Sprite sprite3(texture3);
    sprite3.setPosition({500.f, 80.5f});
    sprite3.setScale({.75f, .3f}); // absolute scale factor
    sf::Vector2f position3 = sprite3.getPosition();



    const sf::Texture texture6(Path +"Fire Flower.png");
    sf::Sprite sprite6(texture6);
    sprite6.setPosition({495.f, 30.f});
    sprite6.setScale({.05f, .01f}); // absolute scale factor
    sf::Vector2f position6 = sprite6.getPosition();


    const sf::Texture texture8(Path +"flag.png");
    sf::Sprite sprite8(texture8);
    sprite8.setPosition({3140.f, 60.5f}); 
    sprite8.setScale({.05f, .05f}); // absolute scale factor
    sf::Vector2f position8 = sprite8.getPosition();

    const sf::Texture textureFire(Path +"Fireball.png");
    sf::Sprite spriteFire(textureFire);
    spriteFire.setScale({.02f, .02f}); // absolute scale factor

    const sf::Texture textureGoom(Path +"worryMIGoom.png");
    sf::Sprite spriteGoom(textureGoom);
    spriteGoom.setPosition({1422.f, 160.f}); 
    spriteGoom.setScale({.04f, .04f}); // absolute scale factor
    sf::Vector2f positionGoom = spriteGoom.getPosition();
    


//https://www.geeksforgeeks.org/how-to-convert-an-integer-to-a-string-in-c/#
    const sf::Font font(Path + "arial.ttf");
    int NumberLife = 3;
    char okay[12];
    sprintf(okay, "%d", NumberLife);
    sf::Text text(font,okay , 50);

    bool accept = true;
    bool response = false;
    // Start the game loop

    int newValue = 0;

    bool onGo = true;
    bool Value = true;
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

            // Draw the sprite
            window.clear();
            window.draw(sprite5);
            window.draw(sprite);
            window.draw(sprite3);
            window.draw(sprite8);
            window.draw(sprite6);

            if (Value == true){
                window.draw(spriteGoom);
                spriteGoom.move({-2, 0}); }

            sf::Vector2f positionGoom = spriteGoom.getPosition();



            if (response == true) {
                window.draw(spriteFire);
                sf::Vector2f positionFire = spriteFire.getPosition();


                if (positionFire.y < 140 && onGo) {
                    spriteFire.move({5, 3});
                } 
                else if (positionFire.y <= 150 && onGo == false)  {
                    spriteFire.move({5, -3});

                    sf::Vector2f positionFire = spriteFire.getPosition();

                    if (positionFire.y  <= 80)
                        onGo = true;

                }
                else {
                    newValue += 1;

                    onGo = false; }

                if ((positionFire.x - positionGoom.x) <= 5 && (positionFire.x - positionGoom.x) >= -5) {
                    Value = false;
                }

                if (newValue >= 2 )
                    response = false;

            }
            sf::Vector2f position2 = sprite2.getPosition();


            if (((position2.x > 570 && position2.x < 610 ) && (position2.y > 13 && position2.y < 40)) || accept == false) {
            
                sf::Texture texture2(Path + "Chacaterpower.png");
                sf::Sprite sprite2(texture2);
                sprite2.setScale({.05f, .05f}); // absolute scale factor
                sprite2.setPosition({position2.x, position2.y});
                window.draw(sprite2);
                accept = false;
          } else
                window.draw(sprite2);


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && accept == false ) {
                if (response == false) {

                newValue = 0;
                sf::Vector2f position2 = sprite2.getPosition();
                spriteFire.setPosition({ position2.x - 5, position2.y - 30.5f});  
                 response = true  ;     
                }  

            }







            sf::Text text(font,okay , 50);
            text.setPosition({position2.x - 60, 0});
            window.draw(text);

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
                {
                    sf::Vector2f position2 = sprite2.getPosition();
                    if (position2.y <= 150.5f ) {
                        float xValue = 3.f;
                        sprite2.move({xValue, 0});
                        float two = 3.f;
                        ChangeCamera(two);
                    }
                }

                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ))
                {
                   sf::Vector2f position2 = sprite2.getPosition();
                   if (position2.y <= 150.5f ) {
                        float xValue = 5.f;
                        sprite2.move({xValue, 0});
                        float two = 5.f;
                        ChangeCamera(two);
                   }
                }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)))
                {
                    sf::Vector2f position2 = sprite2.getPosition();
                    if (position2.x >= 60.f && position2.y <= 150.5f) {
                        float xValue = -3.f;
                        sprite2.move({xValue, 0}); 
                        float two = -3.f;
                        ChangeCamera(two);
                    }
   
                }

                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ))
                {
                    sf::Vector2f position2 = sprite2.getPosition();
                    if (position2.x >= 60.f && position2.y <= 150.5f) {
                        float xValue = -5.f;
                        sprite2.move({xValue, 0});
                        float two = -5.f;
                        ChangeCamera(two);
                    }
                }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)) {
                sf::Vector2f position2 = sprite2.getPosition();
                cout << position2.x << " \\ " << position2.y << endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (position2.y == 150.5f || (position2.x >= 502 && position2.x <= 692)) && (position2.y - 100.f) >= -50.f)
                {
                    sf::Vector2f position2 = sprite2.getPosition();
                    if ((position2.x >= 502 && position2.x <= 692) && position2.y > 86.f) {

                           float yValue = -0.f;
                           sprite2.move({0, yValue}); }
                    else   {
                            if (position2.y > -50.f) {
                                
                                float yValue = -100.f;
                                sprite2.move({0, yValue}); }
                        }
                }



            if ((position2.x - positionGoom.x) <= 5 && (position2.x - positionGoom.x) >= -5 && Value == true && position2.y >= 150.5f)
            {
                view2.setCenter({800.f, 475.f});
                window.setView(view2); 
                sprite2.setPosition({60.f, 150.5f});
                total = 800.f;
                spriteGoom.setPosition({1422.f, 160.f}); 



                NumberLife -= 1;

                sprintf(okay, "%d", NumberLife);
                sf::Text text(font,okay , 50);
                Value = true;

            }
  
            if (position2.x >= 1620.f && position2.x <= 1700.f)
                {

                    if (position2.x < 1700.f) {
                    float yValue = .85f;
                    sprite2.move({0, yValue});
                    sf::Vector2f position2 = sprite2.getPosition();
                }

                    if (position2.y >= 300){
                        view2.setCenter({800.f, 475.f});
                        window.setView(view2); 
                        sprite2.setPosition({60.f, 150.5f});
                        total = 800.f;


                        NumberLife -= 1;

                        sprintf(okay, "%d", NumberLife);
                        sf::Text text(font,okay , 50);
                        Value = true;

                    }
                }
            
            if (position2.y < 150.5f && (position2.x < 502.f || position2.x > 692.f)) {
                    float yValue = .85f;
                    sprite2.move({0, yValue});
                 
                    sf::Vector2f position2 = sprite2.getPosition();
                    if (position2.y > 150.5f)
                        sprite2.setPosition({position2.x, 150.5f});

                } 
            else if (position2.y < 68.f) {
                    float yValue = .85f;
                    sprite2.move({0, yValue});
                    
                    sf::Vector2f position2 = sprite2.getPosition();
                    if (position2.y > 68.f)
                        sprite2.setPosition({position2.x, 68.f});           

                }   
          


            

        window.display();



        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if (position2.x >= 3130) {
        std::cout << "Contrgulation";
        break;}
    
    }
}

void ChangeCamera(float now) {
    total += now;

    
    view2.setCenter({total , 475.f});
    window.setView(view2);
}