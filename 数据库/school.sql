/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50540
Source Host           : localhost:3306
Source Database       : school

Target Server Type    : MYSQL
Target Server Version : 50540
File Encoding         : 65001

Date: 2018-12-25 11:49:22
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `admin`
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `a_id` int(2) NOT NULL AUTO_INCREMENT,
  `a_name` varchar(50) NOT NULL,
  `a_password` varchar(50) NOT NULL,
  PRIMARY KEY (`a_id`)
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO admin VALUES ('1', 'admin', 'admin');
INSERT INTO admin VALUES ('2', '张三', '123');
INSERT INTO admin VALUES ('3', '李四', '123');
INSERT INTO admin VALUES ('10', '123', '123');

-- ----------------------------
-- Table structure for `student`
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
  `s_id` int(20) NOT NULL,
  `s_name` varchar(20) NOT NULL,
  `s_sex` varchar(4) NOT NULL,
  `s_class` varchar(50) NOT NULL,
  `s_phone` varchar(20) NOT NULL,
  PRIMARY KEY (`s_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1317010128 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO student VALUES ('1317010101', '帅哥1', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010102', '帅哥2', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010104', '帅哥3', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010103', '帅哥4', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010105', '帅哥5', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010106', '帅哥6', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010107', '帅哥7', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010108', '帅哥8', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010109', '帅哥9', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010110', '帅哥10', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010111', '帅哥11', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010112', '帅哥12', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010113', '帅哥13', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010114', '帅哥14', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010115', '帅哥15', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010116', '帅哥16', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010117', '帅哥17', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010118', '帅哥18', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010119', '帅哥19', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010120', '帅哥20', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010121', '帅哥21', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010122', '帅哥22', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010123', '帅哥23', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010124', '帅哥24', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010125', '帅哥25', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010126', '帅哥26', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010127', '帅哥27', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010128', '帅哥28', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010129', '帅哥29', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010130', '帅哥30', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010131', '帅哥31', '男', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010132', '美女32', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010133', '美女33', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010134', '美女34', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010135', '美女35', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010136', '美女36', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010137', '美女37', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010138', '美女38', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010139', '美女39', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010140', '美女40', '女 ', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010141', '美女41', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010142', '美女42', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010143', '美女43', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010144', '美女44', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010145', '美女45', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010146', '美女46', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010147', '美女47', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010148', '美女48', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010149', '美女49', '女', '17计科专升本', '12345678910');
INSERT INTO student VALUES ('1317010150', '美女50', '女', '17计科专升本', '12345678910');
