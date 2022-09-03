//
//  TFicgures.h
//  mission5
//
//  Created by Dell on 21.08.2022.
//  Copyright © 2022 Dell. All rights reserved.
//

#ifndef TFicgures_h
#define TFicgures_h
#include <SFML/Graphics.hpp>
#include <cmath>
/*class SuperElipse:public sf::Shape{
    int x,y;
    int a,b;
    float n;
public:
    SuperElipse(int x,int y,int a,int b,float n):x(x),y(y),a(a),b(b),n(n){
        update();
    }
    virtual unsigned int getPointCount(){
        return 30;
    }
    virtual sf::Vector2f getPoint(unsigned int index) const{
        std::pow(std::abs(x/a),n)+std::pow(std::abs(y/b),n) =1;
    }
};
*/
class Elipse: public sf::Shape{
    sf::Vector2f m_radius;
    sf::Color cl;
public:
        explicit Elipse(const sf::Vector2f& radius = sf::Vector2f(0.f, 0.f)) :
        m_radius(radius)
        {
            update();
        }

        void setRadius(const sf::Vector2f& radius)
        {
            m_radius = radius;
            update();
        }
    void setFillColor(const sf::Color &color){
        cl = color;
    }
        const sf::Vector2f& getRadius() const
        {
            return m_radius;
        }

        virtual std::size_t getPointCount() const
        {
            return 30; // fixed, but could be an attribute of the class if needed
        }

        virtual sf::Vector2f getPoint(std::size_t index) const
        {
            static const float pi = 3.141592654f;

            float angle = index * 2 * pi / getPointCount() - pi / 2;
            float x = std::cos(angle) * m_radius.x;
            float y = std::sin(angle) * m_radius.y;

            return sf::Vector2f(m_radius.x + x, m_radius.y + y);
        }
    void draw(sf::RenderWindow & window){
        for(int i =0;i<100;i++){
            
            //window.draw(&point,getPointCount(),sf::TriangleStrip);
        }
    }
    
};

#endif /* TFicgures_h */
