/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
/////Variables//////
using namespace sf;

Sprite CrossHair;
Texture CrossHairTex;
/////Punto de entrada a la aplicación//////



int main()
{
	CrossHairTex.loadFromFile("crosshair.png");
	CrossHair.setTexture(CrossHairTex);

	float altura = CrossHairTex.getSize().y;
	float anchura = CrossHairTex.getSize().x;

	//centramos el origen del sprite
	CrossHair.setOrigin(0.5 * anchura, 0.5 * altura);

	//situamos el sprite en el medio exacto
	CrossHair.setPosition(400, 300);

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
		}

		App.clear();
		App.draw(CrossHair);
		App.display();
	}
	return 0;
}