#include "SFML/Graphics.hpp"
#include "iostream"

using namespace std;
using namespace sf;

int main() {
	RenderWindow v(VideoMode(1600, 1000), "Space");
	v.setFramerateLimit(60);

	Event e;
	Clock reloj;
	Time tiempo;

	CircleShape objeto;
	objeto.setFillColor(Color::Red);
	objeto.setRadius(20);
	objeto.setOrigin(10, 10);
	objeto.setPosition(v.getSize().y/2, v.getSize().x / 2);

	float vel_final = 5.0;
	float vel_x = 0.0;
	float vel_y = 0.0;
	float aceleracion_x = 0.4;
	float aceleracion_y = 0.4;


	while (v.isOpen()) {
		tiempo = reloj.getElapsedTime();//obtienen el tiempo en cada iteracion
		if (objeto.getPosition().x >= v.getSize().x) {//le paso los limites de la pantalla para que no salga
			vel_x = vel_x * (-1);
		}
		if (objeto.getPosition().x <= 10) {
			vel_x = vel_x * (-1);
		}
		if (objeto.getPosition().y >= v.getSize().y) {
			vel_y = vel_y * (-1);
		}
		if (objeto.getPosition().y <= 10) {
			vel_y = vel_y * (-1);
		}
		cout << "velocidad en y " <<vel_y;
		cout << "  velocidad en x " << vel_x << endl;

		objeto.move(vel_x, vel_y);

		while (v.pollEvent(e)){
			if (e.type == Event::KeyPressed) {

				if (e.key.code == Keyboard::Escape) {
					v.close();
				}

				if (e.key.code == Keyboard::A) {
				    if (vel_x >= -vel_final) {
						vel_x = vel_x  - aceleracion_x * (tiempo.asSeconds() / 60);
					}
				}
				if (e.key.code == Keyboard::D) {
					if (vel_x <= vel_final) {
						vel_x = vel_x + aceleracion_x * (tiempo.asSeconds() / 60);
					}
				}
				if (e.key.code == Keyboard::W) {
					if (vel_y >= -vel_final) {
						vel_y = vel_y - aceleracion_y * (tiempo.asSeconds() / 60);
					}
				}
				if (e.key.code == Keyboard::S) {
					if (vel_y <= vel_final) {
						vel_y = vel_y + aceleracion_y * (tiempo.asSeconds() / 60);
					}
				}
			}
		}


		v.clear(Color::Black);
		v.draw(objeto);
		v.display();
	}

	return 0;

}
