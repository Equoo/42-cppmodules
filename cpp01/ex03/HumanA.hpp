#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const HumanA &copy);
		HumanA(std::string name, Weapon &weapon);
		
	public: // Implementations
		void		attack() const;

	public: // Setters / Getters
		std::string getName() const;
		Weapon 		&getWeapon() const;
		void 		setWeapon(Weapon &weapon);

	private:
		Weapon		&weapon; // is initialized in the constructor
		std::string	name;
};

#endif