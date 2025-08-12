
select u.name,b.balance
from users u
left join (select account, sum(amount) as balance
from transactions 
group by account) as b
on u.account=b.account
where b.balance>10000
