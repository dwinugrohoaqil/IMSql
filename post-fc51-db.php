<?php

/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-mysql-database-php/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

$servername = "localhost";

// REPLACE with your Database name
$dbname = "cwp_jatsc";
// REPLACE with Database user
$username = "Aqil";
// REPLACE with Database user password
$password = "";

// Keep this API Key value to be compatible with the ESP32 code provided in the project page. 
// If you change this value, the ESP32 sketch needs to match
//$api_key_value = "tPmAT5Ab3j7F9";
$api_key_value = "";

// $api_key= $tempc = "";
$api_key=  $lev1 =  $lev2 =  $lev3 =  $lev4 =  $lev5 =  $lev6 =  $lev7 =  $lev8 =  $lev9 =  $lev10 = 
 $lev11 =  $lev12 =  $lev13 =  $lev14 =  $lev15 =  $lev16 =  $lev17 =  $lev18 =  $lev19 =  $lev20 = 
 $lev21 =  $lev22 =  $lev23 =  $lev24 =  $lev25 =  $lev26 =  $lev27 =  $lev28 =  $lev29 =  
//  ACC

 $lev30 = 
 $lev31 =  $lev32 =  $lev33 =  $lev34 =  $lev35 =  $lev36 =  $lev37 =  $lev38 =  $lev39 =  $lev40 =  $lev41 =  $lev42 =  $lev43 =  $lev44 = 
// APP 
 
 $lev45 =  $lev46 =  $lev47 = 
// ADC

"";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        
        $lev1 = test_input($_POST["r1lev"]);
        $lev2 = test_input($_POST["r2lev"]);
        $lev3 = test_input($_POST["r3lev"]);
        $lev4 = test_input($_POST["r4lev"]);
        $lev5 = test_input($_POST["r5lev"]);
        $lev6 = test_input($_POST["r6lev"]);
        $lev7 = test_input($_POST["r7lev"]);
        $lev8 = test_input($_POST["r8lev"]);
        $lev9 = test_input($_POST["r9lev"]);
        $lev10 = test_input($_POST["r10lev"]);
        
        
        $lev11 = test_input($_POST["r11lev"]);
        $lev12 = test_input($_POST["r12lev"]);
        $lev13 = test_input($_POST["r13lev"]);
        $lev14 = test_input($_POST["r14lev"]);
        $lev15 = test_input($_POST["r15lev"]);
        $lev16 = test_input($_POST["r16lev"]);
        $lev17 = test_input($_POST["r17lev"]);
        $lev18 = test_input($_POST["r18lev"]);
        $lev19 = test_input($_POST["r19lev"]);
        $lev20 = test_input($_POST["r20lev"]);
        
        $lev21 = test_input($_POST["r21lev"]);
        $lev22 = test_input($_POST["r22lev"]);
        $lev23 = test_input($_POST["r23lev"]);
        $lev24 = test_input($_POST["r24lev"]);
        $lev25 = test_input($_POST["r25lev"]);
        $lev26 = test_input($_POST["r26lev"]);
        $lev27 = test_input($_POST["r27lev"]);
        $lev28 = test_input($_POST["r28lev"]);
        $lev29 = test_input($_POST["r29lev"]);
        $lev30 = test_input($_POST["r30lev"]);
        
        $lev31 = test_input($_POST["r31lev"]);
        $lev32 = test_input($_POST["r32lev"]);
        $lev33 = test_input($_POST["r33lev"]);
        $lev34 = test_input($_POST["r34lev"]);
        $lev35 = test_input($_POST["r35lev"]);
        $lev36 = test_input($_POST["r36lev"]);
        $lev37 = test_input($_POST["r37lev"]);
        $lev38 = test_input($_POST["r38lev"]);
        $lev39 = test_input($_POST["r39lev"]);
        $lev40 = test_input($_POST["r40lev"]);
        
        $lev41 = test_input($_POST["r41lev"]);
        $lev42 = test_input($_POST["r42lev"]);
        $lev43 = test_input($_POST["r43lev"]);
        $lev44 = test_input($_POST["r44lev"]);
        $lev45 = test_input($_POST["r45lev"]);
        $lev46 = test_input($_POST["r46lev"]);
        $lev47 = test_input($_POST["r47lev"]);
        // $haf = test_input($_POST["r1tempf"]);
        // $ful = test_input($_POST["r1humid"]);
        // $r2_humid = test_input($_POST["r2h"]);
       // $value1 = test_input($_POST["value1"]);
       // $value2 = test_input($_POST["value2"]);
       // $value3 = test_input($_POST["value3"]);
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
/*         $sql = "INSERT INTO SensorData (sensor, location)
        VALUES ('" . $sensor . "', '" . $location . "')";    */  
        // $sql = "INSERT INTO tabel_monitor_suhu (temperatureC) VALUES ('".$tempc."')"; 		
        $sql1 = "INSERT INTO cwp1 (Paper_Level) VALUES ('".$lev1."')"; 		
        $sql2 = "INSERT INTO cwp2 (Paper_Level) VALUES ('".$lev2."')"; 		
        $sql3 = "INSERT INTO cwp3 (Paper_Level) VALUES ('".$lev3."')"; 		
        $sql4 = "INSERT INTO cwp4 (Paper_Level) VALUES ('".$lev4."')"; 		
        $sql5 = "INSERT INTO cwp5 (Paper_Level) VALUES ('".$lev5."')"; 		
        $sql6 = "INSERT INTO cwp6 (Paper_Level) VALUES ('".$lev6."')"; 		
        $sql7 = "INSERT INTO cwp7 (Paper_Level) VALUES ('".$lev7."')"; 		
        $sql8 = "INSERT INTO cwp8 (Paper_Level) VALUES ('".$lev8."')"; 		
        $sql9 = "INSERT INTO cwp9 (Paper_Level) VALUES ('".$lev9."')"; 		
        $sql10 = "INSERT INTO cwp10 (Paper_Level) VALUES ('".$lev10."')"; 		
        
        $sql11 = "INSERT INTO cwp11 (Paper_Level) VALUES ('".$lev11."')"; 		
        $sql12 = "INSERT INTO cwp12 (Paper_Level) VALUES ('".$lev12."')"; 		
        $sql13 = "INSERT INTO cwp13 (Paper_Level) VALUES ('".$lev13."')"; 		
        $sql14 = "INSERT INTO cwp14 (Paper_Level) VALUES ('".$lev14."')"; 		
        $sql15 = "INSERT INTO cwp15 (Paper_Level) VALUES ('".$lev15."')"; 		
        $sql16 = "INSERT INTO cwp16 (Paper_Level) VALUES ('".$lev16."')"; 		
        $sql17 = "INSERT INTO cwp17 (Paper_Level) VALUES ('".$lev17."')"; 		
        $sql18 = "INSERT INTO cwp18 (Paper_Level) VALUES ('".$lev18."')"; 		
        $sql19 = "INSERT INTO cwp19 (Paper_Level) VALUES ('".$lev19."')"; 		
        $sql20 = "INSERT INTO cwp20 (Paper_Level) VALUES ('".$lev20."')"; 		
        
        $sql21 = "INSERT INTO cwp21 (Paper_Level) VALUES ('".$lev21."')"; 		
        $sql22 = "INSERT INTO cwp22 (Paper_Level) VALUES ('".$lev22."')"; 		
        $sql23 = "INSERT INTO cwp23 (Paper_Level) VALUES ('".$lev23."')"; 		
        $sql24 = "INSERT INTO cwp24 (Paper_Level) VALUES ('".$lev24."')"; 		
        $sql25 = "INSERT INTO cwp25 (Paper_Level) VALUES ('".$lev25."')"; 		
        $sql26 = "INSERT INTO cwp26 (Paper_Level) VALUES ('".$lev26."')"; 		
        $sql27 = "INSERT INTO cwp27 (Paper_Level) VALUES ('".$lev27."')"; 		
        $sql28 = "INSERT INTO cwp28 (Paper_Level) VALUES ('".$lev28."')"; 		
        $sql29 = "INSERT INTO cwp29 (Paper_Level) VALUES ('".$lev29."')"; 		
        $sql30 = "INSERT INTO cwp30 (Paper_Level) VALUES ('".$lev30."')"; 		
        
        $sql31 = "INSERT INTO cwp31 (Paper_Level) VALUES ('".$lev31."')"; 		
        $sql32 = "INSERT INTO cwp32 (Paper_Level) VALUES ('".$lev32."')"; 		
        $sql33 = "INSERT INTO cwp33 (Paper_Level) VALUES ('".$lev33."')"; 		
        $sql34 = "INSERT INTO cwp34 (Paper_Level) VALUES ('".$lev34."')"; 		
        $sql35 = "INSERT INTO cwp35 (Paper_Level) VALUES ('".$lev35."')"; 		
        $sql36 = "INSERT INTO cwp36 (Paper_Level) VALUES ('".$lev36."')"; 		
        $sql37 = "INSERT INTO cwp37 (Paper_Level) VALUES ('".$lev37."')"; 		
        $sql38 = "INSERT INTO cwp38 (Paper_Level) VALUES ('".$lev38."')"; 		
        $sql39 = "INSERT INTO cwp39 (Paper_Level) VALUES ('".$lev39."')"; 		
        $sql40 = "INSERT INTO cwp40 (Paper_Level) VALUES ('".$lev40."')"; 		
        
        $sql41 = "INSERT INTO cwp41 (Paper_Level) VALUES ('".$lev41."')"; 		
        $sql42 = "INSERT INTO cwp42 (Paper_Level) VALUES ('".$lev42."')"; 		
        $sql43 = "INSERT INTO cwp43 (Paper_Level) VALUES ('".$lev43."')"; 		
        $sql44 = "INSERT INTO cwp44 (Paper_Level) VALUES ('".$lev44."')"; 		
        $sql45 = "INSERT INTO cwp45 (Paper_Level) VALUES ('".$lev45."')"; 		
        $sql46 = "INSERT INTO cwp46 (Paper_Level) VALUES ('".$lev46."')"; 		
        $sql47 = "INSERT INTO cwp47 (Paper_Level) VALUES ('".$lev47."')"; 		
		
        
        // $sql = "INSERT INTO SensorData (sensor, location, value1, value2, value3)
       // VALUES ('" . $sensor . "', '" . $location . "', '" . $value1 . "', '" . $value2 . "', '" . $value3 . "')";
        
        if (
            // 1
            $conn->query($sql1) === TRUE or
            $conn->query($sql2) === TRUE or
            $conn->query($sql3) === TRUE or
            $conn->query($sql4) === TRUE or
            $conn->query($sql5) === TRUE or
            $conn->query($sql6) === TRUE or
            $conn->query($sql7) === TRUE or
            $conn->query($sql8) === TRUE or
            $conn->query($sql9) === TRUE or
            $conn->query($sql10) === TRUE or
            // 10
            $conn->query($sql11) === TRUE or
            $conn->query($sql12) === TRUE or
            $conn->query($sql13) === TRUE or
            $conn->query($sql14) === TRUE or
            $conn->query($sql15) === TRUE or
            $conn->query($sql16) === TRUE or
            $conn->query($sql17) === TRUE or
            $conn->query($sql18) === TRUE or
            $conn->query($sql19) === TRUE or
            $conn->query($sql20) === TRUE or
            // 20
            $conn->query($sql21) === TRUE or
            $conn->query($sql22) === TRUE or
            $conn->query($sql23) === TRUE or
            $conn->query($sql24) === TRUE or
            $conn->query($sql25) === TRUE or
            $conn->query($sql26) === TRUE or
            $conn->query($sql27) === TRUE or
            $conn->query($sql28) === TRUE or
            $conn->query($sql29) === TRUE or
            $conn->query($sql30) === TRUE or
            // 30
            $conn->query($sql31) === TRUE or
            $conn->query($sql32) === TRUE or
            $conn->query($sql33) === TRUE or
            $conn->query($sql34) === TRUE or
            $conn->query($sql35) === TRUE or
            $conn->query($sql36) === TRUE or
            $conn->query($sql37) === TRUE or
            $conn->query($sql38) === TRUE or
            $conn->query($sql39) === TRUE or
            $conn->query($sql40) === TRUE or
            // 40
            $conn->query($sql41) === TRUE or
            $conn->query($sql42) === TRUE or
            $conn->query($sql43) === TRUE or
            $conn->query($sql44) === TRUE or
            $conn->query($sql45) === TRUE or
            $conn->query($sql46) === TRUE or
            $conn->query($sql47) === TRUE
            // 47
            ) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }

}
else {
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>