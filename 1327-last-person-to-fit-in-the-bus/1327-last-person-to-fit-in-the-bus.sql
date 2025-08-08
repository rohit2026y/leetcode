select person_name 
from (select * ,
sum(weight) over(order by turn) as running_sum
from (select *
from queue
order by turn) as ranked) as nij
where running_sum<=1000
order by running_sum desc
limit 1;