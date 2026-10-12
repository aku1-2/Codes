# Write your MySQL query statement below
(select u.name as results
from MovieRating m join Users u 
on u.user_id= m.user_id
group by m.user_id,u.name order by count(*) desc, u.name asc limit 1)

union all
(select x.title as results from MovieRating m join Movies x
on x.movie_id = m.movie_id
where m.created_at >='2020-02-01' and m.created_at<'2020-03-01'
group by m.movie_id, x.title order by avg(m.rating) desc, x.title asc limit 1);