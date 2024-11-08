#pragma once

using namespace sf;

class Alienigena
{
public:
	Texture AlienTexture;
	Sprite Alien;

	Alienigena() {
		AlienTexture.loadFromFile("et.png");
		Alien.setTexture(AlienTexture);
		Alien.setScale(0.1, 0.1);

		//le damos al randomizador una semilla aleatoria
		srand(time(NULL));
		ObtenerPosicionAleatoria();
		
	}

	void ObtenerPosicionAleatoria() {
		Vector2f escala = Alien.getScale();

		//obtenemos el limite restandole al maximo de la pantalla el tamaño escalado de la textura original
		//multiplicamos de nuevo la escala porque getSize() regresa el tamaño sin alterar  
		unsigned int limiteX = 800 - AlienTexture.getSize().x * escala.x;
		unsigned int limiteY = 600 - AlienTexture.getSize().y * escala.y;

		//creamos 2 valores aleatorios dentro de los limites para obtener una posicion aleatoria cada vez que llamamos la funcion
		unsigned int posX = rand() % limiteX + 1;
		unsigned int posY = rand() % limiteY + 1;
		Alien.setPosition(posX, posY);
	}

	bool colisionDetectada(Sprite crosshair) {
		FloatRect Colision = (Alien.getGlobalBounds());

		//chequeamos que los sprites intersecten
		if (Colision.intersects(crosshair.getGlobalBounds())) {
			return true;
		}
		else {
			return false;
		}
	}
};

