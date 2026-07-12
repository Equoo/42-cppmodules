#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <deque>

class RPN
{
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        long evaluate(const std::string& expression);

    private:
        std::deque<long> _stack;

        void processToken(const std::string& token);
        bool isOperator(const std::string& token) const;
        void applyOperator(const std::string& op);
        long popOperand();
};

#endif
