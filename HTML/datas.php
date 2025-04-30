<?php

// Connexion à la base de données
$host = 'localhost';
$dbname = 'nextbedroom';
$username = 'web';
$password = '&aqw1AQW';

$conn = new mysqli($host, $username, $password, $dbname);

// Si il ya une erreur lors de la connexion, on envoie erreur de connexion
if ($conn->connect_error) {
    die("Erreur de connexion à la base de données: " . $conn->connect_error);
}

$test = file_get_contents('php://input');
$data = "Nouvelle requête\n";
$data .= "Données envoyées: ";
$data .= $test;
$data .= "\n";
$data .= "\n";
$file = 'datas.txt';
file_put_contents($file, $data, FILE_APPEND | LOCK_EX);

?>