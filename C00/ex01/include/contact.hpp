#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

// === mini norm ===
// classe = UpperCamelCase
// fonction = CamelCase
// variable = snake_case

class Contact {
	private :
		std::string first_name; // prenom
		std::string last_name; // nom
		std::string nick_name; // surnom
		std::string phone_number;
		std::string darkest_secret; //secret sombre
	
	public :
		//regle de 3 sur la classe (constructeur, copie, destructeur)
		Contact();	// declaration de la classe a l'init (constructeur)
		Contact(const Contact& other); // copie
		~Contact(); //destructeur (ici vide car rien a delet (free))

		// declaration de fonction de la classe
		void	setFirstName(const std::string& str);
		void	setLastName(const std::string& str);
		void   	setNickName(const std::string& str);
		void	setPhoneNumber(const std::string& str);
		void	setDarkestSecret(const std::string& str);

		const std::string&	getFirstName() const;
		const std::string&	getLastName() const;
		const std::string&	getNickName() const;
		const std::string&	getDarkestSecret() const;
		int					getOldestIndex();

		bool isEmpty() const;
};

#endif