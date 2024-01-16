<!DOCTYPE html>

<?php
//Turning of warnings on page
error_reporting(0);

/* script sending data from first cell of form into C script for processing 
and saving resaults as variable */

//check if form was submitted
if(isset($_POST['Sub'])){
    $output=null;
    $retval=null;
    $value_bin=$_POST['Bin'];
    $value_oct=$_POST['Oct'];
    $value_dec=$_POST['Dec'];
    $value_hex=$_POST['Hex'];
    
    $signed;
    if($_POST['signed'] == '1') {$signed = '1';}
    else {$signed = '0';}


    //allowing only one of numeral types to be passed at same time
    $bin = false;
    $oct = false;
    $dec = false;
    $hex = false;

    $input_type = 0;
    $value;

    if(!empty($value_bin)) {
        if (!preg_match("#^[0-1]+$#", $value_bin)) {
            echo '<script>alert("Invalid input")</script>';
        }
        else {
            $bin = true;
            exec("calculator.exe $value_bin 1 $signed", $output, $retval);
         }
    }


    if(!empty($value_oct)) {
        if (!preg_match("#^[0-7]+$#", $value_oct)) {
            echo '<script>alert("Invalid input")</script>';
        }
        else {
            $oct = true;
            exec("calculator.exe $value_oct 2 $signed", $output, $retval);
         }
    }

    if(!empty($value_dec)) {
        if (!preg_match("#^[0-9]+$#", $value_dec)) {
            echo '<script>alert("Invalid input")</script>';
        }
        else {
            $dec = true;
            exec("calculator.exe $value_dec 3 $signed", $output, $retval);
         }
    }


    if(!empty($value_hex)) {
        if (!preg_match("#^[A-F0-9]+$#", $value_hex)) {
            echo '<script>alert("Invalid input")</script>';
        }
        else {
            $hex = true;
            exec("calculator.exe $value_hex 4 $signed", $output, $retval);
         }
    }





    if(!empty($value_oct)) {$oct = true; $input_type = 2; $value = $value_oct;}
    if(!empty($value_dec)) {$dec = true; $input_type = 3; $value = $value_dec;}
    if(!empty($value_hex)) {$hex = true; $input_type = 4; $value = $value_hex;}

    

    $value_bin=$output[0];
    $value_oct=$output[1];
    $value_dec=$output[2];
    $value_hex=$output[3];

}?>







<html>
    <head>
        <title>Numeral system calculator</title>
        <meta Charset="UTF-8">
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
    
    <div id="center">
    <center>
        <div id="valign"> 
            <h1>Numeral system converter</h1>

            <form action="index.php" method="post">

            Bin: <input type="text" name="Bin" maxlength="31"
            placeholder=<?php 
            if(empty($value_bin)) {Echo("00000000000000000000000000000000");}
            else {Echo($value_bin);}?>
            <?php if($oct||$dec||$hex) {Echo("Disabled");} ?>><br>
            
            <input type="checkbox" id="signed" name="signed" value="1">
            <label for="signed"> Signed?</label><br><br>

            Oct: <input type="text" name="Oct" max="37777777777" maxlength="10"
            placeholder=<?php
            if(empty($value_oct)) {Echo("00000000000");}
            else {Echo($value_oct);}?>
            <?php if($bin||$dec||$hex) {Echo("Disabled");} ?>><br>

            Dec: <input type="text" name="Dec" maxlength="9"
            placeholder=<?php
            if(empty($value_dec)) {Echo("0000000000");}
            else {Echo($value_dec);}?>
            <?php if($bin||$oct||$hex) {Echo("Disabled");} ?>><br>

            Hex: <input type="text" name="Hex" maxlength="7"
            placeholder=<?php
            if(empty($value_hex)) {Echo("00000000");}
            else {Echo($value_hex);}?>
            <?php if($bin||$oct||$dec) {Echo("Disabled");} ?>><br>

            <?php if(!empty($value_bin)) {echo("Click 2nd time to reset: <br>");} ?>
            <?php if(empty($value_bin)) {echo('</br>');} ?>
            <input type="submit" value="Submit" name="Sub">
            </form> 
        
        </div>
    </center>
    </div>

    </body>
</html>