CREATE DATABASE 106121077_DBMS;
USE 106121077_DBMS;

CREATE TABLE Department
(dept_id int, 
 dept_name varchar(255)
);

CREATE TABLE Student
(
    rollno int, 
    name varchar(255),
    gender varchar(255), 
    mark1 int, 
    mark2 int,
    mark3 int,
    total int,
    average int,
    dept_id int
);

//DESCRIBE Student - to view the TABLE

CREATE TABLE Staff
(
    staff_id int,
    name varchar(255),
    designation varchar(255),
    qualification varchar(255),
    dept_id int
);

CREATE TABLE Tutor
(
    rollno int,
    staff_id int
);

//To insert values into the table
insert into Student
values(1, "Melvin", "M", 25, 30, 45, NULL, NULL, 123);

1. Calculate the total and average mark of each student while entering the marks to insert the tuple in the student table.
//To calculate the Total and Average COLUMNS
UPDATE Student
SET total = mark1 + mark2 + mark3;

UPDATE Student
SET average = total/3;

2. Display the student details under the department 'CSE'.
SELECT COUNT(*) FROM Student
WHERE dept_id=123;




























































TERMINAL PREVIOUS
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 9
Server version: 8.0.33-0ubuntu0.20.04.2 (Ubuntu)

Copyright (c) 2000, 2023, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> CREATE DATABASE 106121077_DBMS;
Query OK, 1 row affected (0.08 sec)

mysql> USE DATABASE 106121077_DBMS
ERROR 1049 (42000): Unknown database 'DATABASE'
mysql> USE 106121077_DBMS;
Database changed
mysql> CREATE TABLE Question1
    -> 
[1]+  Stopped                 sudo mysql -u root -p
nitt@nitt-OptiPlex-390:~$ sudo mysql -u root -p
Enter password: 
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 10
Server version: 8.0.33-0ubuntu0.20.04.2 (Ubuntu)

Copyright (c) 2000, 2023, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> use 106121077_DBMS
Database changed
mysql> create table Department
    -> (dept_id int,
    -> dept_name varchar(255));
Query OK, 0 rows affected (0.63 sec)

mysql> DESCRIBE Department
    -> ;
+-----------+--------------+------+-----+---------+-------+
| Field     | Type         | Null | Key | Default | Extra |
+-----------+--------------+------+-----+---------+-------+
| dept_id   | int          | YES  |     | NULL    |       |
| dept_name | varchar(255) | YES  |     | NULL    |       |
+-----------+--------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> create table Student
    -> (rollno int,
    -> name varchar(255)
    -> , gender varchar(255),
    -> mark1 int,
    -> mark2 int,
    -> mark3 int,
    -> total int,
    -> average float,
    -> dept_id int);
Query OK, 0 rows affected (0.34 sec)

mysql> DESCRIBE Student
    -> ;
+---------+--------------+------+-----+---------+-------+
| Field   | Type         | Null | Key | Default | Extra |
+---------+--------------+------+-----+---------+-------+
| rollno  | int          | YES  |     | NULL    |       |
| name    | varchar(255) | YES  |     | NULL    |       |
| gender  | varchar(255) | YES  |     | NULL    |       |
| mark1   | int          | YES  |     | NULL    |       |
| mark2   | int          | YES  |     | NULL    |       |
| mark3   | int          | YES  |     | NULL    |       |
| total   | int          | YES  |     | NULL    |       |
| average | float        | YES  |     | NULL    |       |
| dept_id | int          | YES  |     | NULL    |       |
+---------+--------------+------+-----+---------+-------+
9 rows in set (0.00 sec)

mysql> create table Staff
    -> (staff_id int,
    -> name varchar(255),
    -> designation varchar(255),
    -> qualification varchar(255),
    -> dept_id int);
Query OK, 0 rows affected (0.33 sec)

mysql> create table Tutor
    -> (rollno int,
    -> staff_id int);
Query OK, 0 rows affected (0.33 sec)

mysql> insert into Student
    -> values(1, Melvin, M, 25, 45, 20, NULL, NULL, 123);
ERROR 1054 (42S22): Unknown column 'Melvin' in 'field list'
mysql> insert into Student
    -> values(1, "Melvin", M, 25, 40, 35, NULL, NULL, 123);
ERROR 1054 (42S22): Unknown column 'M' in 'field list'
mysql> insert into Student
    -> values(1, "Melvin", "M", 25, 30, 45, NULL, NULL, 123);
Query OK, 1 row affected (0.18 sec)

mysql> insert into Student
    -> values(2, "Mercia", "F", 40, 45, 45, NULL, NULL, 124);
Query OK, 1 row affected (0.08 sec)

mysql> insert into Student
    -> values(3, "Vijay", "M
    "> ", 30, 30, 30, NULL, NULL, 125);
Query OK, 1 row affected (0.05 sec)

mysql> insert into Student
    -> values(4, "Nishith", "M", 20, 25, 33, NULL, NULL, 123);
Query OK, 1 row affected (0.07 sec)

mysql> insert into Student
    -> values(5, "Elizabeth", "F", 50, 30, 40, NULL, NULL, 124);
Query OK, 1 row affected (0.09 sec)

mysql> UPDATE Student 
    -> SET sum(mark1 + mark2 + mark3) as total
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'sum(mark1 + mark2 + mark3) as total' at line 2
mysql> UPDATE Student
    -> SET sum(mark1, mark2, mark3) as total
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'sum(mark1, mark2, mark3) as total' at line 2
mysql> UPDATE Student
    -> SET total = mark1 + mark2 + mark3;
Query OK, 5 rows affected (0.21 sec)
Rows matched: 5  Changed: 5  Warnings: 0

mysql> UPDATE Student
    -> SET average = total/3;
Query OK, 5 rows affected (0.07 sec)
Rows matched: 5  Changed: 5  Warnings: 0

mysql> select* from student
    -> ;
ERROR 1146 (42S02): Table '106121077_DBMS.student' doesn't exist
mysql> select* from Student
    -> ;
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
| rollno | name      | gender | mark1 | mark2 | mark3 | total | average | dept_id |
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
|      1 | Melvin    | M      |    25 |    30 |    45 |   100 | 33.3333 |     123 |
|      2 | Mercia    | F      |    40 |    45 |    45 |   130 | 43.3333 |     124 |
|      3 | Vijay     | M
     |    30 |    30 |    30 |    90 |      30 |     125 |
|      4 | Nishith   | M      |    20 |    25 |    33 |    78 |      26 |     123 |
|      5 | Elizabeth | F      |    50 |    30 |    40 |   120 |      40 |     124 |
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
5 rows in set (0.02 sec)

mysql> DELETE FROM Student
    -> WHERE rollno=3;
Query OK, 1 row affected (0.11 sec)

mysql> select* from Student;
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
| rollno | name      | gender | mark1 | mark2 | mark3 | total | average | dept_id |
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
|      1 | Melvin    | M      |    25 |    30 |    45 |   100 | 33.3333 |     123 |
|      2 | Mercia    | F      |    40 |    45 |    45 |   130 | 43.3333 |     124 |
|      4 | Nishith   | M      |    20 |    25 |    33 |    78 |      26 |     123 |
|      5 | Elizabeth | F      |    50 |    30 |    40 |   120 |      40 |     124 |
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
4 rows in set (0.00 sec)

mysql> insert into Department
    -> values(123, "CSE");
Query OK, 1 row affected (0.06 sec)

mysql> insert into Department
    -> values(124, "ECE");
Query OK, 1 row affected (0.08 sec)

mysql> SELECT COUNT(*) FROM Student
    -> WHERE dept_id=123;
+----------+
| COUNT(*) |
+----------+
|        2 |
+----------+
1 row in set (0.05 sec)

mysql> SELECT COUNT(*) FROM Student
    -> WHERE average>30;
+----------+
| COUNT(*) |
+----------+
|        3 |
+----------+
1 row in set (0.02 sec)

mysql> SELECT* from Student
    -> WHERE average>40
    -> ;
+--------+--------+--------+-------+-------+-------+-------+---------+---------+
| rollno | name   | gender | mark1 | mark2 | mark3 | total | average | dept_id |
+--------+--------+--------+-------+-------+-------+-------+---------+---------+
|      2 | Mercia | F      |    40 |    45 |    45 |   130 | 43.3333 |     124 |
+--------+--------+--------+-------+-------+-------+-------+---------+---------+
1 row in set (0.00 sec)

mysql> insert into Staff
    -> values(1, "Sitara", "AIML", "BTECH", 123);
Query OK, 1 row affected (0.10 sec)

mysql> insert into Staff
    -> values(2, "Sai Krishna", "DSA", 
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 2
mysql> insert into Staff
    -> values(2, "Sai Krishna", "DSA", "PhD", 123);
Query OK, 1 row affected (0.06 sec)

mysql> insert into Staff
    -> values(3, "Nitya", "Networks", "MTech", 124);
Query OK, 1 row affected (0.06 sec)

mysql> insert into Tutor
    -> values(1, 1);
Query OK, 1 row affected (0.07 sec)

mysql> insert into Tutor
    -> values(2, 2);
Query OK, 1 row affected (0.05 sec)

mysql> insert into Tutor
    -> values(4, 2);
Query OK, 1 row affected (0.06 sec)

mysql> insert into Tutor
    -> values(5, 3);
Query OK, 1 row affected (0.09 sec)

mysql> SELECT COUNT(*) from Student RIGHT JOIN Tutor ON staff_id = 2;
+----------+
| COUNT(*) |
+----------+
|       10 |
+----------+
1 row in set (0.00 sec)

mysql> SELECT COUNT(*)
    -> FROM Tutor 
    -> WHERE staff_id = 2;
+----------+
| COUNT(*) |
+----------+
|        2 |
+----------+
1 row in set (0.00 sec)

mysql> SELECT COUNT(*) 
    -> FROM Student
    -> RIGHT JOIN Department
    -> ON Department.dept_id = Student.dept_id
    -> WHERE Department.dept_name="CSE";
+----------+
| COUNT(*) |
+----------+
|        2 |
+----------+
1 row in set (0.00 sec)

mysql> SELECT* FROM Staff
    -> RIGHT JOINN Department
    -> ON Department.dept_id = Staff. dept_id
    -> WHERE Department.dept_name = "CSE";
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'JOINN Department
ON Department.dept_id = Staff. dept_id
WHERE Department.dept_na' at line 2
mysql> SELECT* from Staff
    -> RIGHT JOIN Department
    -> ON Department.dept_id = Staff.dept_id
    -> WHERE Department.dept_name = "CSE";
+----------+-------------+-------------+---------------+---------+---------+-----------+
| staff_id | name        | designation | qualification | dept_id | dept_id | dept_name |
+----------+-------------+-------------+---------------+---------+---------+-----------+
|        2 | Sai Krishna | DSA         | PhD           |     123 |     123 | CSE       |
|        1 | Sitara      | AIML        | BTECH         |     123 |     123 | CSE       |
+----------+-------------+-------------+---------------+---------+---------+-----------+
2 rows in set (0.00 sec)

mysql> SELECT COUNT(DISTINCT(designation)) as desig_count from Staff;
+-------------+
| desig_count |
+-------------+
|           3 |
+-------------+
1 row in set (0.03 sec)

mysql> SELECT COUNT(DISCOUNT(dept_name)) as dept_count from Department
    -> ;
ERROR 1305 (42000): FUNCTION 106121077_DBMS.DISCOUNT does not exist
mysql> select count(distinct(dept_name)) as dept_count from Department
    -> ;
+------------+
| dept_count |
+------------+
|          2 |
+------------+
1 row in set (0.00 sec)

mysql> SELECT* from Student
    -> WHERE name = "M%";
Empty set (0.00 sec)

mysql> SELECT* from Student
    -> WHERE name LIKE "M%";
+--------+--------+--------+-------+-------+-------+-------+---------+---------+
| rollno | name   | gender | mark1 | mark2 | mark3 | total | average | dept_id |
+--------+--------+--------+-------+-------+-------+-------+---------+---------+
|      1 | Melvin | M      |    25 |    30 |    45 |   100 | 33.3333 |     123 |
|      2 | Mercia | F      |    40 |    45 |    45 |   130 | 43.3333 |     124 |
+--------+--------+--------+-------+-------+-------+-------+---------+---------+
2 rows in set (0.02 sec)

mysql> SELECT Department.dept_name, Tutor.rollno, Tutor.staff_id
    -> FROM Student, Department, Tutor
    -> WHERE Student.rollno = Tutor.rollno
    -> AND Student.dept_id = Department.dept_id;
+-----------+--------+----------+
| dept_name | rollno | staff_id |
+-----------+--------+----------+
| CSE       |      1 |        1 |
| ECE       |      2 |        2 |
| CSE       |      4 |        2 |
| ECE       |      5 |        3 |
+-----------+--------+----------+
4 rows in set (0.03 sec)

mysql> SELECT Department.dept_name, Tutor.rollno, Tutor.staff_id
    -> FROM Student, Department, Tutor
   SELECT Department.dept_name, Tutor.rollno, Tutor.staff_id
^C
mysql>     -> FROM Student, Department, Tutor
    ->     -> WHERE Student.rollno = Tutor.rollno
    ->     -> AND Student.dept_id = Department.dept_id
    -> AND Student.name LIKE "M%";
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '-> FROM Student, Department, Tutor
    -> WHERE Student.rollno = Tutor.rollno
  ' at line 1
mysql> Select Department.dept_name, Tutor.rollno, Tutor.staff_id
    -> FROM Student, Department, Tutor
    -> WHERE Student.rollno = Tutor.rollno
    -> AND Student.dept_id = Department.dept_id
    -> AND Student.name LIKE "M%";
+-----------+--------+----------+
| dept_name | rollno | staff_id |
+-----------+--------+----------+
| CSE       |      1 |        1 |
| ECE       |      2 |        2 |
+-----------+--------+----------+
2 rows in set (0.00 sec)

mysql> SELECT* from Student
    -> WHERE gender ="M";
+--------+---------+--------+-------+-------+-------+-------+---------+---------+
| rollno | name    | gender | mark1 | mark2 | mark3 | total | average | dept_id |
+--------+---------+--------+-------+-------+-------+-------+---------+---------+
|      1 | Melvin  | M      |    25 |    30 |    45 |   100 | 33.3333 |     123 |
|      4 | Nishith | M      |    20 |    25 |    33 |    78 |      26 |     123 |
+--------+---------+--------+-------+-------+-------+-------+---------+---------+
2 rows in set (0.00 sec)

mysql> Select* from Student
    -> WHERE gender = "F";
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
| rollno | name      | gender | mark1 | mark2 | mark3 | total | average | dept_id |
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
|      2 | Mercia    | F      |    40 |    45 |    45 |   130 | 43.3333 |     124 |
|      5 | Elizabeth | F      |    50 |    30 |    40 |   120 |      40 |     124 |
+--------+-----------+--------+-------+-------+-------+-------+---------+---------+
2 rows in set (0.00 sec)

mysql> SELECT Department.dept_id, count(Student.rollno), Student.gender
    -> FROM Department 
    -> RIGHT JOIN Student
    -> ON Department.dept_id = Student.dept_id 
    -> GROUP BY Department.dept_name, Student.gender;
ERROR 1055 (42000): Expression #1 of SELECT list is not in GROUP BY clause and contains nonaggregated column '106121077_DBMS.Department.dept_id' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by
mysql> SELECT dept_id, gender, COUNT(*)
    -> FROM Student
    -> GROUP BY dept_id, gender;
+---------+--------+----------+
| dept_id | gender | COUNT(*) |
+---------+--------+----------+
|     123 | M      |        2 |
|     124 | F      |        2 |
+---------+--------+----------+
2 rows in set (0.02 sec)

mysql> insert into Student
    -> values(3, "Vijay", "M", 30, 30, 30, 90, 30, 124);
Query OK, 1 row affected (0.08 sec)

mysql> insert into Student
    -> values(6, "Soya", "F", 40, 40, 40, 120, 40, 123);
Query OK, 1 row affected (0.07 sec)

mysql> SELECT dept_id, gender, COUNT(*)
    -> FROM Student
    -> GROUP BY dept_id, gender;
+---------+--------+----------+
| dept_id | gender | COUNT(*) |
+---------+--------+----------+
|     123 | M      |        2 |
|     124 | F      |        2 |
|     124 | M      |        1 |
|     123 | F      |        1 |
+---------+--------+----------+
4 rows in set (0.00 sec)

mysql> insert into Staff
    -> values(4, "Mohan", "Professor", "GED", 123);
Query OK, 1 row affected (0.06 sec)

mysql> insert into Staff
    -> values(5, "Rajeshwari", "Professor", "PhD", 124);
Query OK, 1 row affected (0.06 sec)

mysql> insert into Staff
    -> values(8, "Mala", "Professor", "KG", 123);
Query OK, 1 row affected (0.06 sec)

mysql> CREATE VIEW as PROFVIEW
    -> SELECT* FROM Staff
    -> WHERE ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'as PROFVIEW
SELECT* FROM Staff
WHERE' at line 1
mysql> CREATE VIEW ProfView AS
    -> SELECT* FROM Staff
    -> WHERE qualification = "Professor";
Query OK, 0 rows affected (0.23 sec)

mysql> select Department.dept_name, Tutor.rollno, Tutor.staff_id, Staff.name 
    -> FROM Student, Department, Tutor
    -> ,Staff
    -> WHERE Student.rollno = Tutor.rollno 
    -> AND Student.dept_id = Department.dept_id 
    -> AND Staff. staff_id = Tutor.staff_id
    -> AND Student.name LIKE "M%";
+-----------+--------+----------+-------------+
| dept_name | rollno | staff_id | name        |
+-----------+--------+----------+-------------+
| CSE       |      1 |        1 | Sitara      |
| ECE       |      2 |        2 | Sai Krishna |
+-----------+--------+----------+-------------+
2 rows in set (0.00 sec)
