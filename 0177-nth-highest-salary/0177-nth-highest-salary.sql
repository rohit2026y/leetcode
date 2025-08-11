CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    select salary
    from (select salary,
    dense_rank() over(order by salary desc) as rn
    from employee) as f
    where rn=n
    limit 1
  );
END