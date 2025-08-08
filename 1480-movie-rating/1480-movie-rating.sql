-- # Write your MySQL query statement below
(select name as results 
from(select b.name,maxi
from (select user_id,count(distinct movie_id) as maxi
from movierating
group by user_id) as a
left join users as b
on a.user_id=b.user_id) as ranked
order by maxi desc,name
limit 1)

union all

(select title as results
from (select d.title,c.rating
from (select movie_id,avg(rating) as rating 
from movierating
where created_at like "2020-02%"
group by movie_id) as c 
left join movies as d
on c.movie_id=d.movie_id) as rated 
order by rating desc, title
limit 1);