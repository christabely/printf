#include "main.h"
/**
 * parser - print formatted string
 * @format: string
 * @conversion_list: functions
 * @arg_list: arguments passef
 * Return: num characters
 */
int parser(const char *format, Conversion conversion_list[], va_list arg_list)
{
    int i, j, r_val, printed_chars;

    printed_chars = 0;
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            for (j = 0; conversion_list[j].symbol != NULL; j++)
            {
                if (format[i + 1] == conversion_list[j].symbol[0])
                {
                    r_val = conversion_list[j].function(arg_list);
                    if (r_val == -1)
                        return (-1);
                    printed_chars += r_val;
                    break;
                }
            }
            if (conversion_list[j].symbol == NULL && format[i + 1] != ' ')
            {
                if (format[i + 1] != '\0')
                {
                    write_character(format[i]);
                    write_character(format[i + 1]);
                    printed_chars += 2;
                }
                else
                {
                    return (-1);
                }
            }
            i = i + 1;
        }
        else
        {
            write_character(format[i]); 
            printed_chars++;
        }
    }
    return (printed_chars);
}

