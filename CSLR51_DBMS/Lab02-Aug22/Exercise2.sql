
--Question 1
SELECT Employee.bdate, Employee.address FROM Employee
RIGHT JOIN Department ON Employee.dno = Department.dno
WHERE Department.dname = 'Research';

SELECT Project.pno, Department.dname, Employee.lname, Employee.address, Employee.bdate FROM Project
RIGHT JOIN Department ON Project.dno = Department.dno
RIGHT JOIN Employee ON Employee.ssn = Department.mgrssn
WHERE Project.plocation = 'Berlin';

SELECT E1.fname, E1.fname, E2.fname, E2.lname FROM Employee E1
RIGHT JOIN Employee E2 ON E1.superssn = E2.ssn;

SELECT* FROM Employee 
RIGHT JOIN Department ON Employee.dno = Department.dno
WHERE Department.dname = 'Research';

SELECT* Project.pno FROM Project
RIGHT JOIN Employee ON Employee.ssn = Project.essn
RIGHT JOIN Department ON Employee.superssn = Department.mgrssn;



SELECT DISTINCT p.pnumber FROM Project p JOIN Workson w ON p.pno = w.pno JOIN Employee e ON w.essn = e.ssn JOIN Department d ON p.dno = d.dno WHERE e.lname = 'John' OR d.mgrssn = e.ssn;

SELECT e.fname, e.lname FROM Employee e LEFT JOIN dependent d ON e.ssn = d.essn WHERE d.essn IS NULL;

SELECT e.fname, e.lname FROM Employee e JOIN dependent d ON e.ssn = d.essn WHERE e.fname = d.dependentname AND e.sex = d.sex;

SELECT MAX(salary) AS max_salary, MIN(salary) AS min_salary FROM Employee;

SELECT COUNT(DISTINCT salary) AS distinct_salary_count FROM Employee;
 
CREATE INDEX idx_employee_fname ON Employee(fname);

CREATE VIEW EmployeeView AS SELECT fname, salary FROM Employee;

CREATE VIEW EmployeeProjectView AS SELECT e.fname, e.dno AS deptid, p.pnumber AS projectnumber FROM Employee e JOIN Workson w ON e.ssn = w.essn;

SELECT SUM(salary) AS total_salary_paid FROM Employee;

SELECT MIN(salary),MAX(salary),AVG(salary) from Employee;

SELECT fname, lname FROM Employee WHERE bdate BETWEEN '2001-06-30' AND '2001-12-30';