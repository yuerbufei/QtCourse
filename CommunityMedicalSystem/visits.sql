/*
 Navicat Premium Data Transfer

 Source Server         : community_medical_system
 Source Server Type    : SQLite
 Source Server Version : 3030001
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001

 Date: 10/01/2025 20:21:04
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for visits
-- ----------------------------
DROP TABLE IF EXISTS "visits";
CREATE TABLE "visits" (
  "id" INTEGER PRIMARY KEY AUTOINCREMENT,
  "patient_id" INTEGER,
  "doctor_id" INTEGER,
  "visit_date" DATE NOT NULL,
  "diagnosis_result" TEXT,
  "prescribed_medicines" TEXT,
  FOREIGN KEY ("patient_id") REFERENCES "patients" ("id") ON DELETE NO ACTION ON UPDATE NO ACTION,
  FOREIGN KEY ("doctor_id") REFERENCES "doctors" ("id") ON DELETE NO ACTION ON UPDATE NO ACTION
);

-- ----------------------------
-- Auto increment value for visits
-- ----------------------------
UPDATE "sqlite_sequence" SET seq = 10 WHERE name = 'visits';

PRAGMA foreign_keys = true;
