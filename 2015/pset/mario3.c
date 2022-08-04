
#include<cs50.h>
#include<stdio.h>

int get_positive_int();
int main(void)
{

    int n = get_positive_int("");                                           //вызывает функцию прописанную внизу
    printf("Heigth %i!\n", n);

printf("                                                                                                                                             #\n");
printf("                                                                                                                                             #                 \n");
printf("                                                                                                                              #              #              #\n");
printf("                                                                                                                                #            #            #\n");
printf("                                                                                                                                  #          #          #\n");
printf("                                                                                                                                    #        #        #\n");
printf("                                                                                                                                      #      #      #\n");
printf("                                                                                                                                        #  #####  #\n");
printf("                                                                                                                                          #######\n");
printf("                                                                                                                                        ###########\n");
printf("                                                                                                                       # # # # # # # # ############# # # # # # # # # \n");
printf("                                                                                                                                        ###########\n");
printf("                                                                                                                                         #########\n");
printf("                                                                                                                                          #######\n");
printf("                                                                                                                                           #####\n");
printf("                                                                                                                                        #    #   #\n");
printf("                                                                                                                                      #      #     #\n");
printf("                                                                                                                                    #        #       #\n");
printf("                                                                                                                                  #          #         #\n");
printf("                                                                                                                                #            #           #\n");
printf("                                 O                                                                                            #              #             #\n");
printf("                                -|-                                                                                                          #\n");
printf("                                / |             \n");

// строим наклонную стену по заданному пользователем числу у этажей
// правильный вариант

    for (int i = 0; i < n; i++)                                              //делает строки. i = 1 гора из двух #. i = 0 гора из одной #
    {
        for (int p = n - i; p > 1; p--)                                     //делает отступ слева. выравнивает по правому краю
            {
                printf(" ");
            }
        for (int f = i; f > 0 || f == 0; f--)                             //делает #
            {
                printf("#");
            }
            printf(" ");                                                    // разделяет горы
        for (int f = i; f > 0 || f == 0; f--)                             //делает # в другую сторону
            {
                printf("#");
            }
        for (int x = n; x > n - 2; x--)                                     //делает отступ справа. выравнивает по правому краю. (n - 2) можно менять отступ
            {
                printf(" ");
            }
/*      for (int f = i + 10; f > 0 || f == 0; f--)                             //делает рисунок справа. f = i + 10 можно менять длинну правлго крыла
            {
                printf("0101");
            }
*/
        printf("\n");
    }
}


int get_positive_int(void)                                                  // функция параметров запрашиваемого числа
{
    int x;
    do
    {
    printf("Insert the number:");
    x = get_int("");
    }
    while (x < 0 || x > 30);
    return x;
}