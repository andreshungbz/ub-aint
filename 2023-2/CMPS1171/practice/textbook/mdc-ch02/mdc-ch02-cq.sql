-- A
-- SELECT *
-- FROM customer;

-- SELECT *
-- FROM invoice;

-- SELECT *
-- FROM invoice_item;

-- B
-- SELECT lastname, firstname, phone
-- FROM customer;

-- C
-- SELECT lastname, firstname, phone
-- FROM customer
-- WHERE firstname = 'Nikki';

-- D
-- SELECT C.lastname, C.firstname, C.phone, I.datein, I.dateout
-- FROM customer AS C
-- INNER JOIN invoice AS I
-- USING (customerid)
-- WHERE I.totalamount > 100.00;

-- E
-- SELECT lastname, firstname, phone
-- FROM customer
-- WHERE firstname LIKE 'B%';

-- F
-- SELECT lastname, firstname, phone
-- FROM customer
-- WHERE lastname LIKE '%cat%';

-- G
-- SELECT lastname, firstname, phone
-- FROM customer
-- WHERE phone LIKE '_23%';

-- H
-- SELECT MAX(totalamount) AS invoice_max_total_amount, MIN(totalamount) AS invoice_min_total_amount
-- FROM invoice;

-- I
-- SELECT AVG(totalamount) AS invoice_avg_total_amount
-- FROM invoice;

-- J
-- SELECT COUNT(*) AS number_of_customers
-- FROM customer;

-- K
-- SELECT lastname, firstname
-- FROM customer
-- GROUP BY lastname, firstname;

-- L
-- SELECT lastname, firstname, COUNT(*)
-- FROM customer
-- GROUP BY lastname, firstname;

-- M
SELECT lastname, firstname, phone
FROM customer
WHERE customerid IN (
    SELECT customerid
    FROM invoice
    WHERE totalamount > 100.00
    )
ORDER BY lastname, firstname DESC;