#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class Bureaucrat
{
public:
	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( void );
	Bureaucrat( Bureaucrat& c );
	Bureaucrat& operator=( Bureaucrat& c);
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incGrade( void );
	void		decGrade( void );

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	const std::string		_name;
	int						_grade;

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
