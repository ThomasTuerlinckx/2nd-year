PRAGMA foreign_keys = ON;

INSERT INTO Funcionario (ID_Funcionario, Nome, Data_Nascimento) VALUES
(1,'Luís Fernandes','1980-08-14'),(2,'Sofia Ramalho','1992-03-25'),(3,'Ricardo Teixeira','1978-11-08'),
(4,'Beatriz Nunes','1987-06-17'),(5,'Hugo Correia','1991-12-03'),(6,'Diana Marques','1983-09-22'),
(7,'Bruno Lopes','1976-04-15'),(8,'Tânia Rocha','1990-07-30'),(9,'Paulo Santos','1985-01-11'),
(10,'Carla Oliveira','1988-10-05'),(11,'Miguel Costa','1979-02-28'),(12,'Inês Pereira','1994-05-19'),
(13,'João Rodrigues','1981-12-14'),(14,'Marta Almeida','1986-03-07'),(15,'Francisco Silva','1977-08-24'),
(101,'Miguel Oliveira','1978-05-02'),(102,'Benedita Almeida','1962-09-16'),(103,'Carlos Santos','1980-11-15'),
(104,'Patrícia Lima','1975-08-22'),(105,'Ricardo Marques','1983-03-30'),(106,'Sandra Costa','1978-12-10'),
(107,'Paulo Rodrigues','1985-06-18'),(108,'Helena Ferreira','1972-04-25'),(109,'Bruno Martins','1981-07-14'),
(110,'Catarina Sousa','1979-09-08'),(111,'Luís Tavares','1986-01-19'),(112,'Tânia Rocha','1976-11-03'),
(113,'Fernando Gomes','1974-02-28'),(114,'Diana Lopes','1982-12-07'),(115,'Hugo Silva','1977-06-12');

INSERT INTO Departamento (ID_Departamento, Nome_Departamento) VALUES
(001, 'Cardiologia'),(002, 'Neurologia'),(003, 'Pediatria'),(004,'Urgência'),(005,'Ortopedia'),(006, 'Oncologia'),
(007, 'Ginecologia e Obstetrícia'),(008, 'Dermatologia'),(009, 'Oftalmologia'),(010,'Otorrinolaringologia'),
(011, 'Radiologia'),(012, 'Cuidados Intensivos'),(013, 'Psiquiatria'),(014, 'Urologia'),(015, 'Gastroenterologia');

INSERT INTO Especialidade (ID_Especialidade, Nome_Especialidade) VALUES
(1, 'Cardiologia'),(2, 'Neurologia'),(3, 'Pediatria'),(4, 'Ortopedia'),(5, 'Oncologia'),(6, 'Ginecologia e Obstetrícia'),(7, 'Dermatologia'),
    (8, 'Oftalmologia'),(9, 'Otorrinolaringologia'),(10, 'Radiologia'),(11, 'Cuidados Intensivos'),(12, 'Psiquiatria'),(13, 'Urologia'),
    (14, 'Gastroenterologia'),(15, 'Urgência');

INSERT INTO Medico (ID_Medico, Nome, Data_Nascimento) VALUES
(101,'Miguel Oliveira','1978-05-02'),(102,'Benedita Almeida','1962-09-16'),(103,'Carlos Santos','1980-11-15'),
(104,'Patrícia Lima','1975-08-22'),(105,'Ricardo Marques','1983-03-30'),(106,'Sandra Costa','1978-12-10'),
(107,'Paulo Rodrigues','1985-06-18'),(108,'Helena Ferreira','1972-04-25'),(109,'Bruno Martins','1981-07-14'),
(110,'Catarina Sousa','1979-09-08'),(111,'Luís Tavares','1986-01-19'),(112,'Tânia Rocha','1976-11-03'),
(113,'Fernando Gomes','1974-02-28'),(114,'Diana Lopes','1982-12-07'),(115,'Hugo Silva','1977-06-12');

INSERT INTO Enfermeiro (ID_Enfermeiro, Nome, Data_Nascimento) VALUES
(1,'Sofia Mendes','1991-03-14'),(2,'Miguel Oliveira','1987-11-22'),(3,'Carla Rodrigues','1993-07-08'),
(4,'Tiago Fernandes','1985-12-03'),(5,'Beatriz Costa','1990-09-17'),(6,'André Pereira','1988-04-26'),
(7,'Diana Martins','1994-01-11'),(8,'Hugo Almeida','1986-08-05'),(9,'Inês Silva','1992-06-30'),
(10,'Ricardo Santos','1984-02-19'),(11,'Laura Ferreira','1995-10-12'),(12,'Bruno Gomes','1989-07-25'),
(13,'Isabela Nunes','1992-09-18'),(14,'Rafael Souza','1986-07-30'),(15,'Juliana Carvalho','1993-11-22');

INSERT INTO Paciente (ID_Paciente, Nome, Data_Nascimento, Estado) VALUES
(1,'Rita Santos','1982-03-10','Recuperação'),(2,'Bruno Costa','1975-11-25','Estável'),
(3,'Carla Almeida','1992-07-18','Grave'),(4,'Hugo Pereira','2005-02-14','Estável'),
(5,'Sofia Martins','1958-09-08','Crítico'),(6,'Paulo Ferreira','1988-06-30','Recuperação'),
(7,'Diana Silva','1970-12-12','Estável'),(8,'Miguel Rocha','1995-04-22','Grave'),
(9,'Ana Sousa','2010-08-17','Estável'),(10,'Carlos Lima','1942-01-05','Crítico'),
(11,'Beatriz Marques','1980-10-19','Recuperação'),(12,'Ricardo Teixeira','1973-05-28','Estável'),
(13,'Tânia Oliveira','1999-03-15','Grave'),(14,'João Carvalho','2008-11-07','Estável'),
(15,'Marta Fernandes','1950-07-24','Crítico');

INSERT INTO Horario (Hora_Inicial, Hora_Final) VALUES
('08:00','16:00'),('09:00','17:00'),('10:00','18:00'),('14:00','22:00'),('16:00','23:00'),
('06:00','22:00'),('07:00','15:00'),('12:00','20:00'),('06:00','14:00'),('15:00','23:00');

INSERT INTO Visitante (ID_Visitante, Nome_Visitante, Data_Nascimento) VALUES
(1,'Carlos Mendes','1985-03-15'),(2,'Sofia Rodrigues','1992-07-22'),(3,'Miguel Costa','1978-11-30'),
(4,'Ana Santos','1988-04-18'),(5,'Paulo Ferreira','1995-09-05'),(6,'Beatriz Almeida','1983-12-12'),
(7,'Rui Martins','1990-06-25'),(8,'Catarina Sousa','1987-01-08'),(9,'Hugo Pereira','1975-08-14'),
(10,'Diana Lima','1993-10-03'),(11,'Bruno Rocha','1980-02-28'),(12,'Tânia Gomes','1986-05-17'),
(13,'André Marques','1991-11-20'),(14,'Laura Silva','1979-07-11'),(15,'Ricardo Oliveira','1984-09-29');

INSERT INTO Internamento (ID_Internamento, ID_Paciente, Data_Inicial, Data_Final) VALUES
(1, 3,  '2024-01-12', '2024-03-05'),(2, 7,  '2023-11-28', '2024-02-18'),(3, 11, '2024-02-03', '2024-03-22'),
(4, 14, '2023-12-10', '2024-01-29'),(5, 15, '2024-01-20', '2024-03-14');

INSERT INTO Diagnostico (Nome, Gravidade, Sintomas, Receita, Terapia) VALUES
('Depressão Major',6,'Anedonia, insónia, alterações de apetite','Antidepressivo: Sertralina 50mg 24/24h','Psicoterapia cognitivo-comportamental'),
('Artrose do Joelho',5,'Dor articular, rigidez matinal','Analgésicos: Paracetamol 1g 6/6h','Fisioterapia, perda de peso'),
('Asma Brônquica',6,'Dispneia, sibilos','Broncodilatador: Salbutamol SOS','Evitar alergénios'),
('Insuficiência Cardíaca',9,'Dispneia, edema','Diurético: Furosemida 40mg','Restrição hídrica'),
('ACV Isquémico',10,'Hemiparesia, afasia','Antiagregante: Ácido acetilsalicílico 100mg','Reabilitação'),
('Sepse',10,'Febre, taquicardia','Antibioticoterapia intravenosa','Cuidados intensivos'),
('Gastrite Aguda',4,'Dor epigástrica','Inibidor da bomba: Omeprazol 20mg','Dieta branda'),
('Anemia Ferropénica',3,'Fadiga, palidez','Suplemento de ferro','Dieta rica em ferro'),
('Hepatite Viral',7,'Icterícia, astenia','Repouso, hidratação','Monitorização hepática'),
('Lombalgia Aguda',5,'Dor lombar','Analgésicos, relaxante','Repouso relativo'),
('Rinite Alérgica',3,'Espirros, prurido','Anti-histamínico: Loratadina','Evitar alergénios'),
('Colecistite Aguda',8,'Dor hipocondríaca','Antibiótico, dieta absoluta','Colecistectomia'),
('Obesidade Mórbida',6,'IMC >40','Dieta hipocalórica','Acompanhamento nutricional'),
('Arritmia Cardíaca',7,'Palpitações','Antiarrítmico: Amiodarona','Monitorização cardíaca'),
('Insuficiência Renal',9,'Edema, oligúria','Diálise','Controlo da doença de base');

INSERT INTO Sala (Numero_Sala, Tipo) VALUES

(101,'Quarto'),(102,'Quarto'),(103,'Quarto'),(104,'Quarto'),(105,'Quarto'),(106,'Quarto'),(107,'Quarto'),
(108,'Quarto'),(109,'Quarto'),(110,'Quarto)(111,'Quarto'),(112,'Quarto'),(113,'Quarto'),(114,'Quarto'),
(115,'Quarto'),(116,'Quarto'),(117,'Quarto'),(118,'Quarto'),(119,'Quarto'),(120,'Quarto'),(301,'Quarto'),
(302,'Quarto'),(303,'Quarto'),(304,'Quarto'),(401,'Quarto'),(402,'Quarto'),(501,'Quarto'),(601,'Quarto'),
(201,'Gabinete'),(202,'Gabinete'),(203,'Gabinete'),(204,'Gabinete'),(205,'Gabinete'),(206,'Gabinete'),
(207,'Gabinete'),(208,'Gabinete'),(209,'Gabinete'),(210,'Gabinete'),(211,'Gabinete'),(212,'Gabinete'),
(213,'Gabinete'),(214,'Gabinete'),(215,'Gabinete'),(303,'Quarto'), 
(305,'Sala Especializada'),(306,'Sala Especializada'),(307,'Sala Especializada'),(308,'Sala Especializada'),
(403,'Sala Especializada'),(404,'Sala Especializada'),(405,'Sala Especializada'),(502,'Sala Especializada'),
(503,'Sala Especializada'),(504,'Sala Especializada'),(505,'Sala Especializada'),(602,'Sala Especializada'),
(603,'Sala Especializada'),(604,'Sala Especializada'),(605,'Sala Especializada'),(702,'Sala Especializada'),
(703,'Sala Especializada'),(704,'Sala Especializada'),(705,'Sala Especializada'),(801,'Sala Especializada'),
(802,'Sala Especializada'),(803,'Sala Especializada'),(804,'Sala Especializada'),(805,'Sala Especializada');


INSERT INTO Quartos (Numero_Sala, Tipo) VALUES
(101,'Quarto Individual'),(102,'Quarto Individual'),(103,'Quarto Individual'),(104,'Quarto Individual'),
(105,'Quarto Individual'),(106,'Quarto Individual'),(107,'Quarto Individual'),(108,'Quarto Individual'),
(109,'Quarto Individual'),(110,'Quarto Individual'),(111,'Quarto Individual'),(112,'Quarto Individual'),
(113,'Quarto Duplo'),(114,'Quarto Duplo'),(115,'Enfermaria'),(116,'Enfermaria'),
(117,'UTI - Adulto'),(118,'UTI - Adulto'),(119,'UTI - Pediátrica'),(120,'UTI - Neonatal');

INSERT INTO Gabinetes (Numero_Sala, ID_Medico) VALUES
(201,101),(202,102),(203,103),(204,104),(205,105),(206,106),(207,107),(208,108),(209,109),
(210,110),(211,111),(212,112),(213,113),(214,114),(215,115);

INSERT INTO AlasHospitalares (Codigo_Ala, Area) VALUES
(1,'Ala Norte'),(2,'Ala Sul'),(3,'Ala Este'),(4,'Ala Oeste'),(5,'Ala Central');

INSERT INTO VendingMachine (ID_VenMachine, Comida, Bebidas, Precos) VALUES
(1,'Sandes','Água e Sumos',2.50),(2,'Chocolates','Refrigerantes',3.00),
(3,'Bolachas e Fruta','Chá e Café',1.80),(4,'Snacks Salgados','Bebidas Energéticas',2.20),
(5,'Sopas e Saladas','Água e Sumos Naturais',4.50);

INSERT INTO Especialidade_SalasEspecializadas (Nome_Especialidade, Numero_Sala) VALUES
('Radiologia',301),('Radiologia',302),('Radiologia',303),('Radiologia',304),('Radiologia',305),('Radiologia',306),
('Gastroenterologia',307),('Cardiologia',308),('Pediatria',401),('Cuidados Intensivos',402),
('Oncologia',403),('Cuidados Intensivos',404),('Ortopedia',405),('Urgência',501),('Urgência',502),
('Urgência',503),('Urgência',504),('Urgência',505),('Oncologia',601),('Oncologia',602),
('Ortopedia',603),('Psiquiatria',604),('Psiquiatria',605);

INSERT INTO Medico_Enfermeiro (ID_Medico, ID_Enfermeiro) VALUES
(101,1),(102,2),(103,3),(104,4),(105,5),(106,6),(107,7),(108,8),(109,9),(110,10),(111,11),(112,12),(113,13),(114,14),(115,15);

INSERT INTO Medico_Paciente (ID_Medico, ID_Paciente) VALUES
(101,1),(102,2),(103,3),(104,4),(105,5),(106,6),(107,7),(108,8),(109,9),(110,10),(111,11),(112,12),(113,13),(114,14),(115,15);

INSERT INTO Medico_Especialidade (ID_Medico, Nome_Especialidade) VALUES
(101,'Cardiologia'),(102,'Neurologia'),(103,'Pediatria'),(104,'Ortopedia'),(105,'Oncologia'),
(106,'Ginecologia e Obstetrícia'),(107,'Dermatologia'),(108,'Oftalmologia'),(109,'Otorrinolaringologia'),
(110,'Radiologia'),(111,'Cuidados Intensivos'),(112,'Psiquiatria'),(113,'Urologia'),
(114,'Gastroenterologia'),(115,'Urgência');

INSERT INTO Medico_Departamento (Nome_Departamento, ID_Medico) VALUES
('Cardiologia',101),('Neurologia',102),('Pediatria',103),('Urgência',104),('Ortopedia',105),
('Oncologia',106),('Ginecologia e Obstetrícia',107),('Dermatologia',108),('Oftalmologia',109),
('Otorrinolaringologia',110),('Radiologia',111),('Cuidados Intensivos',112),('Psiquiatria',113),
('Urologia',114),('Gastroenterologia',115);

INSERT INTO Medico_Horario (ID_Medico, Hora_Inicial, Hora_Final) VALUES
(101,'08:00','16:00'),(102,'09:00','17:00'),(103,'10:00','18:00'),(104,'14:00','22:00'),(105,'16:00','23:00'),
(106,'06:00','22:00'),(107,'07:00','15:00'),(108,'12:00','20:00'),(109,'06:00','14:00'),(110,'15:00','23:00'),
(111,'08:00','16:00'),(112,'09:00','17:00'),(113,'10:00','18:00'),(114,'14:00','22:00'),(115,'16:00','23:00');

INSERT INTO Enfermeiro_Departamento (ID_Departamento, ID_Enfermeiro) VALUES
('Cardiologia',1),('Neurologia',2),('Pediatria',3),('Urgência',4),('Ortopedia',5),
('Oncologia',6),('Ginecologia e Obstetrícia',7),('Dermatologia',8),('Oftalmologia',9),
('Otorrinolaringologia',10),('Radiologia',11),('Cuidados Intensivos',12),('Psiquiatria',13),
('Urologia',14),('Gastroenterologia',15);

INSERT INTO Enfermeiro_Paciente (ID_Enfermeiro, ID_Paciente) VALUES
(1,1),(2,2),(3,3),(4,4),(5,5),(6,6),(7,7),(8,8),(9,9),(10,10),(11,11),(12,12),(13,13),(14,14),(15,15);

INSERT INTO Enfermeiro_Horario (ID_Enfermeiro, Hora_Inicial, Hora_Final) VALUES
(1,'08:00','16:00'),(2,'09:00','17:00'),(3,'10:00','18:00'),(4,'14:00','22:00'),(5,'16:00','23:00'),
(6,'06:00','22:00'),(7,'07:00','15:00'),(8,'12:00','20:00'),(9,'06:00','14:00'),(10,'15:00','23:00'),
(11,'08:00','16:00'),(12,'09:00','17:00'),(13,'10:00','18:00'),(14,'14:00','22:00'),(15,'16:00','23:00');


INSERT INTO Paciente_Internamento (ID_Paciente, ID_Internamento) VALUES
(1,1),(4,2),(10,3),(12,4),(14,5);

INSERT INTO Paciente_Visitante (ID_Paciente, ID_Visitante, Parentesco) VALUES
(1,1,'Filho'),(2,2,'Esposa'),(3,3,'Marido'),(4,4,'Mãe'),(5,5,'Pai'),
(6,6,'Irmã'),(7,7,'Filha'),(8,8,'Irmão'),(9,9,'Avó'),(10,10,'Avô'),
(11,11,'Tio'),(12,12,'Tia'),(13,13,'Primo'),(14,14,'Amiga'),(15,15,'Vizinha');

INSERT INTO Analise (Nome_Diagnostico, Gravidade, MedicID, ID_Paciente) VALUES
('Depressão Major',6,112,1),('Artrose do Joelho',5,105,2),('Asma Brônquica',6,103,3),
('Insuficiência Cardíaca',9,101,4),('ACV Isquémico',10,102,5),('Sepse',10,111,6),
('Gastrite Aguda',4,114,7),('Anemia Ferropénica',3,110,8),('Hepatite Viral',7,115,9),
('Lombalgia Aguda',5,104,10),('Rinite Alérgica',3,108,11),('Colecistite Aguda',8,115,12),
('Obesidade Mórbida',6,111,13),('Arritmia Cardíaca',7,101,14),('Insuficiência Renal',9,111,15);

INSERT INTO Diagnostico_Internamento (ID_Internamento, Nome_Diagnostico, Gravidade) VALUES
(1,'Depressão Major',6),(2,'Insuficiência Cardíaca',9),(3,'ACV Isquémico',10),
(4,'Colecistite Aguda',8),(5,'Arritmia Cardíaca',7);

INSERT INTO Departamento_AlasHospitalares (Nome_Departamento, Codigo_Ala) VALUES
('Cardiologia',1),('Neurologia',2),('Pediatria',1),('Urgência',3),('Ortopedia',4),
('Oncologia',2),('Ginecologia e Obstetrícia',1),('Dermatologia',5),('Oftalmologia',3),
('Otorrinolaringologia',4),('Radiologia',2),('Cuidados Intensivos',3),('Psiquiatria',5),
('Urologia',1),('Gastroenterologia',4);

INSERT INTO AlasHospitalares_VendingMachine (Codigo_Ala, ID_VenMachine) VALUES
(1,1),(2,2),(3,3),(4,4),(5,5);

INSERT INTO Horario_Funcionario (Hora_Inicial, Hora_Final, ID_Funcionario) VALUES
('08:00','16:00',101),('09:00','17:00',102),('10:00','18:00',103),('14:00','22:00',104),('16:00','23:00',105),
('06:00','23:00',106),('07:00','15:00',107),('12:00','20:00',108),('06:00','14:00',109),('15:00','23:00',110),
('08:00','16:00',111),('09:00','17:00',112),('10:00','18:00',113),('14:00','22:00',114),('16:00','23:00',115),
('08:00','16:00',1),('09:00','17:00',2),('10:00','18:00',3),('14:00','22:00',4),('16:00','23:00',5),
('22:00','23:00',6),('07:00','15:00',7),('12:00','20:00',8),('06:00','14:00',9),('15:00','23:00',10),
('08:00','16:00',11),('09:00','17:00',12),('10:00','18:00',13),('14:00','22:00',14),('16:00','23:00',15);
INSERT INTO Horario_Departamento (Hora_Inicial, Hora_Final, Nome_Departamento) VALUES
('08:00','16:00','Cardiologia'),('09:00','17:00','Neurologia'),('10:00','18:00','Pediatria'),
('14:00','22:00','Urgência'),('16:00','23:00','Ortopedia'),('06:00','22:00','Oncologia'),
('07:00','15:00','Ginecologia e Obstetrícia'),('12:00','20:00','Dermatologia'),('06:00','14:00','Oftalmologia'),
('15:00','23:00','Otorrinolaringologia'),('08:00','16:00','Radiologia'),('09:00','17:00','Cuidados Intensivos'),
('10:00','18:00','Psiquiatria'),('14:00','22:00','Urologia'),('06:00','23:00','Gastroenterologia');

INSERT INTO Departamento_Funcionario (Nome_Departamento, ID_Funcionario) VALUES
-- Médicos
('Cardiologia',101),('Neurologia',102),('Pediatria',103),('Urgência',104),('Ortopedia',105),
('Oncologia',106),('Ginecologia e Obstetrícia',107),('Dermatologia',108),('Oftalmologia',109),
('Otorrinolaringologia',110),('Radiologia',111),('Cuidados Intensivos',112),('Psiquiatria',113),
('Urologia',114),('Gastroenterologia',115),
-- Enfermeiros
('Cardiologia',1),('Neurologia',2),('Pediatria',3),('Urgência',4),('Ortopedia',5),
('Oncologia',6),('Ginecologia e Obstetrícia',7),('Dermatologia',8),('Oftalmologia',9),
('Otorrinolaringologia',10),('Radiologia',11),('Cuidados Intensivos',12),('Psiquiatria',13),
('Urologia',14),('Gastroenterologia',15);

INSERT INTO Departamento_Especialidade (Nome_Departamento, Nome_Especialidade) VALUES
('Cardiologia','Cardiologia'),('Neurologia','Neurologia'),('Pediatria','Pediatria'),
('Urgência','Urgência'),('Urgência','Cardiologia'),('Ortopedia','Ortopedia'),
('Oncologia','Oncologia'),('Ginecologia e Obstetrícia','Ginecologia e Obstetrícia'),
('Dermatologia','Dermatologia'),('Oftalmologia','Oftalmologia'),('Otorrinolaringologia','Otorrinolaringologia'),
('Radiologia','Radiologia'),('Cuidados Intensivos','Cuidados Intensivos'),
('Psiquiatria','Psiquiatria'),('Urologia','Urologia'),('Gastroenterologia','Gastroenterologia');


INSERT INTO Paciente_Quarto (ID_Paciente, Numero_Sala) VALUES
(2,102), 
(3,117), 
(5,118), 
(6,105),
(8,119), 
(10,120), 
(11,111), 
(12,113),
(13,115), 
(14,114), 
(15,116); 




CREATE INDEX IF NOT EXISTS idx_medico_especialidade ON Medico(ID_Especialidade);
CREATE INDEX IF NOT EXISTS idx_paciente_nome ON Paciente(Nome);
CREATE INDEX IF NOT EXISTS idx_internamento_datas ON Internamento(Data_Inicial, Data_Final);
CREATE INDEX IF NOT EXISTS idx_analise_paciente ON Analise(ID_Paciente);
CREATE INDEX IF NOT EXISTS idx_produto_vending ON Produto_Vending(ID_VenMachine);
