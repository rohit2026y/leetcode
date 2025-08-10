select distinct num as ConsecutiveNums
from (select *,
lag(num,1) over(order by id) as lag1,
lag(num,2) over(order by id) as lag2,
lead(num,1) over(order by id) as lead1,
lead(num,2) over(order by id) as lead2
from logs) as t
where (num=lag1 and num=lag2) or (num=lead1 and num=lead2) or (num=lead1 and num=lag1);