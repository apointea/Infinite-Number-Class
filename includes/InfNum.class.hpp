#ifndef INFNUM_CLASS_HPP
# define INFNUM_CLASS_HPP

#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>

class InfNum {

	public:
		// CONSTRUCTORS / DESTRUCTORS
		InfNum(void);
		InfNum(char number);
		InfNum(unsigned char number);
		InfNum(short number);
		InfNum(unsigned short number);
		InfNum(int number);
		InfNum(unsigned int number);
		InfNum(const char *number);
		InfNum(const InfNum &src);
		~InfNum(void);
		// UTILS
		InfNum			invert(void) const;
		InfNum			absolute(void) const;
		// DISPLAY
		std::string		toString(void);
		std::string		toStringSigned(void);
		std::string		toStringScientist(size_t accuracy, bool fill);
		// OPERATORS
		bool			operator==(const InfNum &rhs) const;
		bool			operator>(const InfNum &rhs) const;
		bool			operator<(const InfNum &rhs) const;
		bool			operator>=(const InfNum &rhs) const;
		bool			operator<=(const InfNum &rhs) const;
		InfNum			operator+(const InfNum &rhs);

	protected:
		bool								_sign;
		std::vector<unsigned int>			_unit;
		std::vector<unsigned int>			_deci;

	private:
		int		absolute_compare(const InfNum &rhs) const;
		int		absolute_compare_unit(const InfNum &rhs) const;
		int		absolute_compare_deci(const InfNum &rhs) const;

};

#endif // INFNUM_CLASS_HPP
