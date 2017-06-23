#include <string>
#include <cstring>

// implicit constructor, kola tworza sie z losowa wartoscia
// parametru size
class Wheel {
public:
	unsigned int size;
};

class Vehicle {
	const char * name;
public:
	// brak konstruktora kopiujacego, shallow copy
	// brak operatora przypisania, shallow copy
	// od biedy obiekt
	Vehicle(const char * name) {
		// std::strlen zwraca dlugosc bez nulla
		// dac std::strlen(name) + 1 albo sizeof(name)
		this->name = new char[std::strlen(name)];
		// strcpy przy za krotkim this->name daje
		// undefined behavior
		std::strcpy(this->name, name);
	}

	// zwracanie referencji do rvalue
	std::string & getName() const { return std::string(name); }
	
	// raw pointer w klasie, brak destruktora, memory leak
	// istnieje klasa dziedziczaca, brak wirtualnego destruktora
	// daje to undefined behavior przy 
	// Vehicle * foo = new Car();
	// delete foo;
};

// raw pointer w klasie, rule of 3 nie zachowane, shallow copy
// destruktor zadeklarowany, obiekt nie jest "movable"
class Car: public Vehicle {
	Wheel * wheels;
public:

	// od biedy skoro liczba kol jest stala nie ma potrzeby tworzyc dynamicznie
	Car() {
		wheels = new Wheel[4];
	}

	~Car() {
		// bledny typ destruktora (tworzona jest tablica)
		delete wheels;
	}
};

