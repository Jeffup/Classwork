# Host: localhost  (Version: 5.5.53)
# Date: 2019-11-10 08:54:37
# Generator: MySQL-Front 5.3  (Build 4.234)

/*!40101 SET NAMES gb2312 */;

#
# Structure for table "book"
#

DROP TABLE IF EXISTS `book`;
CREATE TABLE `book` (
  `ISBN` varchar(255) DEFAULT NULL,
  `bookname` varchar(255) NOT NULL DEFAULT 'none',
  `version` varchar(255) DEFAULT NULL,
  `author` varchar(255) DEFAULT NULL,
  `publish` varchar(255) DEFAULT NULL,
  `price` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT=' È';

#
# Data for table "book"
#

INSERT INTO `book` VALUES ('9780006176909','House of Card','2007-11-15 ','Michael Dobbs','Harper','8.99');
