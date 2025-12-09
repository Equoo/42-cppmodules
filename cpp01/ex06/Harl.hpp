#ifndef HARL_HPP
#define HARL_HPP

typedef enum { HARL_DEBUG, HARL_INFO, HARL_WARNING, HARL_ERROR } t_harl_level;

class Harl {
public:
	void	complain(t_harl_level level) const;

private:
	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
};

#endif
