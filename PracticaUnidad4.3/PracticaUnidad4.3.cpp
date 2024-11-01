/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/////Variables//////
using namespace sf;
using namespace std;

Texture TexAzul;
Texture TexRojo;
Sprite Circulo;

float alturaSprite;
float anchuraSprite;


vector<Sprite> Circulos;

int alto = 600;
int ancho = 800;

Vector2f PosicionRandom() {
	Vector2f Posicion;
	Posicion.x = rand() % ancho + 1;
	Posicion.y = rand() % alto + 1;
	return Posicion;

}

int main()
{
	/////Creamos la ventana//////
	RenderWindow App(VideoMode(ancho, alto, 32), "ventana");

	TexRojo.loadFromFile("rcircle.png");
	TexAzul.loadFromFile("rcircleb.png");
	
	alturaSprite = TexRojo.getSize().y;
	anchuraSprite = TexRojo.getSize().x;


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
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left) == true) {
					Circulo.setTexture(TexRojo);
					Circulo.setOrigin(anchuraSprite * 0.5, alturaSprite * 0.5);
					Circulo.setPosition(PosicionRandom());
					Circulos.push_back(Circulo);
				}
				else if (Mouse::isButtonPressed(Mouse::Right) == true) {
					Circulo.setTexture(TexAzul);
					Circulo.setOrigin(anchuraSprite * 0.5, alturaSprite * 0.5);
					Circulo.setPosition(PosicionRandom());
					Circulos.push_back(Circulo);
				}
			}
		}




		App.clear();
		
		if (Circulos.size() > 0) {
			for (int j = 0; j < Circulos.size();j++) {
				App.draw(Circulos[j]);
			}
			
		}
		
		App.display();

		
	}	return 0;}