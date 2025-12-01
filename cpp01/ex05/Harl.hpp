#ifndef HARL_HPP
# define HARL_HPP

# include <string>

typedef	enum {
	HARL_DEBUG,
	HARL_INFO,
	HARL_WARNING,
	HARL_ERROR
}	t_harl_level;

class Harl
{
public:
	Harl();
	
public:
	static void	complain(std::string level);

private:
	static void	debug(void);
	static void	info(void);
	static void	warning(void);
	static void	error(void);
};

#endif
