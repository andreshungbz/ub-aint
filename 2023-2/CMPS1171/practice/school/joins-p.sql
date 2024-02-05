-- INNER JOIN
SELECT
    S.student_id,
    S.first_name,
    S.last_name,
    G.student_id,
    G.grade
FROM
    students AS S
    INNER JOIN grades AS G ON S.student_id = G.student_id;

-- LEFT OUTER JOIN
SELECT
    S.student_id,
    S.first_name,
    S.last_name,
    G.student_id,
    G.grade
FROM
    students AS S
    LEFT OUTER JOIN grades AS G ON S.student_id = G.student_id
WHERE
    G.student_id IS NULL;