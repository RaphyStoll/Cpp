#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(const Zombie& other);
		Zombie(const std::string& name); //constructeur avec setter pour name
		Zombie& operator=(const Zombie& other);
		~Zombie();

		void setName(const std::string& str);
		const std::string& getName() const;

		void announce(void);
	};
	Zombie* newZombie(std::string name);
	void randomChump(std::string name);
