<?php
/* Оператор if */

    $n = readline("Введите число \n");

    if($n > 0)
    {
        print("Число больше 0!\n");
    }
    else if($n == 0)
    {
        print("Равно нулю!\n");
    }
    else
    {
        print("Число меньше нуля!\n");
    }

?>