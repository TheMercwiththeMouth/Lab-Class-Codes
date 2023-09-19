CREATE DATABASE 106121077_Lab05;
USE 106121077_Lab05;

CREATE TABLE Employee(
    EmpId INT,
    LastName VARCHAR(255),
    FirstName VARCHAR(255),
    Email TEXT,
    Department VARCHAR(255),
    Designation VARCHAR(255),
    DOJ DATE,
    PhoneNumber TEXT
);
DESCRIBE Employee;

INSERT INTO Employee VALUES(121, "Doe", "John", "johndoe53@gmail.com", "Mathematics", "Asst. Professor", "2003-06-21", "9740315728");
INSERT INTO Employee VALUES(125, "Masterson", "Jane", "janemaster@gmail.com", "Physics", "Associate Professor", "2003-02-03", "99004512");
INSERT INTO Employee VALUES(127, "Swift", "Taylor", "tswift@gmail.com", "Chemistry", "Research Scholar", "2001-04-11", "987654321");
INSERT INTO Employee VALUES(128, "Melville", "Herman", "peeweeherman@gmail.com", "Mathematics", "Professor", "2005-08-22", "6731315728");
INSERT INTO Employee VALUES(129, "Conrad", "Kate", "smellybelly@gmail.com", "Physics", "Asst. Professor", "2000-11-12", "123456789");

CREATE TABLE EmployeeLog(
  QuestionID INT,
  Row_Count INT,
  Date DATE,
  User VARCHAR(255),
  Action TEXT
);
--Question a: Create a trigger that will calculate the number of rows that have been inserted till now--

SET @Row_Count=0;
DELIMITER $$
CREATE TRIGGER Trigger1 AFTER INSERT ON Employee
FOR EACH ROW
BEGIN
  SET @Row_Count= @Row_Count+1;
END $$
DELIMITER ;
SELECT @Row_Count;

--Question 2: Create a trigger that displays a message prior to an insert operation on the Employee Table--
SET @DisplayMessage=NULL;
DELIMITER $$
CREATE TRIGGER Trigger2 BEFORE INSERT ON Employee
FOR EACH ROW
BEGIN
  SET @DisplayMessage = "You are inserting";
  SELECT @DisplayMessage;
END $$
DELIMITER ;


INSERT INTO Employee VALUES(129, "Mercia", "Melvin", "merciwerciwoo@gmail.com", "Physics", "Associate Professor", "2000-10-22", "123456889");
