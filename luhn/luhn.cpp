#include <iostream>
#include <string>
using namespace std;

// Check that the input contains exactly 16 digits
bool validInput(string number)
{
    if (number.length() != 16)
    {
        return false;
    }

    for (int i = 0; i < 16; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return false;
        }
    }

    return true;
}

// Calculate the Luhn checksum
bool checkLuhn(string number)
{
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

    return sum % 10 == 0;
}

int main()
{
    string number;
    int choice;

    cout << "Luhn Checksum Validator" << endl;

    while (true)
    {
        cout << "\n1. Check a 16-digit number" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            if (cin.eof())
            {
                break;
            }

            cout << "Invalid choice. Please enter 1 or 2." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 2)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (choice == 1)
        {
            cout << "Enter a 16-digit number: ";

            if (!(cin >> number))
            {
                break;
            }

            if (!validInput(number))
            {
                cout << "Invalid input: Enter exactly 16 digits." << endl;
            }
            else if (checkLuhn(number))
            {
                cout << "Valid Luhn checksum!" << endl;
            }
            else
            {
                cout << "Invalid Luhn checksum!" << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }

    return 0;
}
