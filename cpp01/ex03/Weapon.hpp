#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
public:
	Weapon(std::string type);
	
public:
	std::string getType() const;
	void setType(std::string str);

private:
	std::string type;
};

#endif
