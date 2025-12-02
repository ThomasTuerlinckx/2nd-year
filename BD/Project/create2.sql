PRAGMA foreign_keys = ON;

-----------------------------------------------------------------
-- DROPS (mantidos como no modelo original)
-----------------------------------------------------------------
DROP TABLE IF EXISTS Produto_Vending;
DROP TABLE IF EXISTS VendingMachine;
DROP TABLE IF EXISTS Departamento_AlasHospitalares;
DROP TABLE IF EXISTS Ala_VendingMachine;
DROP TABLE IF EXISTS Departamento_Especialidade;
DROP TABLE IF EXISTS Departamento_Funcionario;
DROP TABLE IF EXISTS Horario_Departamento;
DROP TABLE IF EXISTS Horario_Funcionario;
DROP TABLE IF EXISTS Diagnostico_Internamento;
DROP TABLE IF EXISTS Analise;
DROP TABLE IF EXISTS Paciente_Visitante;
DROP TABLE IF EXISTS Paciente_Internamento;
DROP TABLE IF EXISTS Paciente_Quarto;
DROP TABLE IF EXISTS Medico_Horario;
DROP TABLE IF EXISTS Enfermeiro_Horario;
DROP TABLE IF EXISTS Medico_Departamento;
DROP TABLE IF EXISTS Enfermeiro_Departamento;
DROP TABLE IF EXISTS Medico_Especialidade;
DROP TABLE IF EXISTS Medico_Paciente;
DROP TABLE IF EXISTS Enfermeiro_Paciente;
DROP TABLE IF EXISTS Medico_Enfermeiro;
DROP TABLE IF EXISTS Gabinete;
DROP TABLE IF EXISTS SalaEspecializada;
DROP TABLE IF EXISTS Quartos;
DROP TABLE IF EXISTS Ala;
DROP TABLE IF EXISTS Sala;
DROP TABLE IF EXISTS Diagnostico;
DROP TABLE IF EXISTS Internamento;
DROP TABLE IF EXISTS Visitante;
DROP TABLE IF EXISTS Horario;
DROP TABLE IF EXISTS Paciente;
DROP TABLE IF EXISTS Especialidade;
DROP TABLE IF EXISTS Departamento;
DROP TABLE IF EXISTS Enfermeiro;
DROP TABLE IF EXISTS Medico;
DROP TABLE IF EXISTS Funcionario;





CREATE TABLE Funcionario (
    ID_Funcionario INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome           VARCHAR(80) NOT NULL,
    Data_Nascimento TEXT CHECK (length(Data_Nascimento)=10)
);

CREATE TABLE Medico (
    ID_Medico        INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome             VARCHAR(80) NOT NULL,
    Data_Nascimento  TEXT CHECK (length(Data_Nascimento)=10),
    ID_Especialidade INTEGER,
    FOREIGN KEY (ID_Especialidade) REFERENCES Especialidade(ID_Especialidade)
);

CREATE TABLE Enfermeiro (
    ID_Enfermeiro INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome          VARCHAR(80) NOT NULL,
    Data_Nascimento TEXT CHECK (length(Data_Nascimento)=10)
);

CREATE TABLE Departamento (
    ID_Departamento INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome VARCHAR(60) NOT NULL UNIQUE
);

CREATE TABLE Especialidade (
    ID_Especialidade INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome VARCHAR(60) NOT NULL UNIQUE
);

CREATE TABLE Paciente (
    ID_Paciente INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome VARCHAR(80) NOT NULL,
    Data_Nascimento TEXT CHECK (length(Data_Nascimento)=10),
    Estado VARCHAR(30)
);

CREATE TABLE Horario (
    ID_Horario INTEGER PRIMARY KEY AUTOINCREMENT,
    Hora_Inicial TEXT NOT NULL,
    Hora_Final   TEXT NOT NULL,
    CHECK (Hora_Inicial < Hora_Final)
);

CREATE TABLE Visitante (
    ID_Visitante INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome VARCHAR(80) NOT NULL,
    Data_Nascimento TEXT CHECK (length(Data_Nascimento)=10)
);

CREATE TABLE Internamento (
    ID_Internamento INTEGER PRIMARY KEY AUTOINCREMENT,
    ID_Paciente INTEGER NOT NULL,
    Data_Inicial TEXT NOT NULL,
    Data_Final   TEXT,
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE,
    CHECK (Data_Final IS NULL OR Data_Final >= Data_Inicial)
);

CREATE TABLE Diagnostico (
    ID_Diagnostico INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome VARCHAR(80) NOT NULL,
    Gravidade INTEGER NOT NULL CHECK (Gravidade BETWEEN 0 AND 10),
    Sintomas TEXT,
    Receita TEXT,
    Terapia TEXT
);




CREATE TABLE Sala (
    Numero_Sala INTEGER PRIMARY KEY,
    Tipo VARCHAR(20) NOT NULL CHECK (Tipo IN ('Quarto','Gabinete','Especializada','Outro'))
);

CREATE TABLE Gabinete (
    Numero_Sala INTEGER PRIMARY KEY,
    ID_Medico INTEGER NOT NULL,
    FOREIGN KEY (Numero_Sala) REFERENCES Sala(Numero_Sala) ON DELETE CASCADE,
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico) ON DELETE CASCADE
);

CREATE TABLE SalaEspecializada (
    Numero_Sala INTEGER NOT NULL,
    ID_Especialidade INTEGER NOT NULL,
    PRIMARY KEY (Numero_Sala, ID_Especialidade),
    FOREIGN KEY (Numero_Sala) REFERENCES Sala(Numero_Sala) ON DELETE CASCADE,
    FOREIGN KEY (ID_Especialidade) REFERENCES Especialidade(ID_Especialidade) ON DELETE CASCADE
);





CREATE TABLE Ala (
    ID_Ala INTEGER PRIMARY KEY AUTOINCREMENT,
    Nome VARCHAR(60),
    Area VARCHAR(50)
);

-- Máquina → agora minimalista
CREATE TABLE VendingMachine (
    ID_VenMachine INTEGER PRIMARY KEY AUTOINCREMENT,
    ID_Ala INTEGER,
    FOREIGN KEY (ID_Ala) REFERENCES Ala(ID_Ala) ON DELETE SET NULL
);

CREATE TABLE Produto_Vending (
    ID_Produto INTEGER PRIMARY KEY AUTOINCREMENT,
    ID_VenMachine INTEGER NOT NULL,
    Nome      VARCHAR(80) NOT NULL,
    Preco     DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (ID_VenMachine) REFERENCES VendingMachine(ID_VenMachine) ON DELETE CASCADE
);




CREATE TABLE Medico_Enfermeiro (
    ID_Medico INTEGER NOT NULL,
    ID_Enfermeiro INTEGER NOT NULL,
    PRIMARY KEY (ID_Medico, ID_Enfermeiro),
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico) ON DELETE CASCADE,
    FOREIGN KEY (ID_Enfermeiro) REFERENCES Enfermeiro(ID_Enfermeiro) ON DELETE CASCADE
);

CREATE TABLE Medico_Paciente (
    ID_Medico INTEGER NOT NULL,
    ID_Paciente INTEGER NOT NULL,
    PRIMARY KEY (ID_Medico, ID_Paciente),
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico) ON DELETE CASCADE,
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE
);

CREATE TABLE Enfermeiro_Paciente (
    ID_Enfermeiro INTEGER NOT NULL,
    ID_Paciente INTEGER NOT NULL,
    PRIMARY KEY (ID_Enfermeiro, ID_Paciente),
    FOREIGN KEY (ID_Enfermeiro) REFERENCES Enfermeiro(ID_Enfermeiro) ON DELETE CASCADE,
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE
);




CREATE TABLE Medico_Departamento (
    ID_Medico INTEGER NOT NULL,
    ID_Departamento INTEGER NOT NULL,
    Data_Inicio TEXT NOT NULL,
    Data_Fim    TEXT,
    Papel VARCHAR(60),
    PRIMARY KEY (ID_Medico, ID_Departamento, Data_Inicio),
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico) ON DELETE CASCADE,
    FOREIGN KEY (ID_Departamento) REFERENCES Departamento(ID_Departamento) ON DELETE CASCADE
);

CREATE TABLE Enfermeiro_Departamento (
    ID_Enfermeiro INTEGER NOT NULL,
    ID_Departamento INTEGER NOT NULL,
    Data_Inicio TEXT NOT NULL,
    Data_Fim TEXT,
    Papel VARCHAR(60),
    PRIMARY KEY (ID_Enfermeiro, ID_Departamento, Data_Inicio),
    FOREIGN KEY (ID_Enfermeiro) REFERENCES Enfermeiro(ID_Enfermeiro) ON DELETE CASCADE,
    FOREIGN KEY (ID_Departamento) REFERENCES Departamento(ID_Departamento) ON DELETE CASCADE
);



CREATE TABLE Medico_Horario (
    ID_Medico INTEGER NOT NULL,
    ID_Horario INTEGER NOT NULL,
    PRIMARY KEY (ID_Medico, ID_Horario),
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico) ON DELETE CASCADE,
    FOREIGN KEY (ID_Horario) REFERENCES Horario(ID_Horario) ON DELETE CASCADE
);

CREATE TABLE Enfermeiro_Horario (
    ID_Enfermeiro INTEGER NOT NULL,
    ID_Horario INTEGER NOT NULL,
    PRIMARY KEY (ID_Enfermeiro, ID_Horario),
    FOREIGN KEY (ID_Enfermeiro) REFERENCES Enfermeiro(ID_Enfermeiro) ON DELETE CASCADE,
    FOREIGN KEY (ID_Horario) REFERENCES Horario(ID_Horario) ON DELETE CASCADE
);

CREATE TABLE Horario_Funcionario (
    ID_Funcionario INTEGER NOT NULL,
    ID_Horario INTEGER NOT NULL,
    PRIMARY KEY (ID_Funcionario, ID_Horario),
    FOREIGN KEY (ID_Funcionario) REFERENCES Funcionario(ID_Funcionario) ON DELETE CASCADE,
    FOREIGN KEY (ID_Horario) REFERENCES Horario(ID_Horario) ON DELETE CASCADE
);




CREATE TABLE Paciente_Quarto (
    ID_Paciente INTEGER NOT NULL,
    Numero_Sala INTEGER NOT NULL,
    Data_Inicio TEXT NOT NULL,
    Data_Fim TEXT,
    PRIMARY KEY (ID_Paciente, Numero_Sala, Data_Inicio),
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE,
    FOREIGN KEY (Numero_Sala) REFERENCES Sala(Numero_Sala) ON DELETE CASCADE,
    CHECK (Data_Fim IS NULL OR Data_Fim >= Data_Inicio)
);

CREATE TABLE Paciente_Internamento (
    ID_Paciente INTEGER NOT NULL,
    ID_Internamento INTEGER NOT NULL,
    PRIMARY KEY (ID_Paciente, ID_Internamento),
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE,
    FOREIGN KEY (ID_Internamento) REFERENCES Internamento(ID_Internamento) ON DELETE CASCADE
);

CREATE TABLE Paciente_Visitante (
    ID_Paciente INTEGER NOT NULL,
    ID_Visitante INTEGER NOT NULL,
    Data_Visita TEXT NOT NULL,
    Parentesco VARCHAR(30),
    PRIMARY KEY (ID_Paciente, ID_Visitante, Data_Visita),
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE,
    FOREIGN KEY (ID_Visitante) REFERENCES Visitante(ID_Visitante) ON DELETE CASCADE
);





CREATE TABLE Analise (
    ID_Analise INTEGER PRIMARY KEY AUTOINCREMENT,
    ID_Diagnostico INTEGER NOT NULL,
    ID_Medico INTEGER NOT NULL,
    ID_Paciente INTEGER NOT NULL,
    Data_Hora TEXT NOT NULL,
    Observacoes TEXT,
    FOREIGN KEY (ID_Diagnostico) REFERENCES Diagnostico(ID_Diagnostico) ON DELETE CASCADE,
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico) ON DELETE CASCADE,
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente) ON DELETE CASCADE
);

CREATE TABLE Diagnostico_Internamento (
    ID_Internamento INTEGER NOT NULL,
    ID_Diagnostico INTEGER NOT NULL,
    PRIMARY KEY (ID_Internamento, ID_Diagnostico),
    FOREIGN KEY (ID_Internamento) REFERENCES Internamento(ID_Internamento) ON DELETE CASCADE,
    FOREIGN KEY (ID_Diagnostico) REFERENCES Diagnostico(ID_Diagnostico) ON DELETE CASCADE
);


CREATE TABLE Departamento_Funcionario (
    ID_Departamento INTEGER NOT NULL,
    ID_Funcionario INTEGER NOT NULL,
    PRIMARY KEY (ID_Departamento, ID_Funcionario),
    FOREIGN KEY (ID_Departamento) REFERENCES Departamento(ID_Departamento) ON DELETE CASCADE,
    FOREIGN KEY (ID_Funcionario) REFERENCES Funcionario(ID_Funcionario) ON DELETE CASCADE
);

CREATE TABLE Departamento_Especialidade (
    ID_Departamento INTEGER NOT NULL,
    ID_Especialidade INTEGER NOT NULL,
    PRIMARY KEY (ID_Departamento, ID_Especialidade),
    FOREIGN KEY (ID_Departamento) REFERENCES Departamento(ID_Departamento) ON DELETE CASCADE,
    FOREIGN KEY (ID_Especialidade) REFERENCES Especialidade(ID_Especialidade) ON DELETE CASCADE
);

CREATE TABLE Departamento_AlasHospitalares (
    ID_Departamento INTEGER NOT NULL,
    ID_Ala INTEGER NOT NULL,
    PRIMARY KEY (ID_Departamento, ID_Ala),
    FOREIGN KEY (ID_Departamento) REFERENCES Departamento(ID_Departamento) ON DELETE CASCADE,
    FOREIGN KEY (ID_Ala) REFERENCES Ala(ID_Ala) ON DELETE CASCADE
);




CREATE INDEX IF NOT EXISTS idx_medico_especialidade ON Medico(ID_Especialidade);
CREATE INDEX IF NOT EXISTS idx_paciente_nome ON Paciente(Nome);
CREATE INDEX IF NOT EXISTS idx_internamento_datas ON Internamento(Data_Inicial, Data_Final);
CREATE INDEX IF NOT EXISTS idx_analise_paciente ON Analise(ID_Paciente);
CREATE INDEX IF NOT EXISTS idx_produto_vending ON Produto_Vending(ID_VenMachine);