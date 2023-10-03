CREATE DATABASE 106121077_Lab6;
USE 106121077_Lab6;

--Create the table Pet--
CREATE TABLE Pet(
    name VARCHAR(255),
    Owner VARCHAR(255),
    Phone TEXT,
    Species VARCHAR(255),
    Sex VARCHAR(1),
    Birth_Date DATE,
    Death_Date DATE
);

CREATE TABLE Event(
    name VARCHAR(255), 
    date DATE,
    type TEXT,
    remark TEXT
);

INSERT INTO Pet VALUES("Fluffy", "Harold Regan", "789543210", "cat", "f", "1993-02-04", NULL);
INSERT INTO Pet VALUES("Claws", "Gwen Cappaloo", "875643219 ", "cat", "m", "1994-03-17", NULL);
INSERT INTO Pet VALUES("Buffy", "Harold Regan", "789543210", "dog", "f", "1989-05-13", NULL);
INSERT INTO Pet VALUES("Fang", "Benny Robert", "987654321", "dog", "m", "1990-08-27", NULL);
INSERT INTO Pet VALUES("Bowser", "Diane Charles", "985423111", "dog", "m", "1979-08-31", "1995-07-29");
INSERT INTO Pet VALUES("Chirpy", "Gwen Cappaloo", "875643219", "bird", "f", "1998-09-11", NULL);
INSERT INTO Pet VALUES("Whistler", "Gwen Cappaloo", "875643219", "bird", "f", "1997-12-09", NULL);
INSERT INTO Pet VALUES("Slim", "Benny Robert", "987654321", "snake", "m", "1996-04-29", NULL);
INSERT INTO Pet VALUES("Puffball", "Diane Daniel", "342567812", "hamster", "f", "1999-03-30", NULL);


INSERT INTO Event VALUES ('Fluffy', '1995-05-15', 'Litter', '4 Kittens, 3 Female, 1 Male');
INSERT INTO Event VALUES ('Buffy', '1993-06-23', 'Litter', '5 Puppies, 2 Female, 3 Male');
INSERT INTO Event VALUES ('Buffy', '1994-06-19', 'Litter', '3 Puppies, 3 Female');
INSERT INTO Event VALUES ('Chirpy', '1999-03-21', 'Vet', 'Needed beak straightened');
INSERT INTO Event VALUES ('Slim', '1997-08-03', 'Vet', 'Broken rib');
INSERT INTO Event VALUES ('Bowser', '1991-10-12', 'Kennel', NULL);
INSERT INTO Event VALUES ('Fang', '1991-10-12', 'Kennel', NULL);
INSERT INTO Event VALUES ('Fang', '1998-08-28', 'Birthday', 'Gave him a new chew toy');
INSERT INTO Event VALUES ('Claws', '1998-03-17', 'Birthday', 'Gave him a new flea collar');
INSERT INTO Event VALUES ('Whistler', '1998-12-09', 'Birthday', 'First birthday');

--Question 1: Modify the structure/create new by splitting the column name to( First name and Last name) and copy the values appropriately into it.--
ALTER TABLE Pet
ADD COLUMN FirstName VARCHAR(255) AFTER Owner;
ALTER TABLE Pet
ADD COLUMN LastName VARCHAR(255) AFTER FirstName;
UPDATE Pet
SET FirstName = REPLACE(Owner, SUBSTRING_INDEX(Owner, ' ', -1),''), LastName =  SUBSTRING_INDEX(Owner, ' ', -1);
ALTER TABLE Pet
DROP COLUMN Owner;

--Question 2: List the Animals that were born during or after 1998--
SELECT name FROM Pet
WHERE Birth_Date >"1997-12-31";

--Question 3: List the pets that were snake or bird--
SELECT name FROM Pet
WHERE Species = "snake" OR Species = "bird";

--Question 4: list each group of species based on its birthdate (oldest first)--
SELECT Species, MIN(Birth_Date) FROM Pet
GROUP BY Species;

--Question 5: Display the age of every species as alias
SELECT TIMESTAMPDIFF(YEAR, Birth_Date, CURDATE()) AS Alias FROM Pet
WHERE Death_Date IS NULL;

--Question 6: Determine age at death for animals that have died.--
SELECT name, TIMESTAMPDIFF(YEAR, Birth_Date, Death_Date) AS Age_at_Death FROM Pet
WHERE Death_Date IS NOT NULL;

--Question 7: Finding animals with birthdays in the current month--
SELECT name, Birth_Date FROM Pet
WHERE MONTH(Birth_Date) = MONTH(NOW());

--Question 8: To find names containing a “f”--
SELECT name FROM Pet
WHERE name LIKE "%f%";

--Question 9: Find out how many pets each owner has:--
SELECT FirstName, LastName, COUNT(*) FROM Pet
GROUP BY FirstName, LastName;

--Question 10: Number of animals per combination of species and sex--
SELECT Species, Sex, COUNT(*) FROM Pet
GROUP BY Species, Sex;

--Question 11: Find out the ages at which each pet had its litters--
SELECT Pet.name, TIMESTAMPDIFF(YEAR, Birth_Date, Event.Date) AS Age_At_Birth FROM Event
LEFT JOIN Pet
ON Pet.name = Event.name
WHERE type = "Litter";

--Question 12: Find breeding pairs among the pets
SELECT Pet1.name, Pet2.name FROM Pet Pet1
RIGHT JOIN Pet Pet2
ON Pet1.Species = Pet2.Species
WHERE Pet1.Sex <> Pet2.Sex;

--Question 13: Create a Trigger that adds “+47” to all Phone numbers in the pet table.
--Test and see if the Trigger works properly by inserting and updating some data in the table.--
DELIMITER $$
CREATE TRIGGER Trigger1
BEFORE UPDATE ON Pet
FOR EACH ROW
BEGIN
  SET NEW.Phone = CONCAT('+47', NEW.Phone);
END $$
DELIMITER ;

UPDATE Pet
SET Pet.name = Pet.name
WHERE Pet.name IS NOT NULL;

--Question 14: Create a procedure for Pet table that will return oldest and youngest pet.
DELIMITER $$
CREATE PROCEDURE Procedure1()
BEGIN
SELECT name AS Oldest_Pet FROM Pet
WHERE Birth_Date = (SELECT MAX(Birth_Date) FROM Pet);
SELECT name AS Youngest_Pet FROM Pet
WHERE Birth_Date = (SELECT MIN(Birth_Date) FROM Pet);
END $$
DELIMITER ;

CALL Procedure1();

--Question 15: write a function that will display age for a given pet.
DELIMITER $$
CREATE FUNCTION Function1 (Arg1 VARCHAR(255))
RETURNS INT DETERMINISTIC
BEGIN
DECLARE Age INT;
SELECT TIMESTAMPDIFF(YEAR, Birth_Date, CURDATE()) INTO Age FROM Pet
WHERE name = Arg1;
RETURN Age;
END $$
DELIMITER ;

SELECT Function1("Fluffy");