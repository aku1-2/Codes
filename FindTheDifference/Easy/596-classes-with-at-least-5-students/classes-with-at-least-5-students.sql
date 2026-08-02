# Write your MySQL query statement below
select c.class as class from Courses c
group by class having count(student)>=5;