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


    if(isset($_GET['system']) == FALSE) // Test if any user data is present in URL, output if there is none
    {
        echo "<tr>";
        echo "<th>System Name</th>";
        echo "<th>Binary Type</th>";
        echo "<th>Number of Planets</th>";
        echo "</tr>";
        $sys_names = array_unique(array_column($data_array, 9));
        asort($sys_names);
        $bin_types = array_column($data_array,1);
        foreach($sys_names as $system)
        {
            $count = array_count_values(array_column($data_array, 9))[$system];
            $key = array_search($system, array_column($data_array, 9));
            $binary_type = $bin_types[$key];
            echo "<tr>";
            echo "<td>" . $system . "</td>";
            echo "<td>" . $binary_type . "</td>";
            echo "<td>" . $count . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    }

    if(isset($_GET['system'])) //Output if user parameter data is present in URL
    {
        echo "<tr>";
        echo "<th>System Name</th>";
        echo "<th>Binary Type</th>";
        echo "<th>Number of Planets</th>";
        echo "<th>Distance From Sun (parsecs)</th>";
        echo "<th>Solar Masses</th>";
        echo "<th>Solar Radii</th>";
        echo "<th>Solar Temperature</th>";
        echo "<th>Solar Age (Gyr)</th>";
        echo "</tr>";
        $input = urldecode($_GET['system']);
        $count = array_count_values(array_column($data_array, 9))[$_GET['system']];
        $key = array_search($_GET['system'], array_column($data_array, 9));
        echo "<tr>";
        echo "<td>" . $data_array[$key][9] . "</td>" ;
        echo "<td>" . $data_array[$key][1] . "</td>" ;
        echo "<td>" . $count . "</td>" ;
        echo "<td>" . $data_array[$key][10] . "</td>" ;
        echo "<td>" . $data_array[$key][11] . "</td>" ;
        echo "<td>" . $data_array[$key][12] . "</td>" ;
        echo "<td>" . $data_array[$key][13] . "</td>" ;
        echo "<td>" . $data_array[$key][14] . "</td>" ;
        echo "</tr>";
        

        echo "</table>";

        echo "<a href= 'display.php'> Return to main list </a>"; // Link back to main list of all planets, clearing entered user parameters
    }
    

?>

</body>
</html>