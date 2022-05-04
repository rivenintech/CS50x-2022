-- Crime info:
-- Theft took place on July 28, 2021
-- Theft took place on Humphrey Street in Fiftyville


-- Check crime description:
-- 1. Theft at 10:15 am at the Humphrey Street Bakery in Fiftyville
-- 2. Interviews were conducted same day with three witnesses
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND street = 'Humphrey Street';


-- Check the transcripts of the interviewed witnesses for clues:
-- 1. Within 10 minutes of the theft, the thief got into a car in a bakery parking lot and left
-- 2. Earlier this day thief withdrew some money at an ATM on Leggett Street
-- 3. The thief talked on the phone for less than a minute and asked person the receiver to buy the plane ticket for the earliest flight the next day
SELECT transcript
  FROM interviews
 WHERE month = 7
   AND day = 28
   AND year = 2021;


-- Get flight id, origin and destination airports for the earliest flight next day
-- flight_id: 36, origin_airport_id: 8, destination_airport_id: 4
SELECT id, origin_airport_id, destination_airport_id
  FROM flights
 WHERE year = 2021
   AND month = 7
   AND day = 29
 ORDER BY hour ASC
 LIMIT 1;


-- Get the city the thief escaped to by knowing the airport id
SELECT city
  FROM airports
 WHERE id = 4;


-- Get the thief's id, name, and phone number by matching all data
SELECT id, name, phone_number
  FROM people
 WHERE phone_number IN
       -- Get calls that were made the same day as the theft happened (that were under a minute)
       (SELECT caller
         FROM phone_calls
        WHERE year = 2021
          AND month = 7
          AND day = 28
          AND duration < 60)
   AND passport_number IN
       -- Get passport numbers from people that were on the plane
       (SELECT passport_number
          FROM passengers
         WHERE flight_id = 36)
   AND license_plate IN
       -- Get license plates of all cars that left within 10 minutes after theft (10:15 - 10:25)
       (SELECT license_plate
         FROM bakery_security_logs
        WHERE year = 2021
          AND day = 28
          AND month = 7
          AND hour = 10
          AND minute BETWEEN 15 AND 25
          AND activity = 'exit')
   AND id IN
       -- Link bank accounts numbers with person_id
       (SELECT person_id
          FROM bank_accounts
         WHERE account_number IN
               -- Get account numbers of people that withdraw money that day from the ATM at "Leggett Street"
               (SELECT account_number
                  FROM atm_transactions
                 WHERE year = 2021
                   AND month = 7
                   AND day = 28
                   AND atm_location = 'Leggett Street'
                   AND transaction_type = 'withdraw'));


-- Get the thief’s accomplice's id and name
SELECT id, name
  FROM people
 WHERE phone_number =
       -- Get the thief’s accomplice's phone number that the thief called
       (SELECT receiver
          FROM phone_calls
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND duration < 60
           AND caller = '(367) 555-5533');