DELIMITER $$
CREATE PROCEDURE InitDeptStats()
begin
    INSERT INTO DEPT_STATS (SELECT Dno, COUNT(*), AVG(Salary) FROM EMPLOYEE GROUP BY Dno);
end$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER INSERTDeptStats 
AFTER INSERT ON EMPLOYEE FOR EACH ROW 
BEGIN 
    IF (New.Dno IS NOT NULL) THEN
        UPDATE DEPT_STATS SET 
        Emp_count = Emp_count + 1,
        Avg_salary = (SELECT AVG(Salary) FROM EMPLOYEE GROUP BY Dno HAVING EMPLOYEE.Dno = New.Dno) 
        WHERE DEPT_STATS.Dnumber = New.Dno;
    END IF;
END; $$

DELIMITER $$
CREATE TRIGGER UPDATEDeptStats 
AFTER UPDATE ON EMPLOYEE FOR EACH ROW 
 BEGIN 
    IF (Old.Dno IS NOT NULL) THEN
        UPDATE DEPT_STATS SET 
        Emp_count = Emp_count - 1,
        Avg_salary = (SELECT AVG(Salary) FROM (SELECT * FROM EMPLOYEE WHERE Ssn <> Old.Ssn) AS E GROUP BY Dno HAVING E.Dno = Old.Dno) 
        WHERE DEPT_STATS.Dnumber = Old.Dno;
    END IF;

    IF (New.Dno IS NOT NULL) THEN
        UPDATE DEPT_STATS SET 
        Emp_count = Emp_count + 1,
        Avg_salary = (SELECT AVG(Salary) FROM EMPLOYEE GROUP BY Dno HAVING EMPLOYEE.Dno = New.Dno) 
        WHERE DEPT_STATS.Dnumber = New.Dno;
    END IF;
END; $$

DELIMITER $$
CREATE TRIGGER DELETEDeptStats 
BEFORE DELETE ON EMPLOYEE FOR EACH ROW 
 BEGIN 
    IF (Old.Dno IS NOT NULL) THEN
		DELETE FROM WORKS_ON WHERE Essn = Old.Ssn;
        UPDATE DEPT_STATS SET 
        Emp_count = Emp_count - 1,
        Avg_salary = (SELECT AVG(Salary) FROM (SELECT * FROM EMPLOYEE WHERE Ssn <> Old.Ssn) AS E GROUP BY Dno HAVING E.Dno = Old.Dno) 
        WHERE DEPT_STATS.Dnumber = Old.Dno;
    END IF;
END; $$

DELIMITER $$
CREATE TRIGGER MaxTotalHours
BEFORE INSERT ON WORKS_ON
FOR EACH ROW 
BEGIN 
    DECLARE sum decimal;
    DECLARE msg VARCHAR(100);
    SELECT SUM(Hours) INTO sum 
        FROM WORKS_ON
        WHERE Essn = New.Essn;
    IF (sum >= 40.0) THEN
        SET msg = concat('You entered ',New.Hours,
            '. You currently work ',sum,
            '. You are over 40 hours.');
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = msg;
    END IF;
END; $$

DELIMITER $$
CREATE FUNCTION PayLevel(empSSN CHAR(9)) 
RETURNS varchar(100) 
BEGIN
    DECLARE avgSal DECIMAL(10,2);
    DECLARE empDno INT(2);
    DECLARE empSal DECIMAL(10,2);
    SELECT Dno, Salary INTO empDno, empSal FROM EMPLOYEE WHERE Ssn = empSSN;
    SELECT AVG(Salary) INTO avgSal FROM EMPLOYEE GROUP BY Dno HAVING EMPLOYEE.Dno = empDno;
    
    if empSal < avgSal then return 'Below Average'; end if;
    if empSal > avgSal then return 'Above Average'; end if;
    return 'Average';
END$$
DELIMITER ;