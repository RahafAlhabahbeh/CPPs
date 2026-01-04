#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "--- Testing DEBUG ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "--- Testing INFO ---" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "--- Testing WARNING ---" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "--- Testing ERROR ---" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "--- Testing INVALID LEVEL ---" << std::endl;
    harl.complain("I want a refund!");
    harl.complain("42");
    
    return 0;
}