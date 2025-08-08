
select round(sum(a.tiv_2016),2)as tiv_2016

from (select pid,tiv_2016
from insurance
where tiv_2015 in (
select tiv_2015 
from insurance
group by tiv_2015
having count(tiv_2015)>1)) as a

inner join
(
select pid,tiv_2016
from insurance 
group by lat,lon
having count(pid) <2) as b

on a.pid=b.pid;