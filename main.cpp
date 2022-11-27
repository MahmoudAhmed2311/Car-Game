#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 1000), "Car Game");
    window.setFramerateLimit(150);

    // Declare Variables
    int x1 = 170;
    int y1 = -200;
    int x2 = 535;
    int y2 = -600;
    int x3 = 415;
    int y3 = -1000;
    int x4 = 280;
    int y4 = -1400;
    int cx1 = 180;
    int cy1 =-250;
    int cx2 = 430;
    int cy2 = -500;
    int cx3 = 300;
    int cy3 = -1050;
    int cx4 = 550;
    int cy4 = -1500;
    int xm =350;
    int ym =800;
    bool play = true;
    bool sPressed = false;
    bool sReleased =false;
    bool Right = false;
    bool Left = false;
    bool UP = false;
    bool Down = false;
    bool Enter = false;
    bool hit = false;
    int i = 0;

    //--------------------

    // Start The Game
    sf::Texture start;
    sf::RectangleShape Start;
    Start.setSize(sf::Vector2f(800,1000));
    start.loadFromFile("data/start.png");
    Start.setTexture(&start);



    //Define Player
    sf::Texture image0;
    sf::RectangleShape rect0;
    rect0.setSize(sf::Vector2f(100,150));
    image0.loadFromFile("data/car.png");
    rect0.setPosition(350,800);
    rect0.setTexture(&image0);

    //Define Barriers

    // Barrier 1
    sf::Texture image1;
    sf::RectangleShape rect1;
    image1.loadFromFile("data/1.png");
    rect1.setSize(sf::Vector2f(100,200));
    rect1.setPosition(x1,y1);
    rect1.setTexture(&image1);

    // Barrier 2
    sf::Texture image2;
    sf::RectangleShape rect2;
    rect2.setSize(sf::Vector2f(100,200));
    image2.loadFromFile("data/2.png");
    rect2.setPosition(x2,y2);
    rect2.setTexture(&image2);

    // Barrier 3
    sf::Texture image3;
    sf::RectangleShape rect3;
    rect3.setSize(sf::Vector2f(100,200));
    image3.loadFromFile("data/3.png");
    rect3.setPosition(x3,y3);
    rect3.setTexture(&image3);

    // Barrier 4
    sf::Texture image4;
    sf::RectangleShape rect4;
    rect4.setSize(sf::Vector2f(100,200));
    image4.loadFromFile("data/4.png");
    rect4.setPosition(x4,y4);
    rect4.setTexture(&image4);

    //--------------------

    //Define Coin

    // Coin 1
    sf::CircleShape coin1;
    coin1.setRadius(40);
    coin1.setPosition(cx1,cy1);
    // Coin 2
    sf::CircleShape coin2;
    coin2.setRadius(40);
    coin2.setPosition(cx2,cy2);
    // Coin 3
    sf::CircleShape coin3;
    coin3.setRadius(40);
    coin3.setPosition(cx3,cy3);
    // Coin 4
    sf::CircleShape coin4;
    coin4.setRadius(40);
    coin4.setPosition(cx4,cy4);

    //Coins
    sf::Texture image5;
    image5.loadFromFile("data/coin.jpg");
    coin1.setTexture(&image5);
    coin2.setTexture(&image5);
    coin3.setTexture(&image5);
    coin4.setTexture(&image5);

    //--------------------

    // Road Of The Game
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(800,1000));
    rect.setPosition(0,0);
    sf::Texture image;
    image.loadFromFile("data/background.png");
    rect.setTexture(&image);

    //Game Over
    sf::Texture over;
    over.loadFromFile("data/Game Over.jpg");
    sf::RectangleShape gameover;
    gameover.setSize(sf::Vector2f(800,1000));
    gameover.setTexture(&over);

    //Font
    sf::Font font;
    font.loadFromFile("Data/calibri.ttf");

    // Score
    sf::Text Score;
    Score.setFont(font);
    Score.setString("Score : ");
    Score.setPosition(50,50);
    Score.setFillColor(sf::Color::Yellow);
    Score.setCharacterSize(50);

    // Value Of Score
    sf::Text VScore;
    VScore.setFont(font);
    VScore.setPosition(200,50);
    VScore.setFillColor(sf::Color::Yellow);
    VScore.setCharacterSize(50);

    // Sound Effect Of The Game

    // Sound Of Game Over
    sf::SoundBuffer buffer1;
    buffer1.loadFromFile("data/game over.wav");
    sf::Sound sound1;
    sound1.setBuffer(buffer1);

    // Sound Of Coins
    sf::SoundBuffer buffer2;
    buffer2.loadFromFile("data/coin.wav");
    sf::Sound sound2;
    sound2.setBuffer(buffer2);




     while(play==true)
    {
        // Process events
        sf::Event move;
        while(window.pollEvent(move))
        {
            // Keyboard events
            if(move.type == sf::Event::KeyPressed )
            {

                if(move.key.code ==sf::Keyboard::Enter)
                {
                    Enter =true;
                }
                if(move.key.code ==sf::Keyboard::Left)
                {
                    Left=true;
                }
                if(move.key.code ==sf::Keyboard::Right)
                {
                    Right=true;
                }
                if(move.key.code ==sf::Keyboard::Up)
                {
                    UP=true;
                }
                if(move.key.code ==sf::Keyboard::Down)
                {
                    Down=true;
                }

                sPressed=true;
           }
           if(move.type==sf::Event::Closed)
           {
               play=false;
           }

        }

        //------------------
        //Logic
        if(Enter == true)
        {
            if(sPressed == true)
            {
                if(Left==true&&xm>140)
                {
                    rect0.setPosition(xm,ym);
                    xm-=10;
                    Left=false;
                }
                if(Right==true&&xm<560)
                {
                    rect0.setPosition(xm,ym);
                    xm+=10;
                    Right=false;
                }
                if(UP==true&&ym>10)
                {
                    rect0.setPosition(xm,ym);
                    ym-=10;
                    UP=false;
                }
                if(Down==true&&ym<870)
                {
                    rect0.setPosition(xm,ym);
                    ym+=10;
                    Down=false;
                }
            }

            if(rect0.getGlobalBounds().intersects(rect1.getGlobalBounds())==true||rect0.getGlobalBounds().intersects(rect2.getGlobalBounds())==true||rect0.getGlobalBounds().intersects(rect3.getGlobalBounds())==true||rect0.getGlobalBounds().intersects(rect4.getGlobalBounds())==true)
            {
                sound1.play();
                hit = true;
                Enter = false;
            }
            if(rect0.getGlobalBounds().intersects(coin1.getGlobalBounds())==true)
            {
                sound2.play();
                i+=1;
                cy1 = -650;
            }
            if(rect0.getGlobalBounds().intersects(coin2.getGlobalBounds())==true)
            {
                sound2.play();
                i+=1;
                cy2 = -920;
            }
            if(rect0.getGlobalBounds().intersects(coin3.getGlobalBounds())==true)
            {
                sound2.play();
                i+=1;
                cy3 = -2050;
            }
            if(rect0.getGlobalBounds().intersects(coin4.getGlobalBounds())==true)
            {
                sound2.play();
                i+=1;
                cy4 = -1550;
            }

            std::string s = std::to_string(i);
            VScore.setString(s);

            // Place Of Barriers
            rect1.setPosition(x1,y1);
            rect2.setPosition(x2,y2);
            rect3.setPosition(x3,y3);
            rect4.setPosition(x4,y4);

            // Place Of Coins
            coin1.setPosition(cx1,cy1);
            coin2.setPosition(cx2,cy2);
            coin3.setPosition(cx3,cy3);
            coin4.setPosition(cx4,cy4);

            if(y1==1000)
            {
                y1 = -400;
            }
            if(y2==1000)
            {
                y2 = -1000;
            }
            if(y3==1000)
            {
                y3 = -1700;
            }
            if(y4==1000)
            {
                y4 = -2200;
            }
            if(cy1>=1000)
            {
                cy1 = -650;
            }
            if(cy2>=1000)
            {
                cy2 = -920;
            }
            if(cy3>=1000)
            {
                cy3 = -2050;
            }
            if(cy4>=1000)
            {
                cy4 = -1550;
            }

            y1+=1;
            y2+=1;
            y3+=1;
            y4+=1;
            cy1+=2;
            cy2+=2;
            cy3+=2;
            cy4+=2;

            //---------------------
            // rendring

            window.clear();
            window.draw(rect);
            window.draw(rect0);
            window.draw(rect1);
            window.draw(rect2);
            window.draw(rect3);
            window.draw(rect4);
            window.draw(coin1);
            window.draw(coin2);
            window.draw(coin3);
            window.draw(coin4);
            window.draw(Score);
            window.draw(VScore);
        }

        if(hit == true)
        {
            window.draw(gameover);
            window.draw(Score);
            window.draw(VScore);
        }

        window.display();
        window.draw(Start);
    }

}
