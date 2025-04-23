# SQLStructured Query Language) commands

## categories
1. DDL (Data Definition Language): These commands define and modify the structure of database objects like tables, schemas, and indexes.

    CREATE: Used to create database objects (e.g., tables, views).
    ALTER: Used to modify existing database objects.
    DROP: Used to delete database objects.
    TRUNCATE: Used to remove all records from a table, but not the table itself.
    RENAME: Used to rename database objects.
    
2. DML (Data Manipulation Language): These commands deal with the manipulation of data within tables.

    SELECT: Used to query data from the database.
    INSERT: Used to insert new data into a table.
    UPDATE: Used to modify existing data in a table.
    DELETE: Used to remove data from a table.
    
3. DCL (Data Control Language): These commands manage permissions and access control in the database.

    GRANT: Used to give privileges to users.
    REVOKE: Used to remove privileges from users.
    
4. TCL (Transaction Control Language): These commands manage transactions in a database.

    COMMIT: Used to save the changes made during the current transaction.
    ROLLBACK: Used to undo the changes made during the current transaction.
    SAVEPOINT: Sets a point in a transaction that can be rolled back to.
    SET TRANSACTION: Used to configure a transaction's properties.

* sudo mysql -u root -p
* create database my_db;
* show databases;
* use my_db;

# 1

## create table
* create table my_table(
	id int primary key,
	name varchar(50),
	age int
	);
* show tables;
* desc my_table;

## alter table
* alter table my_table add weight int ; //adds new column
* alter table my_table drop weight ; //delete that column
* alter table my_table rename column weight to mass ; //rename column name
* alter table my_table rename to my_record ; //rename the table it self
* alter table my_record modify column name varchar(100) ; //modify existing column datatype 

## drop table
* drop database my_db ;
* drop table my_table ;

# 2

## select
* select * form my_table; 

## insert
* insert into my_table (id, name, age) values (1, "xyz", 20), (2, "abc", 24);
* insert into my_table values (3, "pqr", 30);

## update
* update my_table set name = "stu" where id = 1; //update the existing record of id = 1

## delete
* delete from my_table where id = 1; //delete the existing record of id = 1

# 3

## Aggregate Functions in SQL
* Aggregate functions in SQL are used to perform a calculation on a set of values and return a single result. These functions are particularly useful when working with groups of data, especially in combination with the GROUP BY

1. COUNT()

The COUNT() function returns the number of rows that match a specified condition or count all rows in a table.

    Syntax:

SELECT COUNT(column_name) FROM table_name WHERE condition;

Example: Count the number of employees in the "Employees" table:

SELECT COUNT(*) FROM Employees;

Note: COUNT(*) counts all rows, including rows with NULL values. If you want to count rows with non-NULL values, specify the column:

    SELECT COUNT(employee_id) FROM Employees;

2. SUM()

The SUM() function calculates the total sum of a numeric column.

    Syntax:

SELECT SUM(column_name) FROM table_name WHERE condition;

Example: Calculate the total salary of all employees in the "Employees" table:

    SELECT SUM(salary) FROM Employees;

    Note: The SUM() function ignores NULL values in the column.

3. AVG()

The AVG() function returns the average (mean) value of a numeric column.

    Syntax:

SELECT AVG(column_name) FROM table_name WHERE condition;

Example: Calculate the average salary of all employees in the "Employees" table:

    SELECT AVG(salary) FROM Employees;

    Note: AVG() also ignores NULL values.

4. MIN()

The MIN() function returns the smallest value in a specified column.

    Syntax:

SELECT MIN(column_name) FROM table_name WHERE condition;

Example: Find the minimum salary in the "Employees" table:

    SELECT MIN(salary) FROM Employees;

5. MAX()

The MAX() function returns the largest value in a specified column.

    Syntax:

SELECT MAX(column_name) FROM table_name WHERE condition;

Example: Find the maximum salary in the "Employees" table:

SELECT MAX(salary) FROM Employees;






