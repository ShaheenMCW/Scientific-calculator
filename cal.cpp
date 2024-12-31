#include <iostream>
#include <cmath>
#include <concepts>
#include <limits>
#include <stdexcept>

// Define a concept to ensure the type supports necessary mathematical operations
template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Calculator class template
template <Arithmetic T>
class Calculator
{
public:
    // Constructor
    Calculator(T value = 0) : value(value) {}

    // Set the value
    void setValue(T val)
    {
        value = val;
    }

    // Sine function
    T sin() const
    {
        return std::sin(value);
    }

    // Cosine function
    T cos() const
    {
        return std::cos(value);
    }

    // Tangent function
    T tan() const
    {
        return std::tan(value);
    }

    // Exponential function
    T exp() const
    {
        return std::exp(value);
    }

    // Logarithm function
    T log() const
    {
        if (value <= 0)
        {
            throw std::domain_error("Logarithm is undefined for non-positive values.");
        }
        return std::log(value);
    }

    // Square root function
    T sqrt() const
    {
        if (value < 0)
        {
            throw std::domain_error("Square root is undefined for negative values.");
        }
        return std::sqrt(value);
    }

    // Power function
    T pow(T exponent) const
    {
        return std::pow(value, exponent);
    }

    // Fractional part
    T frac() const
    {
        return value - std::floor(value);
    }

    // Sum function
    T sum(T other) const
    {
        return value + other;
    }

    // Subtraction function
    T subtract(T other) const
    {
        return value - other;
    }

    // Multiplication function
    T multiply(T other) const
    {
        return value * other;
    }

    // Division function
    T divide(T other) const
    {
        if (other == 0)
        {
            throw std::invalid_argument("Division by zero is undefined.");
        }
        return value / other;
    }

private:
    T value;
};

// Function to display the menu
void displayMenu()
{
    std::cout << "\nScientific Calculator Operations:\n";
    std::cout << "1. Sine (sin)\n";
    std::cout << "2. Cosine (cos)\n";
    std::cout << "3. Tangent (tan)\n";
    std::cout << "4. Exponential (exp)\n";
    std::cout << "5. Logarithm (log)\n";
    std::cout << "6. Square Root (sqrt)\n";
    std::cout << "7. Power (pow)\n";
    std::cout << "8. Fractional Part (frac)\n";
    std::cout << "9. Addition (sum)\n";
    std::cout << "10. Subtraction (subtract)\n";
    std::cout << "11. Multiplication (multiply)\n";
    std::cout << "12. Division (divide)\n";
    std::cout << "13. Exit\n";
    std::cout << "Select an operation (1-13): ";
}

// Function to get a valid number from the user
template <typename T>
T getValidNumber(const std::string &prompt)
{
    T num;
    while (true)
    {
        std::cout << prompt;
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any extra input
            return num;
        }
    }
}

int main()
{
    Calculator<double> calc;
    int choice;

    while (true)
    {
        displayMenu();
        std::cin >> choice;

        if (choice == 13)
        {
            std::cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        double value = 0, operand = 0, result = 0;
        bool unaryOperation = false;

        try
        {
            switch (choice)
            {
            case 1: // Sine
                value = getValidNumber<double>("Enter the value (in radians) for sine: ");
                calc.setValue(value);
                result = calc.sin();
                unaryOperation = true;
                break;
            case 2: // Cosine
                value = getValidNumber<double>("Enter the value (in radians) for cosine: ");
                calc.setValue(value);
                result = calc.cos();
                unaryOperation = true;
                break;
            case 3: // Tangent
                value = getValidNumber<double>("Enter the value (in radians) for tangent: ");
                calc.setValue(value);
                result = calc.tan();
                unaryOperation = true;
                break;
            case 4: // Exponential
                value = getValidNumber<double>("Enter the value for exponential: ");
                calc.setValue(value);
                result = calc.exp();
                unaryOperation = true;
                break;
            case 5: // Logarithm
                value = getValidNumber<double>("Enter the value for logarithm: ");
                calc.setValue(value);
                result = calc.log();
                unaryOperation = true;
                break;
            case 6: // Square Root
                value = getValidNumber<double>("Enter the value for square root: ");
                calc.setValue(value);
                result = calc.sqrt();
                unaryOperation = true;
                break;
            case 7: // Power
                value = getValidNumber<double>("Enter the base value: ");
                operand = getValidNumber<double>("Enter the exponent value: ");
                calc.setValue(value);
                result = calc.pow(operand);
                break;
            case 8: // Fractional Part
                value = getValidNumber<double>("Enter the value to get its fractional part: ");
                calc.setValue(value);
                result = calc.frac();
                unaryOperation = true;
                break;
            case 9: // Addition
                value = getValidNumber<double>("Enter the first number: ");
                operand = getValidNumber<double>("Enter the second number: ");
                calc.setValue(value);
                result = calc.sum(operand);
                break;
            case 10: // Subtraction
                value = getValidNumber<double>("Enter the first number: ");
                operand = getValidNumber<double>("Enter the second number: ");
                calc.setValue(value);
                result = calc.subtract(operand);
                break;
            case 11: // Multiplication
                value = getValidNumber<double>("Enter the first number: ");
                operand = getValidNumber<double>("Enter the second number: ");
                calc.setValue(value);
                result = calc.multiply(operand);
                break;
            case 12: // Division
                value = getValidNumber<double>("Enter the dividend: ");
                operand = getValidNumber<double>("Enter the divisor: ");
                calc.setValue(value);
                result = calc.divide(operand);
                break;
            default:
                std::cout << "Invalid selection. Please choose a valid operation.\n";
                continue;
            }

            // Display the result
            if (unaryOperation)
            {
                std::cout << "Result: " << result << "\n";
            }
            else
            {
                std::cout << "Result: " << result << "\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
