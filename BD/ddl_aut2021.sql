PRAGMA foreign_keys = ON;


CREATE TABLE district(
  id INTEGER PRIMARY KEY,
  name TEXT NOT NULL,
  type TEXT 
);

CREATE TABLE municipality(
  code INTEGER PRIMARY KEY,
  name TEXT NOT NULL,
  district INTEGER NOT NULL REFERENCES district(id),
  mandates INTEGER,
  registered_voters INTEGER,
  valid_votes INTEGER,
  blank_votes INTEGER,
  null_votes INTEGER
);

CREATE TABLE party(
  id INTEGER PRIMARY KEY,
  shortname TEXT NOT NULL,
  name TEXT NOT NULL);

CREATE TABLE independent(
  municipality_code INTEGER  NOT NULL REFERENCES municipality(code),
  ishortname TEXT NOT NULL,
  name TEXT NOT NULL,
  PRIMARY KEY(municipality_code, ishortname));
