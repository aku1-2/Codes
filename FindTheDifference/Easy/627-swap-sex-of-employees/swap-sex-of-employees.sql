# Write your MySQL query statement below
update Salary
Set sex= case when sex='m' then 'f' 
else 'm'
end;