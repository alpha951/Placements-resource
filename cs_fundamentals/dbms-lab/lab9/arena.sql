CREATE TABLE Activities (
  ActivityID	int NOT NULL,
  ActivityName char(30) NOT NULL default 'charity',
  PRIMARY KEY  (ActivityID)
);


INSERT INTO Activities (ActivityID, ActivityName) VALUES (1, 'Save the Whales');
INSERT INTO Activities (ActivityID, ActivityName) VALUES (2, 'Greenpeace');
INSERT INTO Activities (ActivityID, ActivityName) VALUES (3, 'Doctors without Borders');
INSERT INTO Activities (ActivityID, ActivityName) VALUES (4, 'Home for Aging Rock Stars');
INSERT INTO Activities (ActivityID, ActivityName) VALUES (5, 'Music in Schools');
INSERT INTO Activities (ActivityID, ActivityName) VALUES (6, 'Aids Awareness');
INSERT INTO Activities (ActivityID, ActivityName) VALUES (7, 'USO for Troops');

CREATE TABLE Performers (
  PerformerID int NOT NULL default '0',
  PerformerName char(20) NOT NULL default '',
  Street char(20) NOT NULL default '',
  City char(15) NOT NULL default '',
  State char(2) NOT NULL default '',
  Zip int NOT NULL default '0',
  ActivityID int default '0',
  PRIMARY KEY  (PerformerID),
  FOREIGN KEY(ActivityID) REFERENCES Activities(ActivityID));



INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(1, 'Harry Chapin', 'Main St', 'Scranton', 'PA', 43243, 3);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(2, 'Billy Joel', '42 Street', 'New York', 'NY', 54354, 2);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(3, 'James Taylor', '1 Mud Slide Slim', 'Boston', 'MA', 83432, 5);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(4, 'Harry Connick', 'Sinatra Way', 'New York', 'NY', 42432, 1);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(5, 'Tony Bennett', 'Left His Heart', 'San Francisco', 'NY', 43243, 7);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(7, 'Jimmy Buffett', 'WastingA Way', 'Margaritaville', 'NY', 21323, 3);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(8, 'John', '47 Street', 'New York', 'NY', 54356, 3);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(9, 'Rapier', '41 Street', 'New York', 'NY', 54342, 3);
INSERT INTO Performers (PerformerID, PerformerName, Street, City, State, Zip, ActivityID) VALUES 
(10, 'Leisl', '39 Street', 'New York', 'NY', 54376, 3);



CREATE TABLE Arenas (
  ArenaID int NOT NULL,
  ArenaName char(20) NOT NULL default '',
  City char(15) NOT NULL default '',
  ArenaCapacity int NOT NULL default '0',
  PRIMARY KEY  (arenaID)
);




INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (1, 'Civic Arena', 'Pittsburgh', 18200);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (2, 'Carolina Coliseum', 'Columbia', 12000);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (3, 'Alumni Hall', 'Annapolis', 6000);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (4, 'Radio City Music', 'New York', 4400);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (5, 'Riverfront Coliseum', 'Cincinnati', 21000);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (6, 'Charlotte Coliseum', 'Charlotte', 24000);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (7, 'Roanoke Pavillion', 'Roanoke', 8900);
INSERT INTO Arenas (ArenaID, ArenaName, City, ArenaCapacity) VALUES (8, 'Comcast Center', 'Washington', 21242);



CREATE TABLE Concerts (
  PerformerID int NOT NULL default '0',
  ArenaID int NOT NULL default '0',
  ConcertDate date NOT NULL default '2006-01-01',
  TicketPrice int NOT NULL,
  PRIMARY KEY  (PerformerID,ArenaID),
  FOREIGN KEY (PerformerID) REFERENCES Performers(PerformerID),
  FOREIGN KEY (ArenaID) REFERENCES Arenas(ArenaID)
);




INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (1, 4, '2005-06-12', '25');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (1, 7, '2005-09-21', '23');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (1, 1, '2005-09-17', '32');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (1, 6, '2005-09-11', '25');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (2, 2, '2005-08-11', '21');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (2, 4, '2005-09-18', '26');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (2, 5, '2005-09-21', '22');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (2, 7, '2005-09-11', '31');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (3, 1, '2005-09-11', '22');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (3, 2, '2005-09-16', '21');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (3, 4, '2005-09-01', '29');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (4, 4, '2005-09-11', '31');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (4, 5, '2005-09-17', '24');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (4, 6, '2005-09-18', '17');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (5, 2, '2005-09-11', '22');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (5, 4, '2005-09-18', '31');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (5, 6, '2005-09-01', '25');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (7, 2, '2005-09-11', '21');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (7, 4, '2005-09-18', '31');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (7, 7, '2005-09-01', '28');
INSERT INTO Concerts (PerformerID, ArenaID, ConcertDate, TicketPrice) VALUES (7, 6, '2005-09-16', '25');




