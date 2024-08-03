#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>

struct Data {
	std::string	str;
};

class Serializer
{
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer( void );
	Serializer( Serializer& c );
	Serializer& operator=( Serializer& c);
	~Serializer( void );

};

#endif
