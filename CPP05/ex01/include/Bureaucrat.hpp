#pragma once

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string const	&getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(class Form &form);

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
