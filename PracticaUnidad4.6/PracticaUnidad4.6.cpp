/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Alienigena.h"
#include "Crosshair.h"
#include <iostream>

/////Variables//////
using namespace sf;
using namespace std;

int alto = 600;
int ancho = 800;
int puntos = 0;

int main()
{
	/////Creamos la ventana//////
	RenderWindow App(VideoMode(ancho, alto, 32), "ventana");
	
	//creamos al alienigena
	Alienigena A1;

	//creamos un crosshair
	Crosshair C1;

	while (App.isOpen())
	{

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
			case Event::MouseButtonPressed:
				//si se presiona el click izquierdo y los sprites se solapan, se suma un punto y el alien cambia de lugar
				if (Mouse::isButtonPressed(Mouse::Left) and (A1.colisionDetectada(C1.crosshair))) { 
						A1.ObtenerPosicionAleatoria();
						puntos++;
						break;
					}
				}	
			

			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				App.close();
			}
			
		}

		//el crosshair sigue al mouse
		C1.crosshair.setPosition(Mouse::getPosition(App).x, Mouse::getPosition(App).y);

		if (puntos < 5) {
			App.clear();
			App.draw(A1.Alien);
			App.draw(C1.crosshair);
			App.display();
		}
		else {
			App.close();
		}
		


	}  	return 0;}