//
//  TComponents.h
//  mission5
//
//  Created by Dell on 21.08.2022.
//  Copyright © 2022 Dell. All rights reserved.
//

#ifndef TComponents_h
#define TComponents_h
#include <SFML/Graphics.hpp>
class Button{
    int x,y;
    int dx,dy;
    sf::CircleShape button;
public:
    Button(int x,int y,int dx,int dy):x(x),y(y),dx(dx),dy(dy)
    {
        button.setRadius(dx*dy);
        button.setPosition(x, y);
        button.setFillColor(sf::Color::Red);
    }
    void draw(sf::RenderWindow &window){
        window.draw(button);
    }
};


#endif /* TComponents_h */
