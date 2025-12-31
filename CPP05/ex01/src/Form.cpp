#include "Form.hpp"
#include "libftpp.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) 
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		// Only _isSigned is not const
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << libftpp::DisplayFormatter("Form")
		.add("Name", rhs.getName())
		.add("Signed", rhs.getIsSigned())
		.add("GradeToSign", rhs.getGradeToSign())
		.add("GradeToExecute", rhs.getGradeToExecute());
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const &Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
