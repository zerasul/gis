#include <Arduino.h>


class Matriz {
 
	private:

		byte pines[7];
		byte lacht1;
		byte lacht2;

		void display(boolean, boolean, boolean, boolean, boolean, boolean, 
			boolean);
		void escribirDisplay(byte);

	public:

		Matriz(byte,byte,byte, byte, byte,byte,byte, byte ,byte);
		~Matriz();

		void escribir(byte);
		void transicion(byte);
};
