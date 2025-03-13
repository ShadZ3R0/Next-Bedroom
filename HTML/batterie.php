<?php

// Vérification que l'utilisateur est bien connecté
session_start();
if (!isset($_SESSION['loggedin'])) {
    header('Location: connexion.php');
    exit();
}

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
// Requête SQL pour réccupérer les cales
$sql = "SELECT idCale, nomProprio, batterie FROM cales";
$result = $conn->query($sql);

?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Consultation des batteries</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f9f9f9;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .data-container {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 8px 8px rgba(0, 0, 0, 0.1);
            width: 300px;
        }
        h2 {
            text-align: center;
            margin-bottom: 20px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
        }
        th, td {
            padding: 8px;
            text-align: left;
            border-bottom: 1px solid #ddd;
        }
    </style>
</head>
<body>
    <div class="data-container">
        <table>
            <tr>
                <th>Id</th>
                <th>Propriétaire</th>
                <th>Pourcentage restant</th>
            </tr>
            <?php while($row = $result->fetch_assoc()) { ?>
                <tr>
                    <td><?php echo $row['idCale']; ?></td>
                    <td><?php echo $row['nomProprio']; ?></td>
                    <td><?php echo $row['batterie']; ?></td>
                </tr>
            <?php } ?>
        </table>
    </div>
</body>
</html>

<?php
$conn->close();
?>