<?php

// Connexion à la base de données
$host = 'localhost';
$dbname = 'nextbedroom';
$username = 'web';
$password = '&aqw1AQW';

$conn = new mysqli($host, $username, $password, $dbname);

$data = file_put_contents('php://input');

$parts = explode('|', $data);

$pourcentage = $parts[0] ?? '';
$id = $parts[1] ?? '';
$mdp = $parts[2] ?? '';

$sql = "SELECT mdp FROM employes WHERE id = ";
$sql .= $id;
$sql .= ";";
$result = $conn->query($sql);

if($mdp == $result){

    $bdd = "UPDATE cale SET batterie = ";
    $bdd .= $pourcentage;
    $bdd .= " WHERE employee = ";
    $bdd .= $id;
    $bdd .= ";";

    $conn->query($bdd);

}

?>