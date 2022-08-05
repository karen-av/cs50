<?php
/** открываем файл и делаем рассылку */

    $handle = fopen("staff.csv", "r");
    if(!$handle)
    {
        print("Could not open file\n");
        exit(1);
    }

    $addresses = [];

    /** fgetcsv читает файл csv построчно и видит запятые, которые разделяю колонки */
    while ($row = fgetcsv($handle))
    {
        $number = $row[2]; /** номер телефона */
        $carrier = $row[3]; /** оператор */

        if($carrier == "AT&T")
        {
            $address = "{$nomber}@txt.att.net";
            array_push($addresses, $address); // Увеличиваем массив. В массив addresses  дабавляем данные address
            //$addresses[] = $address; // Так же добавляем данные и увеличиваем массив
        }
        else if ($carrier == "Verizion")
        {
            $address = "{$nomber}@vtext.com";
        }

        //close file
        fclose($handle);

        $mail = new PHPMailer();

    }


?>