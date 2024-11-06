#pragma once

using namespace sf;

class Crosshair
{
public:
	Texture Crosshairtexture;
	Sprite crosshair;
	
	Crosshair() {
		Crosshairtexture.loadFromFile("crosshair.png");
		crosshair.setTexture(Crosshairtexture);
		crosshair.setOrigin(Crosshairtexture.getSize().x / 2, Crosshairtexture.getSize().y / 2);
	}
};

