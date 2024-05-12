
CREATE TABLE cave (
  cave_id int NOT NULL AUTO_INCREMENT,
  name varchar(255) DEFAULT NULL,
  gold int NOT NULL,
  xp int NOT NULL,
  level int NOT NULL,
  conquered bool DEFAULT '0',
  PRIMARY KEY (cave_id)
); 

CREATE TABLE cave_first_name (
  first_name char(20) NOT NULL,
  PRIMARY KEY (first_name)
);
INSERT INTO cave_first_name VALUES ('Blood'),('Blue'),('Bone'),('Brave'),('Cliff'),('Cook Mt.'),('Cute'),('Danger'),('Death'),('Deep'),('Desert'),('Doom'),('Fire'),('Forrest'),('Freezy'),('Golden'),('Grave'),('Green'),('Grey'),('Haunted'),('Hero'),('Ice'),('Journeys'),('Long'),('Monster'),('Mountain'),('Ocean'),('Red'),('Rock'),('Rotten'),('Salty'),('Sir Atlas Mt.'),('Skull'),('Smelly'),('Spiky'),('Stone'),('Tooth'),('Undead'),('Wet');

CREATE TABLE cave_second_name (
  nr int NOT NULL AUTO_INCREMENT,
  second_name char(20) DEFAULT NULL,
  PRIMARY KEY (nr)
);
INSERT INTO cave_second_name VALUES (1,' Cave'),(2,' Sinkhole'),(3,' Stronghold'),(4,' Hole'),(5,' Underground'),(6,' Passage'),(7,' Valley'),(8,' Swamp'),(9,' Mist'),(10,'-Knightly Cave'),(11,'-Crawling Cave'),(12,'-Seeking Cave'),(13,'-Dripping Cave'),(14,'-Infested Cave');

CREATE TABLE cave_monster (
  cave_id int DEFAULT NULL,
  monster_id int DEFAULT NULL,
  FOREIGN KEY (cave_id) REFERENCES cave(cave_id),
  FOREIGN KEY (monster_id) REFERENCES monster(monster_id)
);


CREATE TABLE element (
  element_id int NOT NULL AUTO_INCREMENT,
  name varchar(20) NOT NULL,
  R int DEFAULT 255,
  G int DEFAULT 255,
  B int DEFAULT 255,
  PRIMARY KEY (element_id)
);
INSERT INTO element VALUES (1,'normal',200,200,200),(2,'fire',255,200,0),(3,'earth',220,150,0),(4,'water',0,150,255),(5,'blood',200,0,0),(6,'wood',100,255,0),(7,'metal',130,130,140),(8,'fairy',255,200,255),(9,'dragon',130,0,200);

CREATE TABLE element_resistance (
  element_id int NOT NULL,
  resistance_id int NOT NULL,
  FOREIGN KEY (element_id) REFERENCES element(element_id),
  FOREIGN KEY (resistance_id) REFERENCES element(element_id)
);
INSERT INTO element_resistance VALUES (1,6),(2,6),(2,2),(3,7),(3,3),(4,7),(4,4),(5,2),(5,5),(6,4),(6,6),(7,3),(7,7),(8,3),(8,4),(8,8),(9,7);

CREATE TABLE element_strength (
  element_id int NOT NULL,
  strength_id int NOT NULL,
  FOREIGN KEY (element_id) REFERENCES element (element_id),
  FOREIGN KEY (strength_id) REFERENCES element (element_id)
);
INSERT INTO element_strength VALUES (1,8),(2,7),(2,8),(3,4),(4,2),(5,1),(5,7),(6,3),(6,5),(7,6),(7,9),(8,9),(8,5),(9,1),(9,2);


CREATE TABLE element_weakness (
 element_id int NOT NULL,
 weakness_id int NOT NULL,
 FOREIGN KEY (element_id) REFERENCES element (element_id),
 FOREIGN KEY (weakness_id) REFERENCES element (element_id)
);
INSERT INTO element_weakness VALUES (1,9),(2,4),(3,6),(4,3),(5,8),(5,6),(6,7),(6,2),(7,5),(7,2),(8,2),(8,1),(8,7),(9,8),(9,5),(1,5);

CREATE TABLE hero (
  hero_id int NOT NULL AUTO_INCREMENT,
  name char(20) NOT NULL,
  level int NOT NULL,
  xp int NOT NULL,
  hp int NOT NULL,
  ap int NOT NULL,
  mp int NOT NULL,
  PRIMARY KEY (hero_id)
);

CREATE TABLE hero_magic (
  hero_id int NOT NULL,
  magic_id int NOT NULL,
  FOREIGN KEY (hero_id) REFERENCES hero (hero_id),
  FOREIGN KEY (magic_id) REFERENCES magic (magic_id)
);

CREATE TABLE magic (
  magic_id int NOT NULL AUTO_INCREMENT,
  name varchar(20) NOT NULL,
  damage int DEFAULT '1',
  selfDamage int DEFAULT '0',
  price int DEFAULT NULL,
  element int DEFAULT NULL,
  upgradeOf int DEFAULT NULL,
  PRIMARY KEY (magic_id),
  FOREIGN KEY (element) REFERENCES element (element_id),
  FOREIGN KEY (upgradeOf) REFERENCES magic (magic_id)
);
INSERT INTO magic VALUES (1,'Fire Flick',1,0,100,2,NULL),(2,'Fire Burst',5,0,500,2,1),(3,'Fire Blast',10,0,1000,2,2),(4,'Water Pulse',1,0,100,4,NULL),(5,'Water Stream',5,0,500,4,4),(6,'Water Jet',10,0,1000,4,5),(7,'Rock Throw',1,0,100,3,NULL),(8,'Rock Smash',5,0,500,3,7),(9,'Rock Slam',10,0,1000,3,8),(10,'Leaf Cutter',2,0,200,6,NULL),(11,'Branch Cutter',8,0,800,6,10),(12,'Trunk Cutter',12,0,1200,6,11),(13,'Iron Fist',3,0,300,7,NULL),(14,'Iron Strike',10,0,1500,7,13),(15,'Metal Stab',1,0,100,7,NULL),(16,'Metal Slash',5,0,500,7,15),(17,'Metal Razor',10,0,1000,7,16),(18,'LifeSteal 1',1,-2,200,5,NULL),(19,'LifeSteal 2',4,-6,800,5,18),(20,'LifeSteal 3',8,-10,1400,5,19),(21,'LifeSteal 4',12,-12,2000,5,20),(22,'Dragon Claw',6,1,500,9,NULL),(23,'Dragon Bite',12,2,1200,9,22),(24,'Dragon Razor',16,3,2000,9,23),(25,'Sacrifice 1',8,2,500,5,NULL),(26,'Sacrifice 2',16,5,1200,5,25),(27,'Sacrifice 3',24,8,2000,5,26),(28,'Heal 1',0,-4,200,8,NULL),(29,'Heal 2',0,-10,800,8,28),(30,'Heal 3',0,-20,1500,8,29),(31,'Star Wish',1,-1,100,8,NULL),(32,'Star Sky',3,-3,500,8,31),(33,'Star Rain',8,-8,1200,8,32);

CREATE TABLE monster (
  monster_id int NOT NULL AUTO_INCREMENT,
  name char(20) NOT NULL,
  level int NOT NULL,
  hp int NOT NULL,
  ap int NOT NULL,
  kill_xp int NOT NULL,
  PRIMARY KEY (monster_id)
);
INSERT INTO monster VALUES (1,'Rat',1,5,1,100),(2,'Spider',2,12,2,150),(3,'Zombie',5,30,3,300),(4,'Skeleton',5,20,4,300),(5,'Hound',3,16,3,200),(6,'Dragon',15,250,20,3000),(7,'Witch',7,40,7,600),(8,'Mud-Chopper',3,20,2,210),(9,'Fire-Razer',4,16,4,250),(10,'Scrapling',5,30,4,320),(11,'HuffleWing',7,100,3,400),(12,'GatorGuy',7,50,5,370),(13,'RinoPlate',8,100,4,400),(14,'WaterSpirit',2,20,1,170),(15,'VolcanoStomp',9,100,8,650),(16,'ElderRoot',10,200,8,800),(17,'Twiggle',3,20,2,200),(18,'Goblin',5,15,6,360);

CREATE TABLE monster_element (
  monster_id int NOT NULL,
  element_id int NOT NULL,
  FOREIGN KEY (element_id) REFERENCES element (element_id),
  FOREIGN KEY (monster_id) REFERENCES monster (monster_id)
);
INSERT INTO monster_element VALUES (1,1),(2,1),(3,3),(4,5),(5,1),(5,2),(6,9),(6,2),(7,5),(8,3),(8,4),(9,2),(10,7),(11,8),(12,9),(12,4),(13,3),(13,7),(14,4),(14,8),(15,3),(15,2),(16,3),(16,6),(17,6),(18,1);

