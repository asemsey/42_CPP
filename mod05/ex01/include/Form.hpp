#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
public:
	Form( const std::string& name, int execGrade, int signGrade );
	Form( void );
	Form( Form& c );
	Form& operator=( Form& c);
	~Form( void );

	std::string	getName( void ) const;
	bool		isSigned( void ) const;
	int			getSignGrade( void ) const;
	int			getExecGrade( void ) const;
	void		beSigned(Bureaucrat &b);

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &out, const Form &b);

#endif
