#include<cs50.h>
#include<stdio.h>

int main(void)

// строим наклонную стену по заданному пользователем числу у этажей
// плохой вариант

{
    printf("What height do you want? (from 1 to 14): "); //просим задать высоту от и до
    int height = get_int("");
    if (height<1 || height > 15)
    {
        {
            do
            {
            printf("Chek and try again: ");
            height = get_int("");
            }
            while (height < 1 || height > 15);

            if (height < 2)
            {
                printf("Entre: %i\n", height);
                printf(" \n");
                printf("##\n");
                printf(" \n");
            }

            else if (height < 3)
            {
                printf("Entre: %i\n", height);
                printf(" \n");
                printf(" ##\n");
                printf("###\n");
                printf(" \n");
            }

            else if (height < 4)
            {
                printf("Entre: %i\n", height);
                printf(" \n");
                printf("  ##\n");
                printf(" ###\n");
                printf("####\n");
                printf(" \n");
            }

            else if (height < 5)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("   ##\n");
                printf("  ###\n");
                printf(" ####\n");
                printf("#####\n");
                printf(" \n");
            }

            else if (height < 6)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("    ##\n");
                printf("   ###\n");
                printf("  ####\n");
                printf(" #####\n");
                printf("######\n");
                printf(" \n");
            }

            else if (height < 7)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("     ##\n");
                printf("    ###\n");
                printf("   ####\n");
                printf("  #####\n");
                printf(" ######\n");
                printf("#######\n");
                printf(" \n");
            }

            else if (height < 8)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("      ##\n");
                printf("     ###\n");
                printf("    ####\n");
                printf("   #####\n");
                printf("  ######\n");
                printf(" #######\n");
                printf("########\n");
                printf(" \n");
            }

            else if (height < 9)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("       ##\n");
                printf("      ###\n");
                printf("     ####\n");
                printf("    #####\n");
                printf("   ######\n");
                printf("  #######\n");
                printf(" ########\n");
                printf("#########\n");
                printf(" \n");
            }

            else if (height < 10)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("        ##\n");
                printf("       ###\n");
                printf("      ####\n");
                printf("     #####\n");
                printf("    ######\n");
                printf("   #######\n");
                printf("  ########\n");
                printf(" #########\n");
                printf("##########\n");
                printf(" \n");
            }

            else if (height < 11)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("          ##\n");
                printf("         ###\n");
                printf("        ####\n");
                printf("       #####\n");
                printf("     #######\n");
                printf("    ########\n");
                printf("   #########\n");
                printf("  ##########\n");
                printf(" ###########\n");
                printf("############\n");
                printf(" \n");
            }

            else if (height < 12)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("          ##\n");
                printf("         ###\n");
                printf("        ####\n");
                printf("       #####\n");
                printf("      ######\n");
                printf("     #######\n");
                printf("    ########\n");
                printf("   #########\n");
                printf("  ##########\n");
                printf(" ###########\n");
                printf("############\n");
                printf(" \n");
            }

            else if (height < 13)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("           ##\n");
                printf("          ###\n");
                printf("         ####\n");
                printf("        #####\n");
                printf("       ######\n");
                printf("      #######\n");
                printf("     ########\n");
                printf("    #########\n");
                printf("   ##########\n");
                printf("  ###########\n");
                printf(" ############\n");
                printf("#############\n");
                printf(" \n");
            }

            else if (height < 14)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("            ##\n");
                printf("           ###\n");
                printf("          ####\n");
                printf("         #####\n");
                printf("        ######\n");
                printf("       #######\n");
                printf("      ########\n");
                printf("     #########\n");
                printf("    ##########\n");
                printf("   ###########\n");
                printf("  ############\n");
                printf(" #############\n");
                printf("##############\n");
                printf(" \n");
            }

            else if (height < 15)
            {
                printf("Введенное значение: %i\n", height);
                printf(" \n");
                printf("             ##\n");
                printf("            ###\n");
                printf("           ####\n");
                printf("          #####\n");
                printf("         ######\n");
                printf("        #######\n");
                printf("       ########\n");
                printf("      #########\n");
                printf("     ##########\n");
                printf("    ###########\n");
                printf("   ############\n");
                printf("  #############\n");
                printf(" ##############\n");
                printf("###############\n");
                printf(" \n");
            }
        }
    }


    else if (height < 2)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("##\n");
        printf(" \n");
    }

    else if (height < 3)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf(" ##\n");
        printf("###\n");
        printf(" \n");
    }

    else if (height < 4)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("  ##\n");
        printf(" ###\n");
        printf("####\n");
        printf(" \n");
    }

    else if (height < 5)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("   ##\n");
        printf("  ###\n");
        printf(" ####\n");
        printf("#####\n");
        printf(" \n");
    }

    else if (height < 6)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("    ##\n");
        printf("   ###\n");
        printf("  ####\n");
        printf(" #####\n");
        printf("######\n");
        printf(" \n");
    }

    else if (height < 7)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("     ##\n");
        printf("    ###\n");
        printf("   ####\n");
        printf("  #####\n");
        printf(" ######\n");
        printf("#######\n");
        printf(" \n");
    }

    else if (height < 8)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("      ##\n");
        printf("     ###\n");
        printf("    ####\n");
        printf("   #####\n");
        printf("  #######\n");
        printf(" #######\n");
        printf("########\n");
        printf(" \n");
    }

    else if (height < 9)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("       ##\n");
        printf("      ###\n");
        printf("     ####\n");
        printf("    #####\n");
        printf("   ######\n");
        printf("  #######\n");
        printf(" ########\n");
        printf("#########\n");
        printf(" \n");
    }

    else if (height < 10)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("        ##\n");
        printf("       ###\n");
        printf("      ####\n");
        printf("     #####\n");
        printf("    ######\n");
        printf("   #######\n");
        printf("  ########\n");
        printf(" #########\n");
        printf("##########\n");
        printf(" \n");
    }

    else if (height < 11)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("         ##\n");
        printf("        ###\n");
        printf("       ####\n");
        printf("      #####\n");
        printf("     ######\n");
        printf("    #######\n");
        printf("   ########\n");
        printf("  #########\n");
        printf(" ##########\n");
        printf("###########\n");
        printf(" \n");
    }

    else if (height < 12)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("          ##\n");
        printf("         ###\n");
        printf("        ####\n");
        printf("       #####\n");
        printf("      ######\n");
        printf("     #######\n");
        printf("    ########\n");
        printf("   #########\n");
        printf("  ##########\n");
        printf(" ###########\n");
        printf("############\n");
        printf(" \n");
    }

    else if (height < 13)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("           ##\n");
        printf("          ###\n");
        printf("         ####\n");
        printf("        #####\n");
        printf("       ######\n");
        printf("      #######\n");
        printf("     ########\n");
        printf("    #########\n");
        printf("   ##########\n");
        printf("  ###########\n");
        printf(" ############\n");
        printf("#############\n");
        printf(" \n");
    }

    else if (height < 14)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("            ##\n");
        printf("           ###\n");
        printf("          ####\n");
        printf("         #####\n");
        printf("        ######\n");
        printf("       #######\n");
        printf("      ########\n");
        printf("     #########\n");
        printf("    ##########\n");
        printf("   ###########\n");
        printf("  ############\n");
        printf(" #############\n");
        printf("##############\n");
        printf(" \n");
    }

    else if (height < 15)
    {
        printf("Введенное значение: %i\n", height);
        printf(" \n");
        printf("             ##\n");
        printf("            ###\n");
        printf("           ####\n");
        printf("          #####\n");
        printf("         ######\n");
        printf("        #######\n");
        printf("       ########\n");
        printf("      #########\n");
        printf("     ##########\n");
        printf("    ###########\n");
        printf("   ############\n");
        printf("  #############\n");
        printf(" ##############\n");
        printf("###############\n");
        printf(" \n");
    }
    /*
    else if (height < 16)
    {
        for (int i = 1; i < 16; i++)

        {
            printf("%i\n", i);
        }
        printf("\n");
    }
    */
}

