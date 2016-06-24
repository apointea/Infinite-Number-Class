#include <InfNum.class.hpp>

InfNum::InfNum(void) : _sign(true)
{
	this->_unit.push_back(0);
}
InfNum::InfNum(char number)
{
	this->_sign = true;
	if (number < 0)
	{
		this->_sign = false;
		number = -number;
	}
	this->_unit.push_back((unsigned int)number);
}
InfNum::InfNum(unsigned char number) : _sign(true)
{
	this->_unit.push_back((unsigned int)number);
}
InfNum::InfNum(short number)
{
	this->_sign = true;
	if (number < 0)
	{
		this->_sign = false;
		number = -number;
	}
	this->_unit.push_back((unsigned int)number);
}
InfNum::InfNum(unsigned short number) : _sign(true)
{
	this->_unit.push_back((unsigned int)number);
}
InfNum::InfNum(int number)
{
	this->_sign = true;
	if (number < 0)
	{
		this->_sign = false;
		number = -number;
	}
	this->_unit.push_back((unsigned int)number);
}
InfNum::InfNum(unsigned int number) : _sign(true)
{
	this->_unit.push_back(number);
}
InfNum::InfNum(const char *number)
{
	int		value;

	value = atoi(number);
	this->_sign = true;
	if (value < 0)
	{
		this->_sign = false;
		value = -value;
	}
	this->_unit.push_back((unsigned int)value);
}
InfNum::InfNum(const InfNum &src) : _sign(src._sign), _unit(src._unit), _deci(src._deci)
{
}
InfNum::~InfNum(void)
{
}
/*
**	TOOLS
*/
int					InfNum::absolute_compare(const InfNum &rhs) const
{
	int			ret;

	if ((ret = this->absolute_compare_unit(rhs)))
		return (ret);
	ret = this->absolute_compare_deci(rhs);
	return (ret);
}
int					InfNum::absolute_compare_unit(const InfNum &rhs) const
{
	const std::vector<unsigned int>		*left;
	const std::vector<unsigned int>		*right;
	size_t								it;
	size_t								l_size;
	size_t								r_size;


	left = &this->_unit;
	right = &rhs._unit;
	l_size = left->size();
	r_size = right->size();
	if (l_size > r_size)
		return (1);
	if (l_size < r_size)
		return (-1);
	it = 0;
	while (it < l_size)
	{
		if ((*left)[it] > (*right)[it])
			return (1);
		if ((*left)[it] < (*right)[it])
			return (-1);
		it++;
	}
	return (0);
}
int					InfNum::absolute_compare_deci(const InfNum &rhs) const
{
	const std::vector<unsigned int>		*left;
	const std::vector<unsigned int>		*right;
	size_t								it;
	size_t								size;

	left = &this->_deci;
	right = &rhs._deci;
	size = (left->size() > right->size()) ? right->size() : left->size();
	it = 0;
	while (it < size)
	{
		if ((*left)[it] > (*right)[it])
			return (1);
		if ((*left)[it] < (*right)[it])
			return (-1);
		it++;
	}
	if (size < left->size())
		return (1);
	if (size < right->size())
		return (-1);
	return (0);
}

/*
**	UTILS
*/
InfNum				InfNum::invert(void) const
{
	InfNum			newInst(*this);

	newInst._sign = !(this->_sign);
	return (newInst);
}
InfNum				InfNum::absolute(void) const
{
	InfNum			newInst(*this);

	newInst._sign = true;
	return (newInst);
}

/*
**	DISPLAY
*/
std::string			InfNum::toString(void)
{
	std::ostringstream		out;
	size_t					it;
	size_t					size;

	size = this->_unit.size();
	it = 0;
	if (!this->_sign)
		out << "-";
	while (it < size)
	{
		out << this->_unit[it];
		it++;
	}
	return (out.str());
}
std::string			InfNum::toStringSigned(void)
{
	std::ostringstream		out;
	size_t					it;
	size_t					size;

	size = this->_unit.size();
	it = 0;
	if (!this->_sign)
		out << "-";
	else
		out << "+";
	while (it < size)
	{
		out << this->_unit[it];
		it++;
	}
	return (out.str());
}


/*
**	OPERATORS
*/
bool				InfNum::operator>(const InfNum &rhs) const
{
	int				cmp;

	if (this->_sign != rhs._sign)
		return (this->_sign);
	cmp = this->absolute_compare(rhs);
	if (this->_sign == true)
		return (cmp > 0);
	return (cmp < 0);
}
bool				InfNum::operator<(const InfNum &rhs) const
{
	if ((*this) == rhs)
		return (false);
	return (!((*this) > rhs));
}
bool				InfNum::operator==(const InfNum &rhs) const
{
	return (this->_sign == rhs._sign && this->absolute_compare(rhs) == 0);
}
bool				InfNum::operator>=(const InfNum &rhs) const
{
	return (!((*this) < rhs));
}
bool				InfNum::operator<=(const InfNum &rhs) const
{
	return (!((*this) > rhs));
}

/*
InfNum			InfNum::operator+(const InfNum &rhs)
{
	InfNum		res = new InfNum();

	if ()

}
*/
