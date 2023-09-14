#include <SFML/Graphics.hpp>
#include "puzzle.cpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chessboard Example");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // ªÊ÷∆∆Â≈Ã
        sf::RectangleShape square(sf::Vector2f(100, 100));
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                square.setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
                square.setPosition(i * 100, j * 100);
                window.draw(square);
            }
        }

        window.display();
    }

    return 0;
}
