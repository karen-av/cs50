<?php

    $arr = [4, 5, 2, 6];
    foreach($arr as $value) {
        echo "$value\n";
    }

    $arr2 = ["Hi" => 5, 2 => "Hello", 'H' => 4];
    foreach($arr2 as $key=>$value){
        echo "Key; $key, Value: $value\n";
    }

    echo "$arr[2], $arr2[Hi]\n";



?>