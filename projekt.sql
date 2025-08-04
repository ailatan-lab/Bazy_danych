-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:4306
-- Generation Time: Sty 20, 2024 at 12:45 AM
-- Wersja serwera: 10.4.32-MariaDB
-- Wersja PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `projekt`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `budynek`
--

CREATE TABLE `budynek` (
  `BudynekID` int(11) NOT NULL,
  `FirmaBudowlanaID` int(11) NOT NULL,
  `Rok budowy` int(11) NOT NULL,
  `TypID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `budynek`
--

INSERT INTO `budynek` (`BudynekID`, `FirmaBudowlanaID`, `Rok budowy`, `TypID`) VALUES
(1, 3, 1888, 5),
(2, 5, 1865, 1),
(3, 2, 2000, 4),
(4, 4, 1998, 2),
(5, 1, 2020, 3);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `firmabudowlana`
--

CREATE TABLE `firmabudowlana` (
  `FirmaID` int(11) NOT NULL,
  `Nazwa` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `firmabudowlana`
--

INSERT INTO `firmabudowlana` (`FirmaID`, `Nazwa`) VALUES
(1, 'Budex'),
(2, 'Stawex'),
(3, 'Oknex'),
(4, 'Domex'),
(5, 'Takex');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `typ`
--

CREATE TABLE `typ` (
  `TypID` int(11) NOT NULL,
  `Nazwa` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `typ`
--

INSERT INTO `typ` (`TypID`, `Nazwa`) VALUES
(1, 'Blok'),
(2, 'Dom jednorodzinny'),
(3, 'Blizniak'),
(4, 'Wiezowiec'),
(5, 'Kamienica');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `wlasciciel`
--

CREATE TABLE `wlasciciel` (
  `WlascicielFirmyID` int(11) NOT NULL,
  `Nazwa` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `wlasciciel`
--

INSERT INTO `wlasciciel` (`WlascicielFirmyID`, `Nazwa`) VALUES
(1, 'Maja Majka'),
(2, 'Marzena Fik'),
(3, 'Kaja Kajak'),
(4, 'Katarzyna Stopa'),
(5, 'Barbara Marzen');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `wlascicielfirmy`
--

CREATE TABLE `wlascicielfirmy` (
  `FirmaID` int(11) NOT NULL,
  `WlascicielFirmyID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `budynek`
--
ALTER TABLE `budynek`
  ADD PRIMARY KEY (`BudynekID`),
  ADD UNIQUE KEY `TypID` (`TypID`),
  ADD UNIQUE KEY `FirmaBudowlanaID` (`FirmaBudowlanaID`);

--
-- Indeksy dla tabeli `firmabudowlana`
--
ALTER TABLE `firmabudowlana`
  ADD PRIMARY KEY (`FirmaID`);

--
-- Indeksy dla tabeli `typ`
--
ALTER TABLE `typ`
  ADD PRIMARY KEY (`TypID`);

--
-- Indeksy dla tabeli `wlasciciel`
--
ALTER TABLE `wlasciciel`
  ADD PRIMARY KEY (`WlascicielFirmyID`);

--
-- Indeksy dla tabeli `wlascicielfirmy`
--
ALTER TABLE `wlascicielfirmy`
  ADD PRIMARY KEY (`FirmaID`),
  ADD UNIQUE KEY `WlascicielFirmyID` (`WlascicielFirmyID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `budynek`
--
ALTER TABLE `budynek`
  MODIFY `BudynekID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `firmabudowlana`
--
ALTER TABLE `firmabudowlana`
  MODIFY `FirmaID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `typ`
--
ALTER TABLE `typ`
  MODIFY `TypID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `wlasciciel`
--
ALTER TABLE `wlasciciel`
  MODIFY `WlascicielFirmyID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `wlascicielfirmy`
--
ALTER TABLE `wlascicielfirmy`
  MODIFY `FirmaID` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `budynek`
--
ALTER TABLE `budynek`
  ADD CONSTRAINT `budynek_ibfk_1` FOREIGN KEY (`TypID`) REFERENCES `typ` (`TypID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `budynek_ibfk_2` FOREIGN KEY (`FirmaBudowlanaID`) REFERENCES `firmabudowlana` (`FirmaID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `wlascicielfirmy`
--
ALTER TABLE `wlascicielfirmy`
  ADD CONSTRAINT `wlascicielfirmy_ibfk_1` FOREIGN KEY (`FirmaID`) REFERENCES `firmabudowlana` (`FirmaID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `wlascicielfirmy_ibfk_2` FOREIGN KEY (`WlascicielFirmyID`) REFERENCES `wlasciciel` (`WlascicielFirmyID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
