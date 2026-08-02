# Write your MySQL query statement below
select max(n.num) as num from MyNumbers n
where num in(
    select num from MyNumbers
    group by num
    having count(*)=1
);