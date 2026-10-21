-- MySQL dump 10.13  Distrib 8.0.46, for Win64 (x86_64)
--
-- Host: localhost    Database: hitek_comissoes
-- ------------------------------------------------------
-- Server version	8.4.7

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `colaborador`
--

DROP TABLE IF EXISTS `colaborador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `colaborador` (
  `id_colaborador` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `cpf` varchar(14) COLLATE utf8mb4_unicode_ci NOT NULL,
  `email` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `telefone` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `cargo` varchar(45) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_admissao` date NOT NULL,
  `login` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `senha` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `perfil` enum('USUARIO','VENDEDOR','FINANCEIRO','ADMINISTRADOR') COLLATE utf8mb4_unicode_ci NOT NULL,
  `status` enum('ATIVO','INATIVO') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'ATIVO',
  PRIMARY KEY (`id_colaborador`),
  UNIQUE KEY `cpf` (`cpf`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `colaborador`
--

LOCK TABLES `colaborador` WRITE;
/*!40000 ALTER TABLE `colaborador` DISABLE KEYS */;
INSERT INTO `colaborador` VALUES (1,'Jonas Silva','111.111.111-11','jonas@hitek.com','11911111111','Adminisrador','2020-01-10','jonas','1234','ADMINISTRADOR','ATIVO'),(2,'Carlos Souza','222.222.222.22','carlos@hitek.com','1192222222','Vendedor','2022-05-15','carlos','1234','VENDEDOR','ATIVO'),(3,'Joao Martin','000.000.000-00','joao@hitek.com','12933333333','Financeiro','2024-01-15','joao','1234','FINANCEIRO','ATIVO'),(4,'Marina Costa','444.444.444-44','marina@hitek.com','119444444','Vendedor','2026-10-12','mariana','1234','VENDEDOR','ATIVO');
/*!40000 ALTER TABLE `colaborador` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `comissao`
--

DROP TABLE IF EXISTS `comissao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `comissao` (
  `id_comissao` int NOT NULL AUTO_INCREMENT,
  `id_venda` int NOT NULL,
  `percentual_aplicado` decimal(10,2) NOT NULL,
  `valor_comissao` decimal(10,2) NOT NULL,
  `status` enum('PENDENTE','LIBERADA','PAGA','CANCELADA') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'PENDENTE',
  `data_calculo` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `data_conferencia` datetime DEFAULT NULL,
  PRIMARY KEY (`id_comissao`),
  UNIQUE KEY `id_venda` (`id_venda`),
  CONSTRAINT `fk_comissao_venda` FOREIGN KEY (`id_venda`) REFERENCES `venda` (`id_venda`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comissao`
--

LOCK TABLES `comissao` WRITE;
/*!40000 ALTER TABLE `comissao` DISABLE KEYS */;
INSERT INTO `comissao` VALUES (6,6,1.00,50.00,'PENDENTE','2026-10-17 14:07:29',NULL),(7,7,1.00,50.00,'PENDENTE','2026-10-17 14:21:02',NULL);
/*!40000 ALTER TABLE `comissao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `configuracao`
--

DROP TABLE IF EXISTS `configuracao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `configuracao` (
  `id_configuracao` int NOT NULL AUTO_INCREMENT,
  `percentual_atual` decimal(5,2) NOT NULL DEFAULT '1.00',
  `data_alteracao` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `id_administrador` int NOT NULL,
  PRIMARY KEY (`id_configuracao`),
  KEY `fk_configuracao_administrador` (`id_administrador`),
  CONSTRAINT `fk_configuracao_administrador` FOREIGN KEY (`id_administrador`) REFERENCES `colaborador` (`id_colaborador`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `configuracao`
--

LOCK TABLES `configuracao` WRITE;
/*!40000 ALTER TABLE `configuracao` DISABLE KEYS */;
INSERT INTO `configuracao` VALUES (4,1.00,'2026-10-14 21:45:36',1);
/*!40000 ALTER TABLE `configuracao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `desconto`
--

DROP TABLE IF EXISTS `desconto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `desconto` (
  `id_desconto` int NOT NULL AUTO_INCREMENT,
  `id_comissao_origem` int NOT NULL,
  `valor_desconto` decimal(10,2) NOT NULL,
  `motivo` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_registro` date NOT NULL,
  `aplicado` tinyint(1) NOT NULL DEFAULT '0',
  `data_aplicacao` date DEFAULT NULL,
  `id_pagamento_aplicacao` int DEFAULT NULL,
  PRIMARY KEY (`id_desconto`),
  KEY `fk_desconto_comissao` (`id_comissao_origem`),
  KEY `fk_desconto_pagamento` (`id_pagamento_aplicacao`),
  CONSTRAINT `fk_desconto_comissao` FOREIGN KEY (`id_comissao_origem`) REFERENCES `comissao` (`id_comissao`),
  CONSTRAINT `fk_desconto_pagamento` FOREIGN KEY (`id_pagamento_aplicacao`) REFERENCES `pagamento_comissao` (`id_pagamento`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `desconto`
--

LOCK TABLES `desconto` WRITE;
/*!40000 ALTER TABLE `desconto` DISABLE KEYS */;
INSERT INTO `desconto` VALUES (3,6,20.00,'desconto','2026-10-17',0,NULL,NULL);
/*!40000 ALTER TABLE `desconto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pagamento_comissao`
--

DROP TABLE IF EXISTS `pagamento_comissao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pagamento_comissao` (
  `id_pagamento` int NOT NULL AUTO_INCREMENT,
  `id_comissao` int NOT NULL,
  `data_pagamento` date DEFAULT NULL,
  `valor_pago` decimal(10,2) NOT NULL,
  `forma_pagamento` enum('PIX','TRANSFERENCIA','DINHEIRO') COLLATE utf8mb4_unicode_ci NOT NULL,
  `status` enum('PENDENTE','PAGO','CANCELADO') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'PENDENTE',
  `observacao` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `id_responsavel` int DEFAULT NULL,
  PRIMARY KEY (`id_pagamento`),
  KEY `fk_pagamento_comissao` (`id_comissao`),
  KEY `fk_pagamento_responsavel` (`id_responsavel`),
  CONSTRAINT `fk_pagamento_comissao` FOREIGN KEY (`id_comissao`) REFERENCES `comissao` (`id_comissao`),
  CONSTRAINT `fk_pagamento_responsavel` FOREIGN KEY (`id_responsavel`) REFERENCES `colaborador` (`id_colaborador`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pagamento_comissao`
--

LOCK TABLES `pagamento_comissao` WRITE;
/*!40000 ALTER TABLE `pagamento_comissao` DISABLE KEYS */;
/*!40000 ALTER TABLE `pagamento_comissao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `venda`
--

DROP TABLE IF EXISTS `venda`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `venda` (
  `id_venda` int NOT NULL AUTO_INCREMENT,
  `numero_os` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_colaborador` int NOT NULL,
  `data_venda` date NOT NULL,
  `nome_cliente` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `valor_venda` decimal(10,2) NOT NULL,
  `custo` decimal(10,2) NOT NULL,
  `margem` decimal(5,2) NOT NULL,
  `forma_pagamento` enum('PIX','CARTAO','BOLETO','DINHEIRO') COLLATE utf8mb4_unicode_ci NOT NULL,
  `faturada` tinyint(1) NOT NULL DEFAULT '0',
  `venda_paga` tinyint(1) NOT NULL DEFAULT '0',
  `data_retirada` date DEFAULT NULL,
  `descricao` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `status` enum('ATIVA','CANCELADA') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'ATIVA',
  `data_baixa` datetime DEFAULT NULL,
  `id_financeiro_baixa` int DEFAULT NULL,
  PRIMARY KEY (`id_venda`),
  UNIQUE KEY `numero_os` (`numero_os`),
  KEY `fk_venda_colaborador` (`id_colaborador`),
  KEY `fk_venda_financeiro_baixa` (`id_financeiro_baixa`),
  CONSTRAINT `fk_venda_colaborador` FOREIGN KEY (`id_colaborador`) REFERENCES `colaborador` (`id_colaborador`),
  CONSTRAINT `fk_venda_financeiro_baixa` FOREIGN KEY (`id_financeiro_baixa`) REFERENCES `colaborador` (`id_colaborador`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `venda`
--

LOCK TABLES `venda` WRITE;
/*!40000 ALTER TABLE `venda` DISABLE KEYS */;
INSERT INTO `venda` VALUES (6,'testedata',2,'2026-06-12','joao',5000.00,4000.00,20.00,'PIX',0,1,'2026-10-16','','ATIVA',NULL,NULL),(7,'testedesconto',2,'2026-11-17','joaoteste',5000.00,4000.00,20.00,'PIX',0,1,'2026-11-17','','ATIVA',NULL,NULL);
/*!40000 ALTER TABLE `venda` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-10-17 14:24:51
