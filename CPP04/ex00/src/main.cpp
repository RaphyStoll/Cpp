#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
	std::cout << "\n========== Test 1: Basic instantiation ==========\n" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n========== Test 2: Stack allocation ==========\n" << std::endl;
	{
		Animal animal;
		Dog dog;
		Cat cat;
		
		std::cout << "\nAnimal type: " << animal.getType() << std::endl;
		animal.makeSound();
		
		std::cout << "\nDog type: " << dog.getType() << std::endl;
		dog.makeSound();
		
		std::cout << "\nCat type: " << cat.getType() << std::endl;
		cat.makeSound();
		
		std::cout << "\nEnd of scope:" << std::endl;
	}

	std::cout << "\n========== Test 3: Array of Animals ==========\n" << std::endl;
	{
		Animal* animals[6];
		
		std::cout << "Creating 3 Dogs and 3 Cats:\n" << std::endl;
		for (int i = 0; i < 3; i++)
			animals[i] = new Dog();
		for (int i = 3; i < 6; i++)
			animals[i] = new Cat();
		
		std::cout << "\nMaking all animals sound:" << std::endl;
		for (int i = 0; i < 6; i++) {
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		
		std::cout << "\nDeleting all animals:" << std::endl;
		for (int i = 0; i < 6; i++)
			delete animals[i];
	}

	std::cout << "\n========== Test 4: Copy constructor ==========\n" << std::endl;
	{
		Dog originalDog;
		Dog copyDog(originalDog);
		
		std::cout << "\nOriginal dog: ";
		originalDog.makeSound();
		std::cout << "Copied dog: ";
		copyDog.makeSound();
		
		std::cout << "\nEnd of scope:" << std::endl;
	}

	std::cout << "\n========== Test 5: Assignment operator ==========\n" << std::endl;
	{
		Cat cat1;
		Cat cat2;
		
		std::cout << "\nBefore assignment:" << std::endl;
		cat1.makeSound();
		cat2.makeSound();
		
		std::cout << "\nAssigning cat1 to cat2:" << std::endl;
		cat2 = cat1;
		
		std::cout << "\nAfter assignment:" << std::endl;
		cat1.makeSound();
		cat2.makeSound();
		
		std::cout << "\nEnd of scope:" << std::endl;
	}

	std::cout << "\n========== Test 6: Polymorphism ==========\n" << std::endl;
	{
		Animal* ptr;
		
		std::cout << "Testing with Dog:" << std::endl;
		ptr = new Dog();
		std::cout << "Type: " << ptr->getType() << std::endl;
		ptr->makeSound();
		delete ptr;
		
		std::cout << "\nTesting with Cat:" << std::endl;
		ptr = new Cat();
		std::cout << "Type: " << ptr->getType() << std::endl;
		ptr->makeSound();
		delete ptr;
		
		std::cout << "\nTesting with Animal:" << std::endl;
		ptr = new Animal();
		std::cout << "Type: " << ptr->getType() << std::endl;
		ptr->makeSound();
		delete ptr;
	}

	std::cout << "\n========== All tests completed! ==========\n" << std::endl;
	return 0;
}
