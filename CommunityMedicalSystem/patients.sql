/*
 Navicat Premium Data Transfer

 Source Server         : community_medical_system
 Source Server Type    : SQLite
 Source Server Version : 3030001
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001

 Date: 10/01/2025 20:18:29
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for patients
-- ----------------------------
DROP TABLE IF EXISTS "patients";
CREATE TABLE "patients" (
  "id" INTEGER PRIMARY KEY AUTOINCREMENT,
  "name" TEXT NOT NULL,
  "gender" TEXT,
  "age" INTEGER,
  "phone" TEXT,
  "id_card" TEXT,
  "height" integer,
  "weight" integer
);

-- ----------------------------
-- Auto increment value for patients
-- ----------------------------
UPDATE "sqlite_sequence" SET seq = 10 WHERE name = 'patients';

PRAGMA foreign_keys = true;
