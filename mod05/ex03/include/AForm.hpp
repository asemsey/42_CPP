#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
public:
	AForm( const std::string& name, int execGrade, int signGrade );
	AForm( void );
	AForm( AForm& c );
	AForm& operator=( AForm& c);
	virtual ~AForm( void );

	std::string		getName( void ) const;
	bool			isSigned( void ) const;
	int				getSignGrade( void ) const;
	int				getExecGrade( void ) const;
	void			beSigned(Bureaucrat &b);
	virtual void	execute(const Bureaucrat &executor) const = 0;

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class UnsignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &out, const AForm &b);

#endif
