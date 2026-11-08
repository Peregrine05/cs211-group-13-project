#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number;

    cout << "Luhn Checksum Validator" << endl;
    cout << "Enter a 16-digit number: ";
    cin >> number;

    // Check that the number has exactly 16 digits
    if (number.length() != 16)
    {
        cout << "Invalid input: Number must contain exactly 16 digits." << endl;
        return 0;
    }

    // Check that every character is a digit
    for (int i = 0; i < 16; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            cout << "Invalid input: Only digits are allowed." << endl;
            return 0;
        }
    }

    // Calculate the Luhn checksum
    int sum = 0;
    bool doubleDigit = false;

    for (int i = 15; i >= 0; i--)
    {
        int digit = number[i] - '0';

        if (doubleDigit)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    // Check whether the checksum is divisible by 10
    if (sum % 10 == 0)
    {
        cout << "Valid Luhn checksum!" << endl;
    }
    else
    {
        cout << "Invalid Luhn checksum!" << endl;
    }

    return 0;
}
