// Disclaimer: ChatGPT was used to assist on how to properly use certain part of the code.
    // Mainly the offical SFML site was used for refrences https://www.sfml-dev.org/tutorials/3.0/
    // Additionally, for other minors parts, either my previous codes info were used such as using chrono
        // or if I recently looked up a site for info in this case https://www.geeksforgeeks.org/how-to-convert-an-integer-to-a-string-in-c/#


        #include <SFML/Audio.hpp>
        #include <SFML/Graphics.hpp>
        #include <iostream>
        #include <chrono>
        #include <thread>
         
        using namespace std;
        
        const string Path = "files/";
        
        float CameraXLocation = 800.f;
        
        sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
        sf::View view2;
        
        void ChangeCamera(float xIncrease);
        void Stage1();
        void resetStage1();
        void CharacterLocation();

        const sf::Texture textureBlueWall2(Path +"2dMap.png");
        sf::Sprite spriteBlueWall2(textureBlueWall2);

        const sf::Texture textureBlueWall(Path +"2dMap.png");
        sf::Sprite spriteBlueWall(textureBlueWall);

        const sf::Texture textureCharacter(Path + "character.png");
        sf::Sprite spriteCharacter(textureCharacter);

        const sf::Texture textureLedges(Path +"ledges.png");
        sf::Sprite spriteLedges(textureLedges);

        const sf::Texture textureFire_Flower(Path +"Fire Flower.png");
        sf::Sprite spriteFire_Flower(textureFire_Flower);

        const sf::Texture textureFlag(Path +"flag.png");
        sf::Sprite spriteFlag(textureFlag);

        const sf::Texture textureFire(Path +"Fireball.png");
        sf::Sprite spriteFire(textureFire);

        const sf::Texture textureGoom(Path +"worryMIGoom.png");
        sf::Sprite spriteGoom(textureGoom);

        const sf::Font font(Path + "arial.ttf");

        int NumberLife = 3;
        int CounterFireBall = 0;
        char StringLife[12];
        bool GreenLight_FireBall = true;
        bool RedLight_FireBall = false;
        bool SwitchFireBall = true;
        bool CheckingFire_Gloom_Collision = true;

        int main()
        {
            Stage1();
            return 0;
        }
        
void Stage1() 
{
    // chatgpt was used here
    view2.setCenter({800.f, 475.f});
    view2.setSize({2000.f, 1000.f});
    window.setView(view2); 
    //

    spriteBlueWall.setPosition({50.f, 150.f});
    sf::Vector2f positionBlueWall = spriteBlueWall.getPosition();

    spriteBlueWall2.setPosition({1690.f, 150.f});
    sf::Vector2f positionBlueWall2 = spriteBlueWall2.getPosition();

    spriteCharacter.setPosition({60.f, 150.5f});
    spriteCharacter.setScale({.05f, .05f});
    sf::Vector2f positionCharacter = spriteCharacter.getPosition();

    spriteLedges.setPosition({500.f, 80.5f});
    spriteLedges.setScale({.75f, .3f});
    sf::Vector2f positionLedges = spriteLedges.getPosition();

    spriteFire_Flower.setPosition({495.f, 30.f});
    spriteFire_Flower.setScale({.05f, .01f});
    sf::Vector2f positionFire_Flower = spriteFire_Flower.getPosition();

    spriteFlag.setPosition({3140.f, 60.5f}); 
    spriteFlag.setScale({.05f, .05f});
    sf::Vector2f positionFlag = spriteFlag.getPosition();

    spriteFire.setScale({.02f, .02f});

    spriteGoom.setPosition({1422.f, 160.f}); 
    spriteGoom.setScale({.04f, .04f});
    sf::Vector2f positionGoom = spriteGoom.getPosition();

    // GeeksForGeeks used here
    sprintf(StringLife, "%d", NumberLife);
    sf::Text text(font,StringLife , 50);
    //

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.draw(spriteBlueWall2);
        window.draw(spriteBlueWall);
        window.draw(spriteLedges);
        window.draw(spriteFlag);
        window.draw(spriteFire_Flower);

        if (CheckingFire_Gloom_Collision == true){
            window.draw(spriteGoom);
            spriteGoom.move({-2, 0}); }

        sf::Vector2f positionGoom = spriteGoom.getPosition();

        if (RedLight_FireBall == true) 
        {
            window.draw(spriteFire);
            sf::Vector2f positionFire = spriteFire.getPosition();

            if (positionFire.y < 140 && SwitchFireBall) 
                spriteFire.move({5, 3});
            else if (positionFire.y <= 150 && SwitchFireBall == false)  
            {
                spriteFire.move({5, -3});
                sf::Vector2f positionFire = spriteFire.getPosition();
                if (positionFire.y  <= 80)
                    SwitchFireBall = true;
            } 
            else 
            {
                CounterFireBall += 1;
                SwitchFireBall = false; 
            }

            if ((positionFire.x - positionGoom.x) <= 5 && (positionFire.x - positionGoom.x) >= -5) 
                CheckingFire_Gloom_Collision = false;
            if (CounterFireBall >= 2 )
                RedLight_FireBall = false;
        }

        sf::Vector2f positionCharacter = spriteCharacter.getPosition();

        if (((positionCharacter.x > 570 && positionCharacter.x < 610 ) && (positionCharacter.y > 13 && positionCharacter.y < 40)) || GreenLight_FireBall == false) 
        {
            sf::Texture texture2(Path + "CharacterFire.png");
            sf::Sprite spriteCharacter(texture2);
            spriteCharacter.setScale({.05f, .05f});
            spriteCharacter.setPosition({positionCharacter.x, positionCharacter.y});
            window.draw(spriteCharacter);
            GreenLight_FireBall = false;
        } else
            window.draw(spriteCharacter);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && GreenLight_FireBall == false ) 
        {
            if (RedLight_FireBall == false) 
            {
                CounterFireBall = 0;
                sf::Vector2f positionCharacter = spriteCharacter.getPosition();
                spriteFire.setPosition({ positionCharacter.x - 5, positionCharacter.y - 30.5f});  
                RedLight_FireBall = true  ;     
            }  
        }

        sf::Text text(font,StringLife , 50);
        text.setPosition({positionCharacter.x - 60, 0});
        window.draw(text);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
            {
                sf::Vector2f positionCharacter = spriteCharacter.getPosition();
                if (positionCharacter.y <= 155.5f) 
                {
                    float xValue = 3.f;
                    ChangeCamera(xValue);
                }
            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ))
            {
                sf::Vector2f positionCharacter = spriteCharacter.getPosition();
                if (positionCharacter.y <= 155.5f) 
                {
                        float xValue = 5.f;
                        ChangeCamera(xValue);
                }
            }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)))
        {
            sf::Vector2f positionCharacter = spriteCharacter.getPosition();
            if (positionCharacter.x >= 60.f && positionCharacter.y <= 155.5f) 
            {
                float xValue = -3.f;
                ChangeCamera(xValue);
            }
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ))
        {
            sf::Vector2f positionCharacter = spriteCharacter.getPosition();
            if (positionCharacter.x >= 60.f && positionCharacter.y <= 155.5f) 
            {
                float xValue = -5.f;
                ChangeCamera(xValue);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (positionCharacter.y >= 150.5f || (positionCharacter.x >= 502 && positionCharacter.x <= 692)) 
        && (positionCharacter.y - 100.f) >= -50.f && (positionCharacter.x <= 1620.f || positionCharacter.x >= 1680.f))
        {
            sf::Vector2f positionCharacter = spriteCharacter.getPosition();
            if ((positionCharacter.x >= 502 && positionCharacter.x <= 692) && positionCharacter.y > 86.f) 
            {
                float yValue = -0.f;
                spriteCharacter.move({0, yValue}); 
            } else   
                {
                    if (positionCharacter.y > -50.f) 
                    {
                        float yValue = -100.f;
                        spriteCharacter.move({0, yValue});
                    }
                }
        }

        if ((positionCharacter.x - positionGoom.x) <= 5 && (positionCharacter.x - positionGoom.x) >= -5 
        && CheckingFire_Gloom_Collision == true && positionCharacter.y >= 150.5f)
        {
            resetStage1();
        }

        if (positionCharacter.x >= 1620.f && positionCharacter.x <= 1680.f)
        {
                if (positionCharacter.x < 1700.f) 
                {
                    float yValue = .85f;
                    spriteCharacter.move({0, yValue});
                    sf::Vector2f positionCharacter = spriteCharacter.getPosition();
                } 

                if (positionCharacter.y >= 300)
                    resetStage1();
        }
        
        if (positionCharacter.y < 150.5f && (positionCharacter.x < 502.f || positionCharacter.x > 692.f)) 
        {
            CharacterLocation();
            if (positionCharacter.y > 150.5f)
                spriteCharacter.setPosition({positionCharacter.x, 150.5f});
        } else if (positionCharacter.y < 68.f) 
            {
                CharacterLocation();
                if (positionCharacter.y > 68.f)
                    spriteCharacter.setPosition({positionCharacter.x, 68.f});           
            }   

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if (positionCharacter.x >= 3130 || NumberLife <= 0) 
        {
            break;
        }
    }  
}
        
void ChangeCamera(float xIncrease) 
{
    CameraXLocation += xIncrease;
    spriteCharacter.move({xIncrease, 0}); 
    view2.setCenter({CameraXLocation , 475.f});
    window.setView(view2);
}

void resetStage1() 
{
    view2.setCenter({800.f, 475.f});
    window.setView(view2); 

    spriteCharacter.setPosition({60.f, 150.5f});
    CameraXLocation = 800.f;
    spriteGoom.setPosition({1422.f, 160.f}); 
    NumberLife -= 1;

    sprintf(StringLife, "%d", NumberLife);
    sf::Text text(font,StringLife , 50);
    CheckingFire_Gloom_Collision = true;
    GreenLight_FireBall = true;
}

void CharacterLocation() 
{
    float yValue = .85f;
    spriteCharacter.move({0, yValue});
    sf::Vector2f positionCharacter = spriteCharacter.getPosition();
}