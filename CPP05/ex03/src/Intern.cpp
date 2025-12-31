#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { (void)src; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

static AForm *makeShrubbery(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makePresidential(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(*creators[])(std::string const &) = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found!";
}
