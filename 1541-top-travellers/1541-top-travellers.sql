# Write your MySQL query statement below
select a.name,coalesce(b.travelled_distance,0) as travelled_distance
from users as a
left join (select user_id,sum(distance) as travelled_distance
from rides
group by user_id) as b
on a.id=b.user_id
order by travelled_distance desc ,name asc