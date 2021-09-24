#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;

int main()
{
    float x_min = 0.f, x_max = 1200.f , y_min = 0.f, y_max = 600.f; //tamaño de la ventana

    // definimos las coordenadas y tamaño del rectangulo movil
    float x_rectangulo = x_max / 2;
    float y_rectangulo = y_max / 2;
    float  radio_rectangulo = 21.f;

    // velocidad del rectangulo movil
    float x_mov_rectangulo = 10.f, y_mov_rectangulo = 10.f;

    // definimos las coordenadas y tamaño del segundo rectangulo
    float x_rectangulo1 = x_max / 5;
    float y_rectangulo1 = y_max / 10.5;
    float  radio_rectangulo1 = 21.f;

    // definimos la ventana
    RenderWindow ventana(VideoMode(x_max, y_max), "DALE FLEMA!");
    ventana.setVerticalSyncEnabled(true);

    // definimos el primer rectangulo (movil)
    RectangleShape rectangulo(Vector2f(70, 30));
    rectangulo.setPosition(x_rectangulo, y_rectangulo);
    rectangulo.setFillColor(Color::Green);

    // definimos el segundo rectangulo
    RectangleShape rectangulo1(Vector2f(20, 60));
    rectangulo1.setPosition(x_rectangulo1, y_rectangulo1);
    rectangulo1.setFillColor(Color::Magenta);


     // se ejecuta el programa mientras la ventana esté abierta
    while (ventana.isOpen())
    {

        //verificamos todos los eventos de la ventana
        Event event;

        while (ventana.pollEvent(event))
        {
            // cerramos la ventana
            if (event.type == Event::Closed)
                ventana.close();
       }

  //posicion actual del rectangulo movil
  Vector2f posicion_rectangulo = rectangulo.getPosition();
  x_rectangulo= posicion_rectangulo.x;
  y_rectangulo = posicion_rectangulo.y;

  // esto mueve el triangulo dentro de ciertos limites con WASD o las flechas direccionales
  if ((Keyboard::isKeyPressed(Keyboard::Right) ||
      (Keyboard::isKeyPressed(Keyboard::D)))   && x_rectangulo < x_max - radio_rectangulo *2)
      rectangulo.move(x_mov_rectangulo,0.f);

  if ((Keyboard::isKeyPressed(Keyboard::Left) ||
      (Keyboard::isKeyPressed(Keyboard::A)))  && x_rectangulo > x_min)
      rectangulo.move(-x_mov_rectangulo,0.f);

  if ((Keyboard::isKeyPressed(Keyboard::Up)   ||
       (Keyboard::isKeyPressed(Keyboard::W)))  && y_rectangulo > y_min)
       rectangulo.move(0.f,-y_mov_rectangulo);

  if ((Keyboard::isKeyPressed(Keyboard::Down) ||
      (Keyboard::isKeyPressed(Keyboard::S)))  && y_rectangulo < y_max - radio_rectangulo *2)
      rectangulo.move(0.f,y_mov_rectangulo);


  //obtenemos los limites globales en base a los dos rectangulos
  FloatRect rectangulo1Box = rectangulo1.getGlobalBounds();
  FloatRect rectanguloBox = rectangulo.getGlobalBounds();

  //si el rectangulo movil toca al otro rectangulo, este ultimo cambia de color
  if (rectanguloBox.intersects(rectangulo1Box))
    {
    rectangulo1.setFillColor(Color::White);
    }

  //Si no se cumple la condicion, vuelve al color original
  else
    {
    rectangulo1.setFillColor(Color::Magenta);
    }

    // limpiamos la ventana
    ventana.clear(Color::Black);
    // dibujamos el rectangulo movil en la ventana
    ventana.draw(rectangulo);
    // dibujamos el otro rectangulo en la ventana
    ventana.draw(rectangulo1);
    // mostramos ventana en la pantalla
    ventana.display();
    }

return 0;
}
