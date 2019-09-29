<?xml version="1.0" encoding="UTF-8"?>
<html  xmlns="http://www.w3.org/1999/xhtml">
<head>
 <title> Planetary List</title>



 <style>

  /*  HTML Table styling  */
 table, th, td { 
  border: 1px solid black;
  border-collapse: collapse;
}
th, td {
  padding: 15px;
}
table {
  border-spacing: 5px;
  margin-left:auto; 
  margin-right:auto;
}
body{
    text-align:center;
}
 </style>




</head>


<body>
<!--Search Query-->
<form action="search.php" method="POST">  
<label>System Search: </label><input type="text" name="query"/>
<input type="submit" name="action" value="Search"/>
</form>
<table style="text-align:center;">

<!-- Script start -->
<?php

    $file = 'OpenExoplanetCatalogue.csv';

    $data_array = [];


    // Read all of CSV file into a 2D Array
    if(($h = fopen("{$file}", "r")) !== FALSE)
    {
        while(($data = fgetcsv($h, 179, ",")) !== FALSE)
        {
            $data_array [] = $data;
        }

        fclose($h);
    }

    if(isset($_POST['query']))
    {
        echo "<tr>";
        echo "<th>System Name</th>";
        echo "<th>Planet Name</th>";
        echo "</tr>";

        $query_line = ucfirst($_POST['query']); // Force input to be capitalised to match correctly during search



        // Allow for partial string matching through search
        $planet_array = array_column($data_array, 9);
        $planet_key_array = [];
        for($i = 0; $i < count($planet_array); $i++){
          if(preg_match("/$query_line/", $planet_array[$i]))
          {
            array_push($planet_key_array,$i);
          }
        }

        $name_array = array_column($data_array, 0);
        $name_key_array = [];
        for($i = 0; $i < count($name_array); $i++){
          if(preg_match("/$query_line/", $name_array[$i]))
          {
            array_push($name_key_array,$i);
          }
        }
        $binary_array = array_column($data_array, 1);
        $binary_key_array = [];
        for($i = 0; $i < count($binary_array); $i++){
          if(preg_match("/$query_line/", $binary_array[$i]))
          {
            array_push($binary_key_array,$i);
          }
        }
        // Search through list column
        $list_array = array_column($data_array, 15);
        $list_key_array = [];
        for($i = 0; $i < count($list_array); $i++){
          if(preg_match("/$query_line/", $list_array[$i]))
          {
            array_push($list_key_array,$i);
          }
        }

        // Search by planet name
        foreach($planet_key_array as $key)
        {
        $sys_name = $data_array[$key][9];
        $sys_encode = urlencode($sys_name);
        $planet_name = $data_array[$key][0];
        echo "<tr>";
        echo "<td> <a href='display.php?system=$sys_encode'>" . $sys_name . "</a></td>" ;
        echo "<td>" . $planet_name . "</td>" ;
        echo "</tr>";
        }
        // Search by system name
        foreach($name_key_array as $key)
        {
        $sys_name = $data_array[$key][9];
        $sys_encode = urlencode($sys_name);
        $planet_name = $data_array[$key][0];
        echo "<tr>";
        echo "<td> <a href='display.php?system=$sys_encode'>" . $sys_name . "</a></td>" ;
        echo "<td>" . $planet_name . "</td>" ;
        echo "</tr>";
        }

        // Search by binary type
        foreach($binary_key_array as $key)
        {
        $sys_name = $data_array[$key][9];
        $sys_encode = urlencode($sys_name);
        $planet_name = $data_array[$key][0];
        echo "<tr>";
        echo "<td> <a href='display.php?system=$sys_encode'>" . $sys_name . "</a></td>" ;
        echo "<td>" . $planet_name . "</td>" ;
        echo "</tr>";
        }

        //Search by list inclusion
        foreach($list_key_array as $key)
        {
        $sys_name = $data_array[$key][9];
        $sys_encode = urlencode($sys_name);
        $planet_name = $data_array[$key][0];
        echo "<tr>";
        echo "<td> <a href='display.php?system=$sys_encode'>" . $sys_name . "</a></td>" ;
        echo "<td>" . $planet_name . "</td>" ;
        echo "</tr>";
        }
        echo "</table>";

        echo "<a href= 'display.php'> Return to main list </a>"; // Link back to main list of all planets, clearing entered user parameters
    }
    

?>

</body>
</html>