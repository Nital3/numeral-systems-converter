<!DOCTYPE html>

<?php
/* script sending data from first cell of form into C script for processing 
and saving resaults as variable */

if(isset($_POST['Sub'])){ //check if form was submitted
    $output=null;
    $retval=null;
    $value=$_POST['Bin'];
    exec("calculator.exe $value", $output, $retval );
}    
?>






<html>
    <head>
        <title>Numeral system calculator</title>
        <meta Charset="UTF-8">
    </head>
    <body>
    
    <form action="index.php" method="post">
    Bin: <input type="text" name="Bin"><br>
    Oct: <input type="text" name="Oct"><br>
    Dec: <input type="text" name="Dec"><br>
    Hex: <input type="text" name="Hex"><br>
    <input type="submit" name="Sub">
    </form>


    
    <?php
    //printing out resault of C script
    print($output[0]);
    ?>

    </body>
</html>