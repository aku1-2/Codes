# Write your MySQL query statement below
SELECT p.firstName, p.lastName, a.city, a.state
From person p
LEFT jOIN
address a
ON p.personId=a.personId;
