# Write your MySQL query statement below
select a.request_at as Day ,round(ifnull(b.cnt,0)/a.cnt,2) as 'Cancellation Rate'
from (
    select request_at,count(*) as cnt
    from trips t
    join users u
        on t.client_id=u.users_id AND u.banned = 'No'
    join users uu
        on t.driver_id=uu.users_id AND uu.banned = 'No'
    WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
    group by request_at
) as a

left join (
    select request_at,count(*) as cnt
    from trips t
    join users u
        on t.client_id=u.users_id  AND u.banned = 'No'
    join users uu
        on t.driver_id=uu.users_id AND uu.banned = 'No'
    where status!="completed" and request_at BETWEEN            '2013-10-01' AND '2013-10-03'
    group by request_at
)as b
on a.request_at=b.request_at
