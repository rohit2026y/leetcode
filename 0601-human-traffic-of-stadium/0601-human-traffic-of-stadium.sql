select id,visit_date,people
from (select id,visit_date,people,id-rn as diff
from (select *,
rank() over(order by id) as rn
from stadium
where people>=100) as t) as tn

where diff in (
select id-rn as diff
from (select *,
rank() over(order by id) as rn
from stadium
where people>=100) as t
group by diff
having count(id)>=3)
order by visit_date;