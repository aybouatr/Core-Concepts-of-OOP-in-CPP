# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>



class Weapon
{
	private:
		std::string	_type;

	public:

		Weapon(const std::string &weapon);
		~Weapon();
		std::string getType() const;
		void setType(const std::string &weapon);

};

# endif