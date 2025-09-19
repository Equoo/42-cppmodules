#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const HumanB &copy);
		HumanB(std::string name);
		
	public: // Implementations
		void		attack() const;

	public: // Setters / Getters
		std::string getName() const;
		Weapon 		*getWeapon() const;
		void 		setWeapon(Weapon &weapon);

	private:
		Weapon		*weapon; // isn't initialized in the constructor so can be NULL
		std::string	name;
};

#endif