#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// Orthodox Canonical Form
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &rhs);

		// Getters
		std::string const	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		// Methods
		void	beSigned(Bureaucrat const &bureaucrat);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
