/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/////Variables//////
using namespace sf;
using namespace std;

int velocidad = 5;

int alto = 600;
int ancho = 800;

Texture circulo;
Texture cuadrado;
Sprite personaje;

int main()
{

	circulo.loadFromFile("rcircleg.png");
	cuadrado.loadFromFile("cuad_yellow.png");
	personaje.setTexture(cuadrado);

	Vector2f escalaCirculo;
	escalaCirculo.x = circulo.getSize().x;
	escalaCirculo.y = circulo.getSize().y;


	//empezamos con la textura grande, por lo que reducimos la escala
	personaje.setScale(escalaCirculo.x / cuadrado.getSize().x, escalaCirculo.y / cuadrado.getSize().y);


	/////Creamos la ventana//////
	RenderWindow App(VideoMode(ancho, alto, 32), "ventana");


	while (App.isOpen())
	{

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case Event::Closed:
				App.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Space)) {
					//cambiamos sprite y arreglamos la escala
					personaje.setTexture(circulo);
					personaje.setScale(1, 1);
				}

			}

			//usamos la funcion mover y chequeamos si estamos en los bordes de la pantalla
			if (Keyboard::isKeyPressed(Keyboard::A) and personaje.getPosition().x > 0) {
				//usamos la variable velocidad para alterar que tan rapido nos movemos en tal direccion
				personaje.move(-velocidad, 0);
			}
			//-escalaCirculo funciona porque la posicion real esta en el punto 0,0, por lo que sin este limite, el personaje se saldria
			else if (Keyboard::isKeyPressed(Keyboard::D) and personaje.getPosition().x < ancho-escalaCirculo.x) {
				personaje.move(velocidad, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W) and personaje.getPosition().y > 0) {
				personaje.move(0,-velocidad);
			}
			else if (Keyboard::isKeyPressed(Keyboard::S) and personaje.getPosition().y < alto-escalaCirculo.y) {
				personaje.move(0,velocidad);
			}
		}




		App.clear();

		App.draw(personaje);

		App.display();


	}	return 0;}