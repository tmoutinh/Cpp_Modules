/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:39:17 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/15 16:00:48 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main() {
    try {
        Bureaucrat b("Vasco", 0); // This should throw a GradeTooHighException
        std::cout << "Test failed: No exception thrown for grade 0\n";
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Test passed: Exception thrown for grade 0\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }

    try {
        Bureaucrat b("Pinto", 1); // This should not throw an exception
        std::cout << "Test passed: No exception thrown for grade 1\n";
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Test failed: Exception thrown for grade 1\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }

    try {
        Bureaucrat b("Cheedar", 4);
        Form f("Form", 159, 159); // This should throw a GradeTooHighException
        std::cout << "Test passed: No exception thrown for signing form\n";
        f.beSigned(b); // This should not throw an exception
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Test failed: Exception thrown for form\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }
    catch (const Form::GradeTooHighException& e) {
        std::cout << "Test failed: Exception thrown for form\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Test failed: Exception thrown for signing form\n";
        std::cout << "Exception message: " << e.what() << '\n';
    }
    return 0;
}