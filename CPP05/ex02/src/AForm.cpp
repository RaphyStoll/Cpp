#include "AForm.hpp"
#include "libftpp.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) 
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << libftpp::DisplayFormatter("AForm")
		.add("Name", rhs.getName())
		.add("Signed", rhs.getIsSigned())
		.add("GradeToSign", rhs.getGradeToSign())
		.add("GradeToExecute", rhs.getGradeToExecute());
	return o;
}

std::string const &AForm::getName() const { return this->_name; }

bool AForm::getIsSigned() const { return this->_isSigned; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high!"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low!"; }
const char *AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }
