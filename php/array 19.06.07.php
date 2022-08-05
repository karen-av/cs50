

<?php
    $arr = array("one", 2, 3);
    //цикл прохождения по всему массиву
    foreach ($arr as $value) {
        echo "Value: $value \n";
    }

    echo "\n";

    $arrr = array("a" => 1, "b" => "two", "c" => 3);
    foreach ($arrr as $key => $value) {
        echo "Key: $key, Value: $value \n";
    }
    echo "\n";

    $arr3 = [4, 44, 93];
    echo "$arr3[0]\n";
    echo "{$arr3[1]}\n";
    echo "{$arr3['2']}\n";

    /**
     * == Приводит к одному типу и сравнивает
     * === сравнивает одного ли типа данные
     * foreach прохождение массива от началаи до конца
     */
?>