#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 
 
using namespace std;

// Ôóíêöèÿ äëÿ îòðèñîâêè ãðàôèêà
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Âû÷èñëåíèå çíà÷åíèÿ ôóíêöèè

        // Ïðåîáðàçîâàíèå êîîðäèíàò â ýêðàííûå
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Äîáàâëåíèå òî÷êè â ìàññèâ âåðøèí
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    // Ñîçäàíèå îêíà
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ïðèëîæåíèå äëÿ âûâîäà ãðàôèêîâ");

    // Ïåðåìåííàÿ äëÿ õðàíåíèÿ ïîëüçîâàòåëüñêîé òî÷êè
    sf::CircleShape userPoint(5); // Ðàäèóñ 5 ïèêñåëåé
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false; // Ïåðåìåííàÿ äëÿ ïðîâåðêè ñóùåñòâîâàíèÿ ïîëüçîâàòåëüñêîé òî÷êè

    // 1 _ Çàãðóçêà øðèôòà (äîïèøèòå êîä)
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // 2 _ Òåêñò äëÿ îòîáðàæåíèÿ êîîðäèíàò òî÷êè (äîïèøèòå êîä)
    // Ðàçìåð òåêñòà 20, ïîëîæåíèå òåêñòà (10,10), öâåò áåëûé. Òåêñò õðàíèòå â ïåðåìåííîé coordinatesText
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // Îñè X è Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300); // Íà÷àëî îñè X
    xAxis[0].color = sf::Color::White; // Öâåò îñè
    xAxis[1].position = sf::Vector2f(750, 300); // Êîíåö îñè X
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // Íà÷àëî îñè Y
    yAxis[0].color = sf::Color::White; // Öâåò îñè
    yAxis[1].position = sf::Vector2f(400, 550); // Êîíåö îñè Y
    yAxis[1].color = sf::Color::White;

    string place;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Ïðîâåðêà êëèêà ìûøüþ
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Ïîëó÷åíèå ïîçèöèè êëèêà
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Ïðåîáðàçîâàíèå ýêðàííûõ êîîðäèíàò â "ìàòåìàòè÷åñêèå"
                    float mathX = (mousePos.x - 400) / 30.0f; // Ìàñøòàá 30 ïî X
                    float mathY = -(mousePos.y - 300) / 100.0f; // Ìàñøòàá 100 ïî Y

                    // Óñòàíîâêà íîâîé ïîëüçîâàòåëüñêîé òî÷êè
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // Ïîìå÷àåì, ÷òî òî÷êà ñóùåñòâóåò

                    // 3 _ Äîïèøèòå ëîãèêó ïðîâåðêè òî÷êè ïî ïåðåìåííûì mathX è mathY !
                    double y = round(mathY*10);
                    double x = round(mathX);
                    if (y == (0.1 * pow(x, 2) - 4) or y == -abs(x)) {
                        place = "line";
                    }
                    else if (y < -abs(x) and y >(0.1 * x * x - 4) and y < 0)
                        place = "1";
                    else if (y < -abs(x) and y < (0.1 * x * x - 4) )
                        place = "2";
                    else if (y > -abs(x) and y > (0.1 * x * x - 4))
                        place = "3";
                    else if (y > -abs(x) and y < (0.1 * x * x - 4) and x < 0)
                        place = "4";
                    else if (y > -abs(x) and y < (0.1 * x * x - 4) and x > 0)
                        place = "5";
                        
                    
                    

                    // Îáíîâëåíèå òåêñòà ñ êîîðäèíàòàìè òî÷êè 
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ") Pos: " + place);
                }
            }
        }


        // 4 _ Î÷èñòêà ýêðàíà (äîïèøèòå êîä)
        window.clear();


        // Îòðèñîâêà îñåé
        window.draw(xAxis);
        window.draw(yAxis);



        // 5 _  Îòðèñîâêà ãðàôèêà y1 = -abs(x)
        drawGraph(window, [](float x) { return -abs(x); }, -10, 10, 30, 10, sf::Color::Blue);

        // 5 _   Îòðèñîâêà ãðàôèêà y2 = 0.1 * x * x - 4
        drawGraph(window, [](float x) { return ((0.1 * x * x) - 4); }, -10, 10, 30, 10, sf::Color::Red);

        // Îòðèñîâêà ïîëüçîâàòåëüñêîé òî÷êè, åñëè îíà ñóùåñòâóåò
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        // Îòîáðàæåíèå íîâîãî êàäðà
        window.display();
    }

    return 0;
}
