#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>

void temp()
{
    int option;
    double input, result;
    char again;

    do
    {
        printf("\n\n--- Temperature Converter ---\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("\nChoose your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            result = (input * 9 / 5) + 32;
            printf("Temperature in Fahrenheit: %.2lf\n", result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            result = (input - 32) * 5 / 9;
            printf("Temperature in Celsius: %.2lf\n", result);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            result = input + 273.15;
            printf("Temperature in Kelvin: %.2lf\n", result);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &input);
            result = input - 273.15;
            printf("Temperature in Celsius: %.2lf\n", result);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            result = (input - 32) * 5 / 9 + 273.15;
            printf("Temperature in Kelvin: %.2lf\n", result);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &input);
            result = (input - 273.15) * 9 / 5 + 32;
            printf("Temperature in Fahrenheit: %.2lf\n", result);
            break;
        default:
            printf("Invalid Option.\n");
            break;
        }

        printf("\nDo you want to perform another temperature conversion? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThank you for using the Temperature Converter!\n");
}

void Length()
{
    int i, j;
    double input, result;
    char again;

    const char *units[8] = {
        "Millimeters (mm)",
        "Centimeters (cm)",
        "Meters (m)",
        "Kilometers (km)",
        "Inches (in)",
        "Feet (ft)",
        "Yards (yd)",
        "Miles (mi)"};
    double to_meter[8] = {
        0.001,  // mm
        0.01,   // cm
        1.0,    // m
        1000.0, // km
        0.0254, // in
        0.3048, // ft
        0.9144, // yd
        1609.34 // mi
    };

    do
    {
        printf("\n--- Length Converter ---\n\n");
        for (i = 0; i < 8; i++)
        {
            printf("%d. %s\n", i + 1, units[i]);
        }

        printf("\nChoose source unit number: ");
        scanf("%d", &i);
        if (i < 1 || i > 8)
        {
            printf("Invalid source unit.\n");
            continue;
        }

        printf("Choose target unit number: ");
        scanf("%d", &j);
        if (j < 1 || j > 8)
        {
            printf("Invalid target unit.\n");
            continue;
        }

        printf("Enter length in %s: ", units[i - 1]);
        scanf("%lf", &input);

        result = input * to_meter[i - 1] / to_meter[j - 1];

        printf("\n%.6lf %s = %.6lf %s\n", input, units[i - 1], result, units[j - 1]);

        printf("\nDo you want to perform another length conversion? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThank you for using the Length Converter!\n");
}

void Currency()
{
    int i, j;
    double input, result;
    char again;

    const char *currencies[50] = {
        "USD", "EUR", "GBP", "JPY", "AUD", "CAD", "CHF", "CNY", "INR", "BDT",
        "SGD", "NZD", "HKD", "KRW", "MYR", "THB", "VND", "PHP", "IDR", "AED",
        "SAR", "KWD", "QAR", "BHD", "OMR", "TRY", "RUB", "ZAR", "NOK", "SEK",
        "DKK", "PLN", "CZK", "HUF", "ILS", "MXN", "BRL", "ARS", "CLP", "COP",
        "EGP", "PKR", "LKR", "NGN", "KES", "TWD", "MAD", "UAH", "RON", "HRK"};

    double usd_rate[50] = {
        1.0,     // USD
        0.93,    // EUR
        0.82,    // GBP
        148.0,   // JPY
        1.44,    // AUD
        1.36,    // CAD
        0.91,    // CHF
        7.2,     // CNY
        83.0,    // INR
        110.0,   // BDT
        1.34,    // SGD
        1.57,    // NZD
        7.8,     // HKD
        1300.0,  // KRW
        4.6,     // MYR
        35.0,    // THB
        24000.0, // VND
        55.0,    // PHP
        15200.0, // IDR
        3.67,    // AED
        3.75,    // SAR
        0.31,    // KWD
        3.64,    // QAR
        0.38,    // BHD
        0.38,    // OMR
        32.0,    // TRY
        92.0,    // RUB
        18.0,    // ZAR
        10.5,    // NOK
        10.3,    // SEK
        6.8,     // DKK
        4.1,     // PLN
        21.0,    // CZK
        340.0,   // HUF
        3.6,     // ILS
        17.0,    // MXN
        5.3,     // BRL
        910.0,   // ARS
        870.0,   // CLP
        3900.0,  // COP
        30.0,    // EGP
        280.0,   // PKR
        300.0,   // LKR
        1400.0,  // NGN
        145.0,   // KES
        32.0,    // TWD
        10.0,    // MAD
        36.0,    // UAH
        4.6,     // RON
        7.0      // HRK
    };

    // Create full matrix rate[i][j]
    double rate[50][50];
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 50; j++)
        {
            if (i == j)
                rate[i][j] = 1.0;
            else
                // Convert i to USD, then USD to j
                rate[i][j] = usd_rate[j] / usd_rate[i];
        }
    }

    do
    {
        printf("\n--- Currency Converter ---\n\nAvailable currencies:\n");
        for (i = 0; i < 50; i++)
        {
            printf("%2d. %s\n", i + 1, currencies[i]);
        }

        printf("\nEnter the number for source currency: ");
        scanf("%d", &i);
        if (i < 1 || i > 50)
        {
            printf("Invalid source currency selection.\n");
            continue;
        }

        printf("Enter the number for target currency: ");
        scanf("%d", &j);
        if (j < 1 || j > 50)
        {
            printf("Invalid target currency selection.\n");
            continue;
        }

        printf("Enter amount in %s: ", currencies[i - 1]);
        scanf("%lf", &input);

        result = input * rate[i - 1][j - 1];

        printf("\n%.2lf %s = %.2lf %s\n", input, currencies[i - 1], result, currencies[j - 1]);

        printf("\nDo you want to perform another conversion? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');
    printf("\nThank you for using the Currency Converter!\n");
}

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int char_to_val(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'z')
        return c - 'a' + 36;
    return -1; // Invalid
}

char val_to_char(int val)
{
    if (val >= 0 && val < 62)
        return digits[val];
    return '?';
}

double base_to_decimal(const char *num, int base)
{
    double result = 0.0;
    int point_pos = -1;
    int len = strlen(num);

    for (int i = 0; i < len; i++)
    {
        if (num[i] == '.')
        {
            point_pos = i;
            break;
        }
    }

    int end = (point_pos == -1) ? len : point_pos;

    for (int i = 0; i < end; i++)
    {
        int val = char_to_val(num[i]);
        if (val < 0 || val >= base)
            continue;
        result = result * base + val;
    }

    if (point_pos != -1)
    {
        double frac = 0.0;
        double factor = 1.0 / base;
        for (int i = point_pos + 1; i < len; i++)
        {
            int val = char_to_val(num[i]);
            if (val < 0 || val >= base)
                continue;
            frac += val * factor;
            factor /= base;
        }
        result += frac;
    }

    return result;
}

void decimal_to_base(double num, int base, char *output)
{
    char int_part_str[100] = {0};
    char frac_part_str[100] = {0};
    long long int_part = (long long)num;
    double frac_part = num - int_part;

    int idx = 0;
    if (int_part == 0)
    {
        int_part_str[idx++] = '0';
    }
    else
    {
        while (int_part > 0)
        {
            int rem = int_part % base;
            int_part_str[idx++] = val_to_char(rem);
            int_part /= base;
        }
    }
    int_part_str[idx] = '\0';

    // Reverse integer part
    int len = strlen(int_part_str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = int_part_str[i];
        int_part_str[i] = int_part_str[len - i - 1];
        int_part_str[len - i - 1] = temp;
    }

    // Fractional part
    int frac_idx = 0;
    if (frac_part > 0)
    {
        frac_part_str[frac_idx++] = '.';
        for (int i = 0; i < 12 && frac_part > 0; i++)
        { // 12 fractional digits
            frac_part *= base;
            int digit = (int)frac_part;
            frac_part_str[frac_idx++] = val_to_char(digit);
            frac_part -= digit;
        }
        frac_part_str[frac_idx] = '\0';
    }

    sprintf(output, "%s%s", int_part_str, frac_part_str);
}

void convert_base(const char *num, int from_base, int to_base)
{
    double dec_value = base_to_decimal(num, from_base);

    char output[200];
    decimal_to_base(dec_value, to_base, output);

    printf("Result in base %d: %s\n", to_base, output);
}

void Number_system()
{
    int from_base, to_base;
    char num[200];
    char again;

    do
    {
        printf("\n--- Number System Converter ---\n");
        printf("Enter source base (2 to 62): ");
        scanf("%d", &from_base);

        printf("Enter target base (2 to 62): ");
        scanf("%d", &to_base);

        if (from_base < 2 || from_base > 62 || to_base < 2 || to_base > 62)
        {
            printf("Invalid base range. Please enter bases between 2 and 62.\n");
            continue;
        }

        printf("Enter number in base %d: ", from_base);
        scanf("%s", num);

        convert_base(num, from_base, to_base);

        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Exiting Base Converter...\n");
}

void weight()
{
    int i, j;
    double input, result;
    char again;

    const char *units[7] = {
        "Milligrams (mg)",
        "Grams (g)",
        "Kilograms (kg)",
        "Tonnes (t)",
        "Ounces (oz)",
        "Pounds (lb)",
        "Stones (st)"};
    // Conversion to base unit: grams
    double to_gram[7] = {
        0.001,     // mg
        1.0,       // g
        1000.0,    // kg
        1000000.0, // t
        28.3495,   // oz
        453.592,   // lb
        6350.29    // st
    };

    do
    {
        printf("\n--- Weight Converter ---\n\n");
        for (i = 0; i < 7; i++)
        {
            printf("%d. %s\n", i + 1, units[i]);
        }

        printf("\nChoose source unit number: ");
        scanf("%d", &i);
        if (i < 1 || i > 7)
        {
            printf("Invalid source unit.\n");
            continue;
        }

        printf("Choose target unit number: ");
        scanf("%d", &j);
        if (j < 1 || j > 7)
        {
            printf("Invalid target unit.\n");
            continue;
        }

        printf("Enter weight in %s: ", units[i - 1]);
        scanf("%lf", &input);

        result = input * to_gram[i - 1] / to_gram[j - 1];

        printf("\n%.6lf %s = %.6lf %s\n", input, units[i - 1], result, units[j - 1]);

        printf("\nDo you want to convert another weight? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("Thank you for using the Weight Converter!\n");
}
int main()
{
    int choice;
    char again;

    printf("Welcome to Unit Conversion system!\n\n");

    do
    {
        printf("\nMain Menu:\n");
        printf("1. Temperature Converter\n");
        printf("2. Length Converter\n");
        printf("3. Currency Converter\n");
        printf("4. Time Converter\n");
        printf("5. Number system Converter\n");
        printf("6. Weight Converter\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting the converter. Goodbye!\n");
            break;
        case 1:
            temp();
            break;
        case 2:
            Length();
            break;
        case 3:
            Currency();
            break;
        case 4:
            time();
            break;
        case 5:
            Number_system();
            break;
        case 6:
            weight();
        default:
            printf("Invalid choice! Please select a number between 0 and 6.\n");
            break;
        }

        if (choice != 0)
        {
            printf("\nDo you want to return to main menu? (y/n): ");
            scanf(" %c", &again);
        }
    } while ((choice != 0) && (again == 'y' || again == 'Y'));

    return 0;
}
