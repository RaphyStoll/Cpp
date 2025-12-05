#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

int main()
{
	std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║        EXERCICE 02: CLASSE ABSTRAITE (ABSTRACT CLASS)      ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════╝\n" << std::endl;

	std::cout << "📚 EXPLICATION:" << std::endl;
	std::cout << "Animal est maintenant une CLASSE ABSTRAITE (abstract class)." << std::endl;
	std::cout << "Cela signifie qu'on ne peut PAS créer d'instance Animal directement." << std::endl;
	std::cout << "Pourquoi? Parce que makeSound() est une fonction virtuelle PURE (= 0).\n" << std::endl;

	std::cout << "❌ Ce code ne compilerait PAS:" << std::endl;
	std::cout << "   Animal a;  // ERREUR: cannot declare variable 'a' to be of abstract type 'Animal'" << std::endl;
	std::cout << "   Animal* ptr = new Animal();  // ERREUR!\n" << std::endl;

	std::cout << "✅ Mais on peut toujours utiliser Animal comme POINTEUR ou RÉFÉRENCE:" << std::endl;
	std::cout << "   Animal* ptr = new Dog();  // OK! Polymorphisme\n" << std::endl;

	std::cout << "\n========== Test 1: Subject example (no leak test) ==========\n" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "\nDeleting animals (should not create a leak):" << std::endl;
		delete j;
		delete i;
	}

	std::cout << "\n========== Test 2: Array of Animals (half Dogs, half Cats) ==========\n" << std::endl;
	{
		const int arraySize = 10;
		Animal* animals[arraySize];
		
		std::cout << "Creating " << arraySize/2 << " Dogs:\n" << std::endl;
		for (int i = 0; i < arraySize/2; i++) {
			animals[i] = new Dog();
		}
		
		std::cout << "\nCreating " << arraySize/2 << " Cats:\n" << std::endl;
		for (int i = arraySize/2; i < arraySize; i++) {
			animals[i] = new Cat();
		}
		
		std::cout << "\nAll animals make sound:" << std::endl;
		for (int i = 0; i < arraySize; i++) {
			std::cout << "\nAnimal[" << i << "] is a " << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		
		std::cout << "\nDeleting all animals as Animal* (proper destructors should be called):\n" << std::endl;
		for (int i = 0; i < arraySize; i++) {
			std::cout << "Deleting animal[" << i << "]:" << std::endl;
			delete animals[i];
			std::cout << std::endl;
		}
	}

	std::cout << "\n========== Test 3: Deep copy with Dog ==========\n" << std::endl;
	{
		std::cout << "Creating original Dog:" << std::endl;
		Dog* originalDog = new Dog();
		
		std::cout << "\nSetting ideas in original dog's brain:" << std::endl;
		originalDog->getBrain()->setIdea(0, "I love bones!");
		originalDog->getBrain()->setIdea(1, "I want to play fetch!");
		originalDog->getBrain()->setIdea(2, "Where is my human?");
		
		std::cout << "\nOriginal Dog's ideas:" << std::endl;
		std::cout << "  Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "  Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
		std::cout << "  Idea 2: " << originalDog->getBrain()->getIdea(2) << std::endl;
		
		std::cout << "\nCreating copy of Dog:" << std::endl;
		Dog* copiedDog = new Dog(*originalDog);
		
		std::cout << "\nCopied Dog's ideas (should be the same):" << std::endl;
		std::cout << "  Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "  Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;
		std::cout << "  Idea 2: " << copiedDog->getBrain()->getIdea(2) << std::endl;
		
		std::cout << "\nModifying original dog's idea 0:" << std::endl;
		originalDog->getBrain()->setIdea(0, "I love STEAKS now!");
		
		std::cout << "\nOriginal Dog's idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog's idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "(If different, deep copy works! ✓)" << std::endl;
		
		std::cout << "\nComparing Brain addresses:" << std::endl;
		std::cout << "  Original Brain*: " << originalDog->getBrain() << std::endl;
		std::cout << "  Copied Brain*:   " << copiedDog->getBrain() << std::endl;
		std::cout << "  (Should be DIFFERENT addresses for deep copy! ✓)" << std::endl;
		
		std::cout << "\nDeleting dogs:" << std::endl;
		delete originalDog;
		delete copiedDog;
	}

	std::cout << "\n========== Test 4: Deep copy with Cat ==========\n" << std::endl;
	{
		std::cout << "Creating original Cat:" << std::endl;
		Cat originalCat;
		
		std::cout << "\nSetting ideas in original cat's brain:" << std::endl;
		originalCat.getBrain()->setIdea(0, "I am the boss here");
		originalCat.getBrain()->setIdea(1, "Feed me NOW!");
		originalCat.getBrain()->setIdea(2, "Maybe I'll sit on your keyboard");
		
		std::cout << "\nOriginal Cat's ideas:" << std::endl;
		std::cout << "  Idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
		std::cout << "  Idea 2: " << originalCat.getBrain()->getIdea(2) << std::endl;
		
		std::cout << "\nCreating copy of Cat:" << std::endl;
		Cat copiedCat(originalCat);
		
		std::cout << "\nCopied Cat's ideas (should be the same):" << std::endl;
		std::cout << "  Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
		std::cout << "  Idea 2: " << copiedCat.getBrain()->getIdea(2) << std::endl;
		
		std::cout << "\nModifying original cat's idea 1:" << std::endl;
		originalCat.getBrain()->setIdea(1, "Actually, I'm not hungry anymore");
		
		std::cout << "\nOriginal Cat's idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
		std::cout << "Copied Cat's idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
		std::cout << "(If different, deep copy works! ✓)" << std::endl;
		
		std::cout << "\nComparing Brain addresses:" << std::endl;
		std::cout << "  Original Brain*: " << originalCat.getBrain() << std::endl;
		std::cout << "  Copied Brain*:   " << copiedCat.getBrain() << std::endl;
		std::cout << "  (Should be DIFFERENT addresses for deep copy! ✓)" << std::endl;
		
		std::cout << "\nEnd of scope (automatic deletion):" << std::endl;
	}

	std::cout << "\n========== Test 5: Assignment operator (deep copy) ==========\n" << std::endl;
	{
		std::cout << "Creating Dog1:" << std::endl;
		Dog dog1;
		dog1.getBrain()->setIdea(0, "Dog1's idea");
		
		std::cout << "\nCreating Dog2:" << std::endl;
		Dog dog2;
		dog2.getBrain()->setIdea(0, "Dog2's idea");
		
		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "  Dog1's idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Dog2's idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Dog1's Brain*: " << dog1.getBrain() << std::endl;
		std::cout << "  Dog2's Brain*: " << dog2.getBrain() << std::endl;
		
		std::cout << "\nAssigning dog1 to dog2:" << std::endl;
		dog2 = dog1;
		
		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "  Dog1's idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Dog2's idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Dog1's Brain*: " << dog1.getBrain() << std::endl;
		std::cout << "  Dog2's Brain*: " << dog2.getBrain() << std::endl;
		std::cout << "  (Brain addresses should be DIFFERENT! ✓)" << std::endl;
		
		std::cout << "\nModifying dog1's idea:" << std::endl;
		dog1.getBrain()->setIdea(0, "Dog1's NEW idea");
		
		std::cout << "\nAfter modification:" << std::endl;
		std::cout << "  Dog1's idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "  Dog2's idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "  (Should be DIFFERENT! ✓)" << std::endl;
		
		std::cout << "\nEnd of scope:" << std::endl;
	}

	std::cout << "\n========== Test 6: Testing all 100 ideas ==========\n" << std::endl;
	{
		Dog smartDog;
		
		std::cout << "Filling dog's brain with 100 ideas:" << std::endl;
		for (int i = 0; i < 100; i++) {
			std::string idea = "Idea number ";
			idea += static_cast<char>('0' + (i / 10));
			idea += static_cast<char>('0' + (i % 10));
			smartDog.getBrain()->setIdea(i, idea);
		}
		
		std::cout << "First 5 ideas:" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << "  " << smartDog.getBrain()->getIdea(i) << std::endl;
		}
		
		std::cout << "Last 5 ideas:" << std::endl;
		for (int i = 95; i < 100; i++) {
			std::cout << "  " << smartDog.getBrain()->getIdea(i) << std::endl;
		}
		
		std::cout << "\nEnd of scope:" << std::endl;
	}

	std::cout << "\n========== All tests completed! ==========\n" << std::endl;
	std::cout << "✅ Check for memory leaks with: valgrind --leak-check=full ./brain\n" << std::endl;
	
	return 0;
}
