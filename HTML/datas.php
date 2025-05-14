<?php

// Connexion à la base de données
$host = 'localhost';
$dbname = 'nextbedroom';
$username = 'web';
$password = '&aqw1AQW';

$conn = new mysqli($host, $username, $password, $dbname);

$data = file_put_contents('php://input');
$conn->query($data);

?>