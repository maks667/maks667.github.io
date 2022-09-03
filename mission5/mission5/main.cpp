
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TComponents.h"
#include "TFicgures.h"
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window" );

    // Set the Icon
    sf::Image icon;
    
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return 0;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    float min_range = 200.f;
    float max_range = 500.f;
    float step = 10.f;
    sf::VertexArray curve(sf::PrimitiveType::LineStrip, 100);
    for (float x = min_range; x < max_range ; x += step)
    {
        curve.append(sf::Vertex(sf::Vector2f(x, -sin(x))));
    }

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

       
        // Clear screen
        window.clear();
        window.draw(curve);
        window.display();
    }

    return 0;
}
