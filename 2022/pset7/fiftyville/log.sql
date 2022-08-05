-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Записать все SQL  запросы и добавить коменты
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
-- Сортируем по дае преступлеиня и улице и упоминанию утки или cd50 в таблице crime_scene_reports
SELECT *
FROM crime_scene_reports
WHERE year == 2021
AND month == 7
AND day == 28
AND street LIKE "Humphrey Street"
AND description LIKE "%duck%";

-- Выше мы получили id  преступления и описание
-- Далее в таблице interviews ищем упоминания о пекарне в свидетельских показаниях
SELECT *
FROM interviews
WHERE transcript like "%bakery%";
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- id 163. Говорится, что преступник вылетает завтра (29.07.21) утром самым ранним рейсом.

-- Ищем рейс 29.07.21 в
-- Сначала данные фэропорта вылета из airports
SELECT * FROM airports WHERE city LIKE "Fiftyville";
-- id 8 CSF
-- ищем информацию о вылетах из Fiftyville  в  flights
-- узнаем аэропорт прилета
-- id 4. аэропорт прилета LGA LaGuardia Airport New York City

SELECT abbreviation, full_name, city
FROM airports
WHERE id in
    (SELECT destination_airport_id
    FROM flights
    JOIN airports
    ON airports.id = flights.origin_airport_id
    WHERE city LIKE "Fiftyville"
    AND day == 29
    ORDER BY hour, minute
    LIMIT 1);

-- Вытаскиваем список пассажиров рейса
    -- Номер рейса (36)
    -- вариант 1
SELECT *
FROM flights
JOIN airports
ON airports.id = flights.origin_airport_id
WHERE city LIKE "Fiftyville"
AND day == 29
ORDER BY hour, minute
LIMIT 1;

        -- Вариант 2
SELECT id
FROM flights
WHERE origin_airport_id in
    (SELECT id
    FROM airports
    WHERE city LIKE "Fiftyville")
AND day == 29
ORDER BY hour, minute
LIMIT 1;


    -- Список пассажиров рейса
 SELECT *
 FROM passengers
 WHERE flight_id ==
    (SELECT id
    FROM flights
    WHERE origin_airport_id in
        (SELECT id
        FROM airports
        WHERE city LIKE "Fiftyville")
    AND day == 29
    ORDER BY hour, minute
    LIMIT 1);


-- Телефонный разговор меньше минуты 28.07.21
-- Список звонков
SELECT * FROM phone_calls WHERE duration < 60 AND day == 28;

--Есть список пассажиров и сисок звонков vожно сопоставить по номеру телефона

    -- У нас есть список звонков и список людей летевших эти рейсом
    -- Сопоставляем номера телефоно в из этих списков
    -- По показаниям свидетеля вор кому-то позвонить
    -- список людейб которые летели этим рейсом и сделали звонок длительностью меньше минуты

SELECT *
FROM people
WHERE passport_number in
    (SELECT passport_number
    FROM passengers
    WHERE flight_id ==
        (SELECT id
        FROM flights
        WHERE origin_airport_id in
            (SELECT id
            FROM airports
            WHERE city LIKE "Fiftyville")
        AND day == 29
        ORDER BY hour, minute
        LIMIT 1))
AND phone_number IN
    (SELECT caller
    FROM phone_calls
    WHERE duration < 60
    AND day == 28);



-- Лог машин приехавши/уехавших из кафе сопоставляем со списком пассажиров

SELECT *
FROM bakery_security_logs
WHERE license_plate IN
    (SELECT license_plate
    FROM people
    WHERE passport_number in
        (SELECT passport_number
        FROM passengers
        WHERE flight_id ==
            (SELECT id
            FROM flights
            WHERE origin_airport_id in
                (SELECT id
                FROM airports
                WHERE city LIKE "Fiftyville")
            AND day == 29
            ORDER BY hour, minute
            LIMIT 1))
    AND phone_number IN
        (SELECT caller
        FROM phone_calls
        WHERE duration < 60
        AND day == 28))
AND day == 28
AND minute <= 25
AND minute >= 15
AND activity == "exit";


-- нужен список людей, покупавших билеты



-- выводим список банковских аккаунтов всех этих людей
SELECT *
FROM bank_accounts
WHERE person_id IN
    (SELECT id
    FROM people
    WHERE passport_number in
        (SELECT passport_number
        FROM passengers
        WHERE flight_id ==
            (SELECT id
            FROM flights
            WHERE origin_airport_id in
                (SELECT id
                FROM airports
                WHERE city LIKE "Fiftyville")
            AND day == 29
            ORDER BY hour, minute
            LIMIT 1))
    AND phone_number IN
        (SELECT caller
        FROM phone_calls
        WHERE duration < 60
        AND day == 28));

-- Список тех, кто снимал деньги на Humphrey Lane

SELECT *
FROM atm_transactions
WHERE day == 28
AND atm_location LIKE "Leggett Street"
AND transaction_type == "withdraw"
AND account_number IN
    (SELECT account_number
    FROM bank_accounts
    WHERE person_id IN
        (SELECT id
        FROM people
        WHERE passport_number in
            (SELECT passport_number
            FROM passengers
            WHERE flight_id ==
                (SELECT id
                FROM flights
                WHERE origin_airport_id in
                    (SELECT id
                    FROM airports
                    WHERE city LIKE "Fiftyville")
                AND day == 29
                ORDER BY hour, minute
                LIMIT 1))
        AND phone_number IN
            (SELECT caller
            FROM phone_calls
            WHERE duration < 60
            AND day == 28)));

-- Сопоставляем спиок аккаунтов пассажиров и список снимавших деньги xерез people(id)

SELECT *
FROM people
WHERE id IN
    (SELECT person_id
    FROM bank_accounts
    WHERE person_id IN
        (SELECT id
        FROM people
        WHERE passport_number in
            (SELECT passport_number
            FROM passengers
            WHERE flight_id ==
                (SELECT id
                FROM flights
                WHERE origin_airport_id in
                    (SELECT id
                    FROM airports
                    WHERE city LIKE "Fiftyville")
                AND day == 29
                ORDER BY hour, minute
                LIMIT 1))
        AND phone_number IN
            (SELECT caller
            FROM phone_calls
            WHERE duration < 60
            AND day == 28)))
AND license_plate IN
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE license_plate IN
        (SELECT license_plate
        FROM people
        WHERE passport_number in
            (SELECT passport_number
            FROM passengers
            WHERE flight_id ==
                (SELECT id
                FROM flights
                WHERE origin_airport_id in
                    (SELECT id
                    FROM airports
                    WHERE city LIKE "Fiftyville")
                AND day == 29
                ORDER BY hour, minute
                LIMIT 1))
        AND phone_number IN
            (SELECT caller
            FROM phone_calls
            WHERE duration < 60
            AND day == 28))
    AND day == 28
    AND minute <= 25
    AND minute >= 15
    AND activity == "exit");

-- еще раз отфильтруем звонки
-- Получаем кому  сделал зыонок преступник

SELECT receiver
FROM phone_calls
WHERE duration < 60
AND day == 28
AND caller IN
    (SELECT phone_number
    FROM people
    WHERE id IN
        (SELECT person_id
        FROM bank_accounts
        WHERE person_id IN
            (SELECT id
            FROM people
            WHERE passport_number in
                (SELECT passport_number
                FROM passengers
                WHERE flight_id ==
                    (SELECT id
                    FROM flights
                    WHERE origin_airport_id in
                        (SELECT id
                        FROM airports
                        WHERE city LIKE "Fiftyville")
                    AND day == 29
                    ORDER BY hour, minute
                    LIMIT 1))
            AND phone_number IN
                (SELECT caller
                FROM phone_calls
                WHERE duration < 60
                AND day == 28)))
    AND license_plate IN
        (SELECT license_plate
        FROM bakery_security_logs
        WHERE license_plate IN
            (SELECT license_plate
            FROM people
            WHERE passport_number in
                (SELECT passport_number
                FROM passengers
                WHERE flight_id ==
                    (SELECT id
                    FROM flights
                    WHERE origin_airport_id in
                        (SELECT id
                        FROM airports
                        WHERE city LIKE "Fiftyville")
                    AND day == 29
                    ORDER BY hour, minute
                    LIMIT 1))
            AND phone_number IN
                (SELECT caller
                FROM phone_calls
                WHERE duration < 60
                AND day == 28))
        AND day == 28
        AND minute <= 25
        AND minute >= 15
        AND activity == "exit"));

        -- Сообщник

SELECT name
FROM people
WHERE phone_number IN
    (SELECT receiver
FROM phone_calls
WHERE duration < 60
AND day == 28
AND caller IN
    (SELECT phone_number
    FROM people
    WHERE id IN
        (SELECT person_id
        FROM bank_accounts
        WHERE person_id IN
            (SELECT id
            FROM people
            WHERE passport_number in
                (SELECT passport_number
                FROM passengers
                WHERE flight_id ==
                    (SELECT id
                    FROM flights
                    WHERE origin_airport_id in
                        (SELECT id
                        FROM airports
                        WHERE city LIKE "Fiftyville")
                    AND day == 29
                    ORDER BY hour, minute
                    LIMIT 1))
            AND phone_number IN
                (SELECT caller
                FROM phone_calls
                WHERE duration < 60
                AND day == 28)))
    AND license_plate IN
        (SELECT license_plate
        FROM bakery_security_logs
        WHERE license_plate IN
            (SELECT license_plate
            FROM people
            WHERE passport_number in
                (SELECT passport_number
                FROM passengers
                WHERE flight_id ==
                    (SELECT id
                    FROM flights
                    WHERE origin_airport_id in
                        (SELECT id
                        FROM airports
                        WHERE city LIKE "Fiftyville")
                    AND day == 29
                    ORDER BY hour, minute
                    LIMIT 1))
            AND phone_number IN
                (SELECT caller
                FROM phone_calls
                WHERE duration < 60
                AND day == 28))
        AND day == 28
        AND minute <= 25
        AND minute >= 15
        AND activity == "exit")));