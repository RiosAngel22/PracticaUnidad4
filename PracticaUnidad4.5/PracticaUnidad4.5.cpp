/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

/////Variables//////

int alto = 500;
int ancho = 500;


int main()
{
	/////Creamos la ventana//////
	RenderWindow App(VideoMode(ancho,alto, 32), "ventana");


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
			case Event::MouseWheelMoved:

				//(el mouse si o si tiene que hacer hover sobre la pantalla del juego para recibir el input)
				int movement = evt.mouseWheel.delta;
				//obtenemos un valor entre menos 1 y 1

				unsigned int altura = App.getSize().y;
				unsigned int anchura = App.getSize().x;
				unsigned int diferencia = 10;

				//si da 1 aumentamos la pantalla hasta 1000
				if ((movement > 0) and (altura < 1000)) {
						App.setSize(Vector2u(anchura + diferencia, altura + diferencia));
				}

				//si da -1 reducimos la pantalla hasta 100
				else if ((movement < 0) and (altura > 100)) {
						App.setSize(Vector2u(anchura - diferencia, altura - diferencia));
					}
				break;
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				App.close();
			}

			
		}


		App.clear();


		App.display();


	}	return 0;}