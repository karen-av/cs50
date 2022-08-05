

<?php

/**
 * работа вс типами даных
 * Динамическая типизация
 * */

    $a = 1 + 1;
    echo "1 + 1 = $a\n";
    $typea = gettype($a); // Определяет тип переменной. Тип данных
    echo "Type a: $typea\n";

    $b = "1" + "1"; // Программа сама определяет тип данных. Делает целочисленное из строк, содержащих числа.
    echo "\"1\" + \"1\" is $b \n";
    $typeb = gettype($b);
    echo "Type b: $typeb\n";

    $c = "1" + 1; // Число + строка. Определяет как число 
    echo "\"1\" + 1 is $c\n";
    $typec = gettype($c);
    echo "Type c: $typec\n";

    $d = '1' + (double)'1';
    echo "'1' + '1' is $d\n";
    $typed = gettype($d);
    echo "Type d: $typed\n";

?>