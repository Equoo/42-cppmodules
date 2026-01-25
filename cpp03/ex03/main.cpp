 // ANSI escape codes for terminal colors
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bright/bold colors
#define BOLD_BLACK   "\033[1;30m"
#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"

// Background colors
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

#define PARENS ()

#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

#define FOR_EACH(macro, ...)                                    \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...)                         \
  macro(a1)                                                     \
  __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define ADDTOSTREAM(x) << x
#define PRINTLN(...) std::cout << "[TEST] " FOR_EACH(ADDTOSTREAM, __VA_ARGS__) << std::endl

#define TEST_TITLE(x) PRINTLN(BOLD_BLUE, "------------ ", x, " ------------", RESET)


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <streambuf>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void	test_claptrap() {
	ClapTrap	paul(string("Paul"));
	string		ennemy("ennemy");

	TEST_TITLE("ClapTrap default");
	PRINTLN(paul, " HitPoints: ", paul.getHitPoints());
	PRINTLN(paul, " EnergyPoints: ", paul.getEnergyPoints());
	PRINTLN(paul, " AttackDamage: ", paul.getAttackDamage());

	TEST_TITLE("Attack");
	paul.attack(ennemy);

	TEST_TITLE("SetAttackDamage(23)");
	paul.setAttackDamage(23);
	PRINTLN(paul, " AttackDamage: ", paul.getAttackDamage());
	paul.attack(ennemy);

	TEST_TITLE("TakeDamage(9)");
	paul.takeDamage(9);
	PRINTLN(paul, " HitPoints: ", paul.getHitPoints());
	
	TEST_TITLE("beRepaired(9)");
	paul.beRepaired(9);
	PRINTLN(paul, " HitPoints: ", paul.getHitPoints());

	TEST_TITLE("Energy empty");
	std::streambuf *old = cout.rdbuf(0); // Redirect STDOUT to hide printing.
	for (int i = 0; i < 7; i++)
		paul.beRepaired(1);
	cout.rdbuf(old);
	PRINTLN(paul, " EnergyPoints: ", paul.getEnergyPoints());
	paul.beRepaired(1);
	paul.attack(ennemy);
	paul.takeDamage(1);

	TEST_TITLE("HitPoints empty");
	ClapTrap	mehdi(string("Mehdi"));

	PRINTLN(mehdi, " HitPoints: ", mehdi.getHitPoints());
	PRINTLN(mehdi, " EnergyPoints: ", mehdi.getEnergyPoints());
	PRINTLN(mehdi, " AttackDamage: ", mehdi.getAttackDamage());
	mehdi.attack(ennemy);
	mehdi.beRepaired(1);
	mehdi.takeDamage(11);
	PRINTLN(mehdi, " HitPoints: ", mehdi.getHitPoints());
	mehdi.attack(ennemy);
	mehdi.beRepaired(10);
	mehdi.takeDamage(10);
}

void	test_scavtrap() {
	ScavTrap	noam(string("Noam"));

	TEST_TITLE("ScavTrap default");
	PRINTLN("Noam HitPoints: ", noam.getHitPoints());
	PRINTLN("Noam EnergyPoints: ", noam.getEnergyPoints());
	PRINTLN("Noam AttackDamage: ", noam.getAttackDamage());

	TEST_TITLE("Attack");
	noam.attack("Zakhian");

	TEST_TITLE("GuardGate");
	noam.guardGate();
}

void	test_fragtrap() {
	FragTrap	feur(string("Feur"));

	TEST_TITLE("FragTrap default");
	PRINTLN(feur, " HitPoints: ", feur.getHitPoints());
	PRINTLN(feur, " EnergyPoints: ", feur.getEnergyPoints());
	PRINTLN(feur, " AttackDamage: ", feur.getAttackDamage());

	TEST_TITLE("Attack");
	feur.attack("Zakhian");

	TEST_TITLE("HighFivesGuys");
	feur.highFivesGuys();
}

void	test_diamondtrap() {
	DiamondTrap	diamond(string("Diamond"));

	TEST_TITLE("FragTrap default");
	PRINTLN(diamond, " HitPoints: ", diamond.getHitPoints());
	PRINTLN(diamond, " EnergyPoints: ", diamond.getEnergyPoints());
	PRINTLN(diamond, " AttackDamage: ", diamond.getAttackDamage());

	TEST_TITLE("Attack");
	diamond.attack("ZakhianEcureuil");

	TEST_TITLE("GuardGate");
	diamond.guardGate();

	TEST_TITLE("HighFivesGuys");
	diamond.highFivesGuys();

	TEST_TITLE("WhoAmI");
	diamond.whoAmI();
}

int main( void ) {
	PRINTLN(BOLD_MAGENTA, "============ ClapTrap =============", RESET);
	test_claptrap();
	PRINTLN();
	PRINTLN(BOLD_MAGENTA, "============ ScavTrap =============", RESET);
	test_scavtrap();
	PRINTLN();
	PRINTLN(BOLD_MAGENTA, "============ FragTrap =============", RESET);
	test_fragtrap();
	PRINTLN();
	PRINTLN(BOLD_MAGENTA, "============ DiamondTrap =============", RESET);
	test_diamondtrap();

	return (0);
}

