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

    }
    while (again == 'y' || again == 'Y');

    printf("\nThank you for using the Temperature Converter!\n");
}

void Length() {
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
        "Miles (mi)"
    };
    double to_meter[8] = {
        0.001,    // mm
        0.01,     // cm
        1.0,      // m
        1000.0,   // km
        0.0254,   // in
        0.3048,   // ft
        0.9144,   // yd
        1609.34   // mi
    };

    do {
        printf("\n--- Length Converter ---\n\n");
        for (i = 0; i < 8; i++) {
            printf("%d. %s\n", i + 1, units[i]);
        }

        printf("\nChoose source unit number: ");
        scanf("%d", &i);
        if (i < 1 || i > 8) {
            printf("Invalid source unit.\n");
            continue;
        }

        printf("Choose target unit number: ");
        scanf("%d", &j);
        if (j < 1 || j > 8) {
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


void Currency() {
    int i, j;
    double input, result;
    char again;

    // Currency names for display
    const char *currencies[10] = {
        "USD", "BDT", "EUR", "GBP", "JPY", "AUD", "CAD", "CHF", "CNY", "INR"
    };

    double rate[10][10] = {
        // USD    BDT     EUR     GBP     JPY     AUD     CAD     CHF     CNY     INR
        {1.0,   110.0,  0.93,   0.82,   148.0,  1.44,   1.36,   0.91,   7.2,    83.0}, // USD
        {0.0091,1.0,    0.0084, 0.0075, 1.35,   0.013,  0.012,  0.0083, 0.065,  0.75},// BDT
        {1.08,  118.0,  1.0,    0.88,   159.0,  1.55,   1.47,   0.98,   7.7,    89.0}, // EUR
        {1.22,  135.0,  1.14,   1.0,    181.0,  1.76,   1.67,   1.12,   8.8,    102.0},// GBP
        {0.0068,0.74,   0.0063, 0.0055, 1.0,    0.0097, 0.0092, 0.0061, 0.048,  0.56},// JPY
        {0.69,  76.0,   0.64,   0.57,   103.0,  1.0,    0.95,   0.64,   5.0,    58.0}, // AUD
        {0.74,  82.0,   0.68,   0.60,   109.0,  1.05,   1.0,    0.67,   5.2,    60.0}, // CAD
        {1.10,  120.0,  0.99,   0.89,   161.0,  1.56,   1.49,   1.0,    7.7,    89.0}, // CHF
        {0.14,  15.3,   0.13,   0.11,   20.8,   0.20,   0.19,   0.13,   1.0,    11.6}, // CNY
        {0.012, 1.33,   0.011,  0.0098, 1.8,    0.017,  0.016,  0.011,  0.086,  1.0}   // INR
    };

    do {
        printf("\n--- Currency Converter ---\n");
        printf("Available currencies:\n");
        for (i = 0; i < 10; i++) {
            printf("%d. %s\n", i + 1, currencies[i]);
        }

        printf("Enter the number for source currency: ");
        scanf("%d", &i);
        if (i < 1 || i > 10) {
            printf("Invalid source currency selection.\n");
            continue;
        }

        printf("Enter the number for target currency: ");
        scanf("%d", &j);
        if (j < 1 || j > 10) {
            printf("Invalid target currency selection.\n");
            continue;
        }

        printf("Enter the amount in %s: ", currencies[i - 1]);
        scanf("%lf", &input);

        result = input * rate[i - 1][j - 1];
        printf("%.2lf %s = %.2lf %s\n", input, currencies[i - 1], result, currencies[j - 1]);

        printf("Do you want to perform another conversion? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("Thank you for using the Currency Converter!\n");
}

void time() {
    int i, j;
    double input, result;
    char again;

    const char *units[7] = {
        "Seconds (s)",
        "Minutes (min)",
        "Hours (h)",
        "Days (d)",
        "Weeks (wk)",
        "Months (mo)",
        "Years (yr)"
    };

    // Conversion to base unit: seconds
    double to_sec[7] = {
        1.0,            // seconds
        60.0,           // minutes
        3600.0,         // hours
        86400.0,        // days
        604800.0,       // weeks
        2629746.0,      // months (30.44 days)
        31556952.0      // years (365.25 days)
    };

    do {
        printf("\n--- Time Converter ---\n\n");
        for (i = 0; i < 7; i++) {
            printf("%d. %s\n", i + 1, units[i]);
        }

        printf("\nChoose source unit number: ");
        scanf("%d", &i);
        if (i < 1 || i > 7) {
            printf("Invalid source unit.\n");
            continue;
        }

        printf("Choose target unit number: ");
        scanf("%d", &j);
        if (j < 1 || j > 7) {
            printf("Invalid target unit.\n");
            continue;
        }

        printf("Enter time in %s: ", units[i - 1]);
        scanf("%lf", &input);

        // Convert to seconds first, then to target unit
        result = input * to_sec[i - 1] / to_sec[j - 1];

        printf("\n%.6lf %s = %.6lf %s\n", input, units[i - 1], result, units[j - 1]);

        printf("\nDo you want to perform another conversion? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThank you for using the Time Converter!\n");
}


int hex_char_to_int(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

double hex_to_decimal(const char *hex)
{
    double result = 0;
    int point_pos = -1;
    int len = strlen(hex);

    for (int i = 0; i < len; i++)
    {
        if (hex[i] == '.')
        {
            point_pos = i;
            break;
        }
    }

    int start = 0;
    int end = (point_pos == -1) ? len : point_pos;
    for (int i = start; i < end; i++)
    {
        int val = hex_char_to_int(hex[i]);
        if (val == -1)
            continue;
        result = result * 16 + val;
    }

    if (point_pos != -1)
    {
        double frac = 0;
        double base = 1.0 / 16;
        for (int i = point_pos + 1; i < len; i++)
        {
            int val = hex_char_to_int(hex[i]);
            if (val == -1)
                continue;
            frac += val * base;
            base /= 16;
        }
        result += frac;
    }

    return result;
}

void Decimal_to_Binary(float num)
{
    int int_part = (int)num;
    float frac_part = num - int_part;

    printf("Binary: ");
    for (int i = 31; i >= 0; i--)
    {
        int bit = (int_part >> i) & 1;
        printf("%d", bit);
    }
    printf(".");

    for (int i = 0; i < 8; i++)
    {
        frac_part *= 2;
        int frac_bit = (int)frac_part;
        printf("%d", frac_bit);
        frac_part -= frac_bit;
    }
    printf("\n");
}

void Decimal_to_Octal(float num)
{
    int int_part = (int)num;
    float frac_part = num - int_part;

    printf("Octal: %o.", int_part);
    for (int i = 0; i < 8; i++)
    {
        frac_part *= 8;
        int frac_bit = (int)frac_part;
        printf("%d", frac_bit);
        frac_part -= frac_bit;
    }
    printf("\n");
}

void Decimal_to_Hex(float num)
{
    int int_part = (int)num;
    float frac_part = num - int_part;

    printf("Hexadecimal: %X.", int_part);
    for (int i = 0; i < 8; i++)
    {
        frac_part *= 16;
        int frac_bit = (int)frac_part;
        printf("%X", frac_bit);
        frac_part -= frac_bit;
    }
    printf("\n");
}

void Binary_to_Decimal(char *bin)
{
    int result = 0;
    for (int i = 0; bin[i]; i++)
    {
        result = result * 2 + (bin[i] - '0');
    }
    printf("Decimal: %d\n", result);
}

void Octal_to_Decimal(char *oct)
{
    int result = 0;
    for (int i = 0; oct[i]; i++)
    {
        result = result * 8 + (oct[i] - '0');
    }
    printf("Decimal: %d\n", result);
}

void Hexadecimal_to_Decimal(char *hex)
{
    double result = hex_to_decimal(hex);
    printf("Decimal: %lf\n", result);
}

void Number_system()
{
    int opt;
    char again;

    do
    {
        printf("\nWelcome to Number system converter\n\n");
        printf("1. Decimal to Binary\n");
        printf("2. Decimal to Octal\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Binary to Decimal\n");
        printf("5. Octal to Decimal\n");
        printf("6. Hexadecimal to Decimal\n");
        printf("0. Exit\n\n");

        printf("Enter your option: ");
        scanf("%d", &opt);

        switch(opt)
        {
        case 0:
            printf("Exiting Number System Converter...\n");
            break;
        case 1:
        {
            float dec;
            printf("Enter Decimal Number: ");
            scanf("%f", &dec);
            Decimal_to_Binary(dec);
            break;
        }
        case 2:
        {
            float dec;
            printf("Enter Decimal Number: ");
            scanf("%f", &dec);
            Decimal_to_Octal(dec);
            break;
        }
        case 3:
        {
            float dec;
            printf("Enter Decimal Number: ");
            scanf("%f", &dec);
            Decimal_to_Hex(dec);
            break;
        }
        case 4:
        {
            char bin[100];
            printf("Enter Binary Number: ");
            scanf("%s", bin);
            Binary_to_Decimal(bin);
            break;
        }
        case 5:
        {
            char oct[100];
            printf("Enter Octal Number: ");
            scanf("%s", oct);
            Octal_to_Decimal(oct);
            break;
        }
        case 6:
        {
            char hex[100];
            printf("Enter Hexadecimal Number (e.g., 13442EA.EB): ");
            scanf("%s", hex);
            Hexadecimal_to_Decimal(hex);
            break;
        }
        default:
            printf("Invalid Option\n");
            break;
        }

        if (opt != 0)
        {
            printf("\nDo you want to perform another conversion? (y/n): ");
            scanf(" %c", &again);
        }
    }
    while ((opt != 0) && (again == 'y' || again == 'Y'));
}

void weight() {
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
        "Stones (st)"
    };
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

    do {
        printf("\n--- Weight Converter ---\n\n");
        for (i = 0; i < 7; i++) {
            printf("%d. %s\n", i + 1, units[i]);
        }

        printf("\nChoose source unit number: ");
        scanf("%d", &i);
        if (i < 1 || i > 7) {
            printf("Invalid source unit.\n");
            continue;
        }

        printf("Choose target unit number: ");
        scanf("%d", &j);
        if (j < 1 || j > 7) {
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

        switch(choice)
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
    }
    while ((choice != 0) && (again == 'y' || again == 'Y'));

    return 0;
}
