CREATE database org;
show databases;
use org;

create table worker(
	worker_id int not null primary key auto_increment,
    first_name char(25),
    last_name char(25),
    salary int(15),
    joining_date datetime,
    department char(25)
);

insert into worker
		(worker_id, first_name, last_name, salary, joining_date, department) values
        (001, 'Monika', 'Arora', 100000, '14-02-20 09.00.00', 'HR'),
        (002, 'Niharika', 'Verma', 80000, '14-06-20 09.00.00', 'Admin'),
        (003, 'Vishal', 'Singhal', 300000, '14-02-20 09.00.00', 'HR'),
        (004, 'Amitabh', 'Singh', 500000, '14-04-11 09.00.00', 'Admin'),
        (005, 'Vipul', 'Diwan', 200000, '14-06-11 09.00.00', 'Account'),
        (006, 'Satish', 'Kumar', 750000, '14-01-20 09.00.00', 'Account'),
        (007, 'Gitika', 'Chauhan', 90000, '14-02-11 09.00.00', 'Admin');
        
select * from worker;

create table bonus(
	worker_ref_id int,
    bonus_amount int,
    bonus_date datetime,
    foreign key (worker_ref_id)
		references worker(worker_id)
        on delete cascade
);

insert into bonus 
		(worker_ref_id, bonus_amount, bonus_date) values
        (001, 4000, '16-02-21'),
        (002, 5000, '16-02-21'),
        (003, 7000, '16-02-21'),
        (004, 8000, '16-02-21');

select *from bonus;

create table title(
	worker_ref_id int,
    worker_title char(25),
    affected_from datetime,
    foreign key (worker_ref_id)
		references worker(worker_id)
		on delete cascade
);

insert into title
	(worker_ref_id, worker_title, affected_from) values
	(001, 'Manager', '2021-02-20 00.00.00'),
    (002, 'Executive', '2020-02-20 00.00.00'),
    (003, 'Manager', '2023-02-20 00.00.00');

select *from title;
SELECT * FROM worker WHERE salary > 100000;
















