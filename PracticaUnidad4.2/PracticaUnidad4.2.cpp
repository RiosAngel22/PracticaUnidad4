/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
/////Variables//////
using namespace sf;


Texture CircleTex;
Sprite Circle;
Sprite Circle2;
Sprite Circle3;
Sprite Circle4;



/////Punto de entrada a la aplicación//////

bool detectarMouse(Sprite circulo,Event evt) {
	//creamos un rectangulo para preguntar si el mouse esta adentro
	FloatRect area = circulo.getGlobalBounds();

	//la funcion contains devuelve verdadero si la posicion que ingresamos esta adentro del rectangulo "area"
	if (area.contains(evt.mouseMove.x,evt.mouseMove.y)) {
		return true;
	}
	else {
		return false;
	}

}

int main()
{

	CircleTex.loadFromFile("rcircle.png");
	Circle.setTexture(CircleTex);
	Circle2.setTexture(CircleTex);
	Circle3.setTexture(CircleTex);
	Circle4.setTexture(CircleTex);

	float anchuraCirculo = CircleTex.getSize().x;
	float alturaCirculo = CircleTex.getSize().y;

	//situamos el origen del punto en el medio para que quede centrado con el mouse
	Circle.setOrigin(0.5 * anchuraCirculo, 0.5 * alturaCirculo);
	Circle2.setOrigin(0.5 * anchuraCirculo, 0.5 * alturaCirculo);
	Circle3.setOrigin(0.5 * anchuraCirculo, 0.5 * alturaCirculo);
	Circle4.setOrigin(0.5 * anchuraCirculo, 0.5 * alturaCirculo);


	int alturaLimite = 550;
	int anchuraLimite = 750;

	Circle.setPosition(60, 60);
	Circle2.setPosition(60, alturaLimite);
	Circle3.setPosition(anchuraLimite, 60);
	Circle4.setPosition(anchuraLimite, alturaLimite);

	/////Creamos la ventana//////
	RenderWindow App(VideoMode(800, 600, 32), "ventana");

	while (App.isOpen())
	{

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();

			//chequeamos si es detectado el click izquierdo
			if (Mouse::isButtonPressed(Mouse::Left) == true) {

				//preguntamos si las posiciones coinciden
				if (detectarMouse(Circle, evt)) {
					Circle.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				}
				else if (detectarMouse(Circle2, evt)) {
					Circle2.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				}
				else if (detectarMouse(Circle3, evt)) {
					Circle3.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				}
				else if (detectarMouse(Circle4, evt)) {
					Circle4.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				}
			}
		}


		App.clear();

		App.draw(Circle);
		App.draw(Circle2);
		App.draw(Circle3);
		App.draw(Circle4);
		App.display();
	}
	return 0;
}