
select b.name as Department ,a.name as Employee,a.Salary
from (
    select rn.departmentId as Department,name,salary
    from (select * ,
    dense_rank() over(partition by departmentId order by salary desc) as rn
    from employee) as rn
    where rn<4
) as a
left join department as b
on a.Department=b.id;
