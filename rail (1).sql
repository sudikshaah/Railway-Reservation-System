-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 05, 2025 at 07:13 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.0.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `rail`
--

-- --------------------------------------------------------

--
-- Table structure for table `passengers`
--

CREATE TABLE `passengers` (
  `pname` char(20) DEFAULT NULL,
  `age` int(3) DEFAULT NULL,
  `trainno` int(6) DEFAULT NULL,
  `noofpas` int(3) DEFAULT NULL,
  `cls` char(4) DEFAULT NULL,
  `amt` int(6) DEFAULT NULL,
  `status` char(10) DEFAULT NULL,
  `pnrno` int(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `passengers`
--

INSERT INTO `passengers` (`pname`, `age`, `trainno`, `noofpas`, `cls`, `amt`, `status`, `pnrno`) VALUES
('MIHIKA SETH', 27, 629663, 1, 'ac2', 800, 'deleted', 1004),
('VANSH RAI SINGHANIA', 30, 918267, 1, 'ac1', 1000, 'conf', 1005),
('Rishita Vats', 23, 736257, 1, 'ac2', 800, 'conf', 1006);

-- --------------------------------------------------------

--
-- Table structure for table `traindetail`
--

CREATE TABLE `traindetail` (
  `tname` char(50) DEFAULT NULL,
  `tnum` int(6) NOT NULL,
  `src` char(50) DEFAULT NULL,
  `des` char(50) DEFAULT NULL,
  `ac1` int(5) DEFAULT NULL,
  `ac2` int(5) DEFAULT NULL,
  `ac3` int(5) DEFAULT NULL,
  `slp` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `traindetail`
--

INSERT INTO `traindetail` (`tname`, `tnum`, `src`, `des`, `ac1`, `ac2`, `ac3`, `slp`) VALUES
('HUMSAFAR EXPRESS', 157265, 'HOWRAH', 'JAMMU TAWI', 190, 180, 200, 203),
('SHATABDI EXPRESS', 629663, 'HOWRAH', 'DELHI', 250, 250, 270, 150),
('Kolkata Mail', 736257, 'Kolkata', 'Jammu', 180, 195, 200, 250),
('COROMANDEL EXPRESS', 765243, 'KHARAGPUR', 'HOWRAH', 190, 334, 200, 250),
('RAJDHANI EXPRESS', 918267, 'CHENNAI', 'JAIPUR', 175, 118, 90, 200);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `traindetail`
--
ALTER TABLE `traindetail`
  ADD PRIMARY KEY (`tnum`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
