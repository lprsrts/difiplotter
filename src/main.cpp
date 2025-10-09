#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

class DirectionalFieldPlotter {
private:
  sf::RenderWindow window;
  std::vector<sf::VertexArray> field_lines;

public:
  // Window settings
  const unsigned int WINDOW_HEIGHT = 600;
  const unsigned int WINDOW_WIDTH = 800;

  // Grid NxN
  const int GRID = 20;

  // Domain boundaries
  const float X_MIN = -5.0f;
  const float X_MAX = 5.0f;
  const float Y_MIN = -5.0f;
  const float Y_MAX = 5.0f;

  const float pixels_per_domain_units =
      static_cast<float>(std::min(WINDOW_HEIGHT, WINDOW_WIDTH)) /
      (Y_MAX - Y_MIN);

  DirectionalFieldPlotter() {
    std::cout << "Starting Directional Field Plotter...";

    window = sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                              "Directional Field Plotter");
    window.setFramerateLimit(60);

    std::cout << "OK" << std::endl;
  }

  void generateFieldLines() {
    field_lines.clear();
    for (int i = 1; i < GRID; ++i) {
      for (int j = 1; j < GRID; ++j) {
        sf::VertexArray line(sf::PrimitiveType::LineStrip, 2);
        float x = X_MIN + (i * (X_MAX - X_MIN) / GRID);
        float y = Y_MIN + (j * (Y_MAX - Y_MIN) / GRID);
        float slope = differentialEquation(x, y);

        float angle = std::atan(slope);
        float dx = std::cos(angle);
        float dy = std::sin(angle);
        float scale = 0.15f;

        float param = (std::abs(angle) * 180 / M_PI) * 255 / 180;

        line[0].color = sf::Color(255, 255 - param, 255 - param);
        line[1].color = sf::Color(255, 255 - param, 255 - param);
        line[0].position = domainToWindowCoord({x - dx * scale, y - dy * scale});
        line[1].position = domainToWindowCoord({x + dx * scale, y + dy * scale});
        field_lines.push_back(line);
      }
    }
  }

  float differentialEquation(float x, float y) {
    float constant = 3.0f;
    return constant - 2 * y;
  }

  sf::Vector2f domainToWindowCoord(sf::Vector2f domain_coords) {
    return sf::Vector2f((static_cast<float>(WINDOW_WIDTH) / 2.0f) +
                            (domain_coords.x * pixels_per_domain_units),
                        (static_cast<float>(WINDOW_HEIGHT) / 2.0f) -
                            (domain_coords.y * pixels_per_domain_units));
  }

  void handleEvents() {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::Escape) {
          window.close();
        }
        // TODO: Add more controls here
      }
    }
  }

  void render() {
    window.clear(sf::Color::Black);

    //Draw grid lines
    sf::VertexArray x_axis(sf::PrimitiveType::LineStrip, 2);
    sf::VertexArray y_axis(sf::PrimitiveType::LineStrip, 2);

    x_axis[0].position = sf::Vector2f(domainToWindowCoord({X_MIN, 0}));
    x_axis[1].position = sf::Vector2f(domainToWindowCoord({X_MAX, 0}));
    y_axis[0].position = sf::Vector2f(domainToWindowCoord({0, Y_MIN}));
    y_axis[1].position = sf::Vector2f(domainToWindowCoord({0, Y_MAX}));

    window.draw(x_axis);
    window.draw(y_axis);

    for (const auto &lines : field_lines) {
      window.draw(lines);
    }

    window.display();
  }

  void run() {
    generateFieldLines();

    while (window.isOpen()) {
      handleEvents();
      render();
    }
  }
};

int main() {
  DirectionalFieldPlotter app;
  app.run();

  return 0;
}
