# include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Tiago",0); // This should throw a GradeTooHighException
        // If the exception is not thrown, the test fails
        std::cout << "Test failed: No exception thrown for grade 0\n";
        std::cout << b << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        // If the exception is thrown, the test passes
        std::cout << "Test passed: Exception thrown for grade 0\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }

    try {
        Bureaucrat b("Victor", 1); // This should not throw an exception
        // If the exception is not thrown, the test passes
        std::cout << "Test passed: No exception thrown for grade 1\n";
        std::cout << b << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        // If the exception is thrown, the test fails
        std::cout << "Test failed: Exception thrown for grade 1\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }

    try {
        Bureaucrat c("Vasco", 151); // This should not throw an exception
        // If the exception is not thrown, the test passes
        std::cout << "Test passed: No exception thrown for grade 151\n";
        std::cout << c << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        // If the exception is thrown, the test fails
        std::cout << "Test failed: Exception thrown for grade 151\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }
    return 0;
}
